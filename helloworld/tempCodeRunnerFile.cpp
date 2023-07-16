#include<bits/stdc++.h>
using namespace std;

class node{
  public:
  int data;
  node* next;

  node(int val){
    data = val;
    next = NULL;
  }
};
void insertathead(node* &head,int val){
  node* n = new node(val);
  n->next = head;
  head = n;
}
void insertattail(node* &head,int val){
  node* n = new node(val);
  node* temp = head;
  if(head == NULL){
    head = n;
    return ;
  }
  while(temp->next != NULL){
    temp = temp->next;
  }
  temp->next = n;

}
void display(node* head){
  node* temp = head;
  while(temp != NULL){
    cout<<temp->data<<"->";
    temp = temp->next;
  }
  cout<<"NULL"<<endl;}

void deleteathead(node* &head){
  node* todelete = head;
  head = head->next;
  delete todelete;
}

void deletion(node* &head,int val){
  if(head == NULL){
    return;
  }
  if(head->next == NULL){
    deleteathead(head);
  }
    node* temp = head;
    while(temp->next->data != val){
      temp = temp->next;
    }
    node* todelete = temp->next;
    temp->next = temp->next->next;

    delete todelete;
  }
node* reverse(node* &head){
  node* prev = NULL;
  node* curr = head;
  node* next;
  while(curr != NULL){
    next = curr->next;
    curr->next = prev;

    prev = curr;
    curr = next;
  }
  return prev;

}
node* reverserecursive(node* &head){
  if(head == NULL || head->next == NULL){
    return head;
  }
  node* newhead = reverserecursive(head->next);
  head->next->next = head;
  head->next = NULL;

  return newhead;
}
int main(){

  node* head = NULL;
  int n;
  cin>>n;
  int arr[n];
  for (int i = 0; i < n; i++)
  {
    cin>>arr[i];
  }
  for (int i = 0; i < n; i++)
  {
    insertattail(head,arr[i]);
  }
  display(head);
  deletion(head,4);
  display(head);
  node* newhead = reverse(head);
  display(newhead);
  display(reverserecursive(newhead));

}