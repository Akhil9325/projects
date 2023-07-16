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
void insertattail(node* &head,int val){
     node* n = new node(val);
     node* temp = head;
     if(head == NULL){
        head = n;
        return;
     }

     while(temp->next != NULL){
        temp = temp->next;
     }  
     temp->next = n;

}
void insertathead(node* &head,int val){
    node* n = new node(val);
    n->next = head;
    head = n;
}
void deleteathead(node* &head){
        node* todelete = head;
        head = head->next;

        delete todelete;
}

void deletion(node* &head,int val){
    if(head == NULL){
        return;
    }
    if(head->data == val || head->next == NULL){
        deleteathead(head);
        return ;
    }

    node* temp = head;
    while(temp->next->data != val && temp->next != NULL){
        temp = temp->next;
    }
    node* todelete = temp->next;
    temp->next = temp->next->next;

    delete todelete;
}

node* reversion(node* &head){
    node* prev = NULL;
    node* curr = head;
    node* nexptr;
    while(curr != NULL){
        nexptr = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nexptr;
    }
    return prev;
}

node* reversionrecursive(node* &head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    node* newhead = reversionrecursive(head->next);
    head->next->next = head;
    head->next = NULL;

    return newhead;
}
void display(node* head){
    node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}
node* reversionK(node* &head,int k){
    node* prev = NULL;
    node* curr = head;
    node* nextptr;
    int count = 0;
    while(curr != NULL && count < k){
        nextptr = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextptr;
        count++;
    }

    if(nextptr != NULL){
        head->next = reversionK(nextptr,k);
    }

    return prev;
}


int main(){
node* head = NULL;
insertattail(head,1);
insertattail(head,2);
insertattail(head,3);
insertattail(head,4);
insertattail(head,5);
insertattail(head,6);
display(head);
node* newhead = reversionK(head,2);
display(newhead);
}