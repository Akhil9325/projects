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
    int k = 1;
    for(int i = 0;i<n;i++){
        p = (node*)malloc(sizeof(node));
        p->val = k++;
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
    node* temper = head;
    while(temper->next != NULL){
        temper = temper->next;
    }
    temper->next = head;

    return head;
}
node* delhead(node* head){
    head = head->next;
    return head;
}
void deleter(node* head,int data){
    node* temp = head;
    if(head->val == data){
        head = delhead(head);
    }
    while(temp->next->val != data){
        temp = temp->next;
    }
    temp->next = temp->next->next;
}

int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    node* head = create(n);
    node* temp = head;
    while(temp != temp->next){
        int count = 1;
        while(count != k){
            temp = temp->next;
            count++;
        }
        node* conti = temp->next;
        deleter(head,temp->val);
        temp = conti;
    }
    printf("%d",temp->val);


}