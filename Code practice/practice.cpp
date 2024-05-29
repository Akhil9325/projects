#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node(int d)
    {
        data=d;
        next=NULL;
}
};

void display(node* head){
    node* temp = head;
    while(temp->next != NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<temp->data<<endl;
}
void insertnode(node*& head ,int val){
    node* n = new node(val);
    if(head == NULL){
        head = n;
        return;
    }
    node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = n;
}
void deletenode(node*& head,int val){
    if(head == NULL){
        return;
    }
    if(head->data == val){
        node* todelete = head;
        head = head->next;
        delete todelete;
        return;
    }
    node* temp = head;
    while(temp->next->data != val){
        temp = temp->next;
    }
    node* todelete = temp->next;
    temp->next = temp->next->next;
    delete todelete;
}

int main(){
    node* head=new node(10);
    insertnode(head,20);
    insertnode(head,56);
    insertnode(head,40);
    insertnode(head,50);
    display(head);
    deletenode(head,56);
    display(head);
    deletenode(head,10);
    display(head);

}