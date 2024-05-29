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

int search(int ino[],int s,int e,int curr){
    for(int i = s;i<e;i++){
        if(ino[i] == curr){
            return i;
        }
    }
    return -1;
}
node* formtree(int pre[],int ino[],int s,int e){
    static int idx  = 0;
    if(s > e){
        return NULL;
    }
    int curr = pre[idx];
    idx++;
    node* root = (node*)malloc(sizeof(node));
    root->val = curr;
    if(s == e){
        return root;
    }
    int pos = search(ino,s,e,curr);
    root->left = formtree(pre,ino,s,pos-1);
    root->right = formtree(pre,ino,pos+1,e);
    return root;
}
node* builder(int arr[],int s,int e,int* i){
    if(s > e){
        return NULL;
    }
    node* root = (node*)malloc(sizeof(node));
    root->val = arr[*i];
    int m = s;
    for(int j = (e-1);j>=s;j--){
        if(arr[j] < arr[*i]){
            m = j+1;
            break;
        }
    }
    *i = *i-1;
    root->right = builder(arr,m,e-1,i);
    root->left = builder(arr,s,m-1,i);
    return root;
}
int main(){
    int n;
    scanf("%d",&n);
    int pre[n];
    int ino[n];
    for(int i = 0;i<n;i++){
        scanf("%d",&pre[i]);
    }
    int i = n-1;
    node* root = builder(pre,0,n-1,&i);
    listnode* head = (listnode*)malloc(sizeof(listnode));
    head->valu = root;
    head->next = NULL;
    listnode* last = head;
    int x = 0;
    while(x<n){
        node* temp = head->valu;
        if(temp == NULL){
            printf("-1 ");
        }
        else{
            printf("%d ",temp->val);
            x++;
            last->next = (listnode*)malloc(sizeof(listnode));
            last->next->valu = temp->left;
            last = last->next;
            last->next = (listnode*)malloc(sizeof(listnode));
            last->next->valu = temp->right;
            last = last->next;
            last->next = NULL;

        }
        head = head->next;
    }




}