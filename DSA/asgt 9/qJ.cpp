#include<stdio.h>
#include<stdlib.h>

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
        }else{
            temp->left = NULL;
            j++;
        }
        if(j<n && arr[j] >0){
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
int height(node* root){
    if(root == NULL){
        return 0;
    }
    int left = height(root->left);
    int right = height(root->right);
    return (left>right?left:right)+1;
}
int diam(node* root){
    if(root == NULL){
        return 0;
    }
    int lefth = height(root->left);
    int righth = height(root->right);
    int currdiam = lefth+righth+1;
    int leftdiam = diam(root->left);
    int rightdiam = diam(root->right);
    int maxi = leftdiam>rightdiam?leftdiam:rightdiam;
    return (currdiam>maxi?currdiam:maxi);
}

int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
    node* root = formtree(n,arr);
    int ans = diam(root);
    printf("%d",ans);

}