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

node* reverse(node* head){
    node* prev = NULL;
    node* curr = head;
    node* nxtptr;
    while(curr != NULL){
        nxtptr = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxtptr;
    }
    return prev;
}

void display(node* head){
    node* temp = head;
    while(temp != NULL){
        printf("%d ",temp->val);
        temp = temp->next;
    }
}

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    node* head = create(n);
    node* temp = head;
    while(m != 0){
        if(temp->next != NULL){
        temp = temp->next;
        m--;
        }else{
        temp = head;
        m--;
        }
    }
    node* head1;
    head1 = temp;
    display(head1);
    node* temper = head;
    while(temper != head1){
        printf("%d ",temper->val);
        temper = temper->next;
    }


}