#include<stdio.h>
#include<stdlib.h>
#include<math.h>


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
    node* nxt;
    while(curr != NULL){
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }
    return prev;
}

node* insert(node* head,int data){
    node* temp = head;
    node* p = (node*)malloc(sizeof(node));
    p->val = data;
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
    return head;
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
    node* h1 = create(n);
    node* h2 = create(m);
    h1 = reverse(h1);
    h2 = reverse(h2);
    long int sum1 = 0;
    int i = 0;
    int x = n;
    while(x != 0){
        sum1 += (h1->val)*pow(10,x-1);
        h1 = h1->next;
        x--;
    }
     x = m;
    long int sum2 = 0;
    while(x != 0){
        sum2 += (h2->val)*pow(10,x-1);
        h2 = h2->next;
        x--;
    }
    long long int ans = sum1+sum2;
    node* answ = NULL;
    while(ans != 0){
        int rem = ans%10;
        ans = ans/10;
        answ = insert(answ,rem);
    }
    display(answ);




}