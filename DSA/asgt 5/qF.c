#include<stdio.h>
#include<stdlib.h>


typedef struct node{
    int val;
    struct node* next;
}node;

node* create(int n){
    node* head = NULL;
    node* temp = NULL;
    node* p = NULL;
    for(int i = 0;i<n;i++){
        p = (node*)malloc(sizeof(node));
        scanf("%d",&(p->val));
        p->next = NULL;
        if(head == NULL){
            head = p;
        }
        else{
            temp = head;
            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->next = p;
        }
    }
    return head;
}

int main(){
    int n;
    scanf("%d",&n);
    node* head = create(n);
    node* temp = head;
    int data = 0;
    while(temp != NULL){
        data = temp->val;
        printf("%d ",data);
          temp = temp->next;
        while(temp != NULL && temp->val == data){
            temp = temp->next;
        }
    }
}