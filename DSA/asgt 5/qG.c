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
int main(){
    int n,a,b;
    scanf("%d %d %d",&n,&a,&b);
    node* head = create(n);
    int count = 1;
    node* d = head;
    while(count != a){
        d = d->next;
        count++;
    }
    count = 1;
    node* j = head;
    while(count != b){
        j = j->next;
        count++;
    }
    while(j != d){
        j = j->next;
        d = d->next->next;
    }
    printf("%d",j->val);




}