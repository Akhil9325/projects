#include<bits/stdc++.h>
using namespace std;

 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
class Solution {
public:
TreeNode* ancs(TreeNode* root,int st,int dest){
    if(root == NULL){
        return NULL;
    }
    if(root->val == st or root->val == dest){
        return root;
    }
    TreeNode* left = ancs(root->left,st,dest);
    TreeNode* right = ancs(root->right,st,dest);
    if(left == NULL and right == NULL){
        return NULL;
    }
    if(left != NULL and right != NULL){
        return root;
    }
    if(left != NULL){
        return left;
    }
    else{
        return right;
    }
}
void dist(TreeNode* root,int st,string d,string& s){
    if(root == NULL){
        return;
    }
    if(st == root->val){
        s.append(d);
        return;
    }
    d.push_back('U');
    dist(root->left,st,d,s);
    dist(root->right,st,d,s);
}

void dista(TreeNode* root,int st,string da,string& s){
    if(root == NULL){
        return ;
    }
    if(st == root->val){
        s.append(da);
        return;
    }
    da.push_back('L');
    dista(root->left,st,da,s);
    da.pop_back();
    da.push_back('R');
    dista(root->right,st,da,s);
}
    string getDirections(TreeNode* root, int st, int dest) {
        root = ancs(root,st,dest);
        string s;
        dist(root,st,"",s);
        dista(root,dest,"",s);
        return s;
    }
};

int main(){
    
}