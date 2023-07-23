#include<bits/stdc++.h>
using namespace std;
class node{
  public:
  int data;
  node* next;
  node* prev;
  node(int val){
    data = val;
    next = NULL;
    prev = NULL;
  }
};
void insertathead(node* &head,int val){
  node* n = new node(val);
  n->next = head;
  head = n;
}
void insertattail(node* &head,int val){
  if(head == NULL){
    insertathead(head,val);
    return;
  }
  node* n = new node(val);
  node* temp = head;
  while(temp->next != NULL){
    temp = temp->next;
  }
  temp->next = n;
  n->prev = temp;
}
void display(node* head){
  node* temp = head;
  while(temp != NULL){
    cout<<temp->data<<" ";
    temp = temp->next;

  }
  cout<<endl;
}
void deleteathead(node* &head){
  node* todelete = head;
  head = head->next;
  head->prev = NULL;
  delete todelete;


}

void deletion(node* &head,int val){
  if(head->data == val){
    deleteathead(head);
    return;
  }
  node* temp = head;
  while(temp != NULL && temp->data!=val){
    temp = temp->next;
  }
  node* todelete = temp;

  temp->prev->next = temp->next;
  if(temp->next != NULL){
  temp->next->prev = temp->prev;}
delete todelete;
  
}


int main(){
  node* head = NULL;
  insertattail(head,1);
  insertattail(head,2);
  insertattail(head,3);
  insertattail(head,4);
  insertathead(head,5);
  display(head);

}