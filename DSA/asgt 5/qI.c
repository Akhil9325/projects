#include<stdio.h>
#include<stdlib.h>


typedef struct node{
    char val;
    struct node* next;
}node;

node* create(int n,char str[]){
    node* head = NULL;
    node* temp = NULL;
    node* p = NULL;
    for(int i = 0;i<n;i++){
        p = (node*)malloc(sizeof(node));
        p->val = str[i];
        p->next = NULL;
        if(head == NULL){
            head = p;
        }else{
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
    while(temp != NULL){
        printf("%c ",temp->val);
        temp = temp->next;
    }
}

node* reverse(node* head){
    node* prev = NULL;
    node* curr = head;
    node* nxt;
    while(curr != NULL){
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }
    return prev;
}


int main(){
    int n;
    scanf("%d",&n);
    char str[n+1];
    scanf("%s",str);
    node* head = create(n,str);
    node* head1 = reverse(head);
    int x = 0;
    while(head1 != NULL){
        if(str[x] == head1->val){
            x++;
            head1 = head1->next;
        }
        else{
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");
}