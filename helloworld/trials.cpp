#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node* left;
    node* right;
    node(int val){
        data = val;
        left = right = NULL;
    }
};
node* buildtreepre(int preorder[],int inorder[],int start,int end){
    static int idx = 0;
    if(start > end){
        return NULL;
    }
    int curr = preorder[idx++];
    node* root = new node(curr);
    
}
int main(){

}