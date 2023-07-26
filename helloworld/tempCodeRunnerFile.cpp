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
//O(N2) METHOD TO FIND A SUM PAIR IN DLL
void sumpairs(node* &head,int key){
  node* temp = head;
  node* nextptr;
  vector<vector<int>> ans;
  while(temp != NULL){
    node* val1 = temp;
    nextptr = temp->next;
    temp = temp->next;
    while(temp != NULL){
      if(temp->data == (key - val1->data)){
        ans.push_back({val1->data,temp->data});
        break;
      }
      temp = temp->next;
    }
    temp = nextptr;

  }
  int num = ans.size();
  for (int i = 0; i < num; i++)
  {
    cout<<ans[i][0]<<" "<<ans[i][1]<<endl;
  }
  
}
void sumpaireff(node* &head,int key){
  node* first = head;
  node* second = head;
  while(second->next != NULL){
    second = second->next;
  }
  bool found = false;
  while(first != second && second->next != first){
    if((first->data + second->data) == key){
      cout<<first->data<<" "<<second->data<<endl;
    first = first->next;
    second = second->prev;
  }
  else{
    if((first->data + second->data) < key){

      first = first->next;
    }
    else{
      second = second->prev;
    }
  }
}
}
#define n 100

class stack{
  int* arr;
  int top;
  public:
  stack(){
  arr = new int[n];
  top = -1;
}
void push(int x){
  if(top == n-1){
    cout<<"stack overflow"<<endl;
    return;
  }
  top++;
  arr[top] = x;
}
void pop(){
  if(top == -1){
    cout<<"no element to pop"<<endl;
    return;
  }
  top--;
}
int Top(){
  if(top == -1){
    cout<<"no element in stack"<<endl;
    return -1;
  }
  return arr[top];
}
bool empty(){
  return (top == -1);
}
};



int main(){

  stack st;
  st.push(1);
  st.push(2);
  st.push(3);
  st.push(4);
  cout<<st.Top()<<endl;
  


}