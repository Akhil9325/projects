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

void display(node* head){
node* temp = head;
while (temp != NULL){
    printf("%d ",temp->val);
    temp = temp->next;
}
printf("NULL");
}
node* insert(node* head,int data){
    node* p = (node*)malloc(sizeof(node));
    node* temp = NULL;
    p->val = data;
    p->next = NULL;
    if(head == NULL){
        head = p;
    }
    else{
        temp = head;
        while(temp->next != NULL){
            temp  = temp->next;
        }
        temp->next = p;
    }
    return head;
}



int main(){
int n,m;
scanf("%d %d",&n,&m);
node* head1 = create(n);
node* head2 = create(m);
node* head = NULL;
while(head1!= NULL && head2 != NULL){
    if(head1->val <= head2->val){
        head = insert(head,head1->val);
        head1 = head1->next;
    }
    else{
        head = insert(head,head2->val);
        head2 = head2->next;
    }
}
while(head1 != NULL){
   head =  insert(head,head1->val);
    head1 = head1->next;
}
while(head2 != NULL){
    head = insert(head,head2->val);
    head2 = head2->next;
}
display(head);



}