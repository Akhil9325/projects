#include<stdio.h>
#include<stdlib.h>
#include<math.h>


typedef struct node{
    int val;
    struct node* left;
    struct node* right;
}node;

typedef struct listnode{
    node* valu;
    struct listnode* next;
}listnode;

node* formtree(int n,int arr[]){
    int j = 0;
    node* root = (node*)malloc(sizeof(node));
    root->val = arr[0];
    listnode* head = (listnode*)malloc(sizeof(listnode));
    head->valu = root;
    head->next = NULL;
    listnode* last = head;
    while(head != NULL){
        node* temp = head->valu;
        j++;
        if(j<n && arr[j]>0){
            temp->left = (node*)malloc(sizeof(node));
            temp->left->val = arr[j];
            last->next = (listnode*)malloc(sizeof(listnode));
            last->next->valu = temp->left;
            last = last->next;
            last->next = NULL;
        }
        else{
            temp->left = NULL;
            ++j;
        }
        if(j<n && arr[j] > 0){
            temp->right = (node*)malloc(sizeof(node));
            temp->right->val = arr[j];
            last->next = (listnode*)malloc(sizeof(listnode));

            last->next->valu = temp->right;
            last = last->next;
            last->next = NULL;
        }else{
            temp->right = NULL;
            head = head->next;
        }
    }
    return root;
}
int height(node* root,int n){
    if(root == NULL){
        return 0;
    }
    if(root->val == n){
        return 0;
    }
    int left = height(root->left,n);
    int right = height(root->right,n);
    int max;
    if(left > right){
        max = left;
    }else{
        max = right;
    }
    return max + 1;
}
int subtree(node* roo1,node* roo2){
    if(roo1 == NULL && roo2 == NULL){
        return 1;
    }
    else if(roo1 != NULL && roo2 == NULL){
        return 0;
    }
    else if(roo1 == NULL && roo2 != NULL){
        return 0;
    }
    else if(roo1->val == roo2->val && subtree(roo1->left,roo2->left)&&subtree(roo1->right,roo2->right)){
        return 1;
    }
    else{
        return 0;
    }
}
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    int arr[n];
    for(int i = 0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int array[m];
    for(int i = 0;i<m;i++){
        scanf("%d",&array[i]);
    }
    node* roo1 = formtree(n,arr);
    node* roo2 = formtree(m,array);
    int ans = subtree(roo1,roo2);
    if(ans == 1){
        printf("win");
    }
}