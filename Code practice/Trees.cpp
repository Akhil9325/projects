#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node* left;
    node* right;
    public:
    node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};
void preorder(struct node* root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
    }
void postorder(struct node* root){
    if(root == NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";

}
void inorder(struct node* root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
int search(int inorder[],int start,int end,int curr){
    for (int i = start; i <= end; i++)
    {
        if(inorder[i] == curr){
            return i;
        }

    }
    return -1;
}
node* buildtreepre(int preorder[],int inorder[],int start,int end){
     static int idx = 0;
    if(start > end){
        return NULL;
    }
    int curr = preorder[idx];
    idx++;
    node* head = new node(curr);
    if(start == end){
        return head;
    }
    int pos = search(inorder,start,end,curr);
    head->left = buildtreepre(preorder,inorder,start,pos-1);
    head->right = buildtreepre(preorder,inorder,pos+1,end);

    return head;
}
node* buildtreepost(int postorder[],int inorder[],int start,int end){
    static int idx = end;
    if(start > end){
        return NULL;
    }
    int val = postorder[idx];
    idx--;
    node* curr = new node(val);
    if(start == end){
        return curr;
    }
    int pos = search(inorder,start,end,val);
    curr->right = buildtreepost(postorder,inorder,pos+1,end);
    curr->left = buildtreepost(postorder,inorder,start,pos-1);
    return curr;
}
void inorderprint(node* root){
    if(root == NULL){
        return;
    }
    inorderprint(root->left);
    cout<<root->data<<" ";
    inorderprint(root->right);
}
void levelordertraversal(struct node* root){
    if(root == NULL){
        return;
    }
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node* temp = q.front();
        q.pop();
        if(temp != NULL){
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
        else if(!q.empty()){
            q.push(NULL);
        }
    }
}
int sumatK(node* root,int k){
   if(root == NULL){
    return -1;
   }
   queue<node*> q;
   q.push(root);
   q.push(NULL);
   int level = 0;
   int sum = 0;
   while(!q.empty()){
      node* temp = q.front();
      q.pop();
      if(temp != NULL){
        if(level == k){
            sum += temp->data;
        }
        if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }
      }
      else if(!q.empty()){
        q.push(NULL);
        level++;
      }
   }
   return sum;
}
int count(node* root){
    if(root == NULL){
        return 0;
    }
    return count(root->left) + count(root->right) + 1;
}
int sumall(node* root){
    if(root == NULL){
        return 0;
    }
    return sumall(root->left) + sumall(root->right) + root->data;
}
int height(node* root){
    if(root == NULL){
        return 0;
    }
    int leftheight = height(root->left);
    int rightheight = height(root->right);
    return (max(leftheight,rightheight) + 1);
}
//height queue method
int heighter(node* root){
     if(root == NULL){
        return 0;
    }
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    int level = 1;
    while(!q.empty()){
        node* temp = q.front();
        q.pop();
        if(temp != NULL){
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
        else if(!q.empty()){
            q.push(NULL);
            level++;
        }
    }
    return level;
}

int calcdiameter(node* root){
    if(root == NULL){
        return 0;
    }
    int leftheight = height(root->left);
    int rightheight = height(root->right);
    int currdiameter = leftheight + rightheight + 1;
    int leftdiameter = calcdiameter(root->left);
    int rightdiamter = calcdiameter(root->right);
    return (max(currdiameter,max(leftdiameter,rightdiamter)));
}
//calculate diameter optimised
int calcdiam(node* root,int* height){
    if(root == NULL){
        *height = 0;
        return 0;
    }
int lh = 0,rh = 0;
int leftdiam = calcdiam(root->left,&lh);
int rightdiam = calcdiam(root->right,&rh);
int currdiam = lh + rh + 1;
*height = max(lh,rh) + 1;
return max(currdiam,max(leftdiam,rightdiam));
}
void sumreplace(node* root){
    if(root == NULL){
        return;
    }
    sumreplace(root->left);
    sumreplace(root->right);
    if(root->left != NULL){
        root->data += root->left->data;
    }
    if(root->right != NULL){
        root->data += root->right->data;
    }

}
bool balancechecker(node* root){
    if(root == NULL){
        return true;
    }
    if(balancechecker(root->left) == false){
        return false;
    }
    if(balancechecker(root->right) == false){
        return false;
    }
    int lh = height(root->left);
    int rh = height(root->right);
    if(abs(lh - rh) <= 1){
        return true;
    }
    else{
        return false;
    }
}
//balance checker optimised
bool balancecheckered(node* root,int* height){
    if(root == NULL){
        return true;
    }
    int lh = 0,rh = 0;
    if(balancecheckered(root->left,&lh) == false){
        return false;
    }
    if(balancecheckered(root->right,&rh) == false){
        return false;
    }
    *height = max(lh,rh) + 1;
    if(abs(lh - rh) <= 1){
        return true;
    }
    else{
        return false;
    }


}
node* LCA(node* root,int n1,int n2){
    if(root == NULL){
        return NULL;
    }
    if(root->data == n1 or root->data == n2){
        return root;
    }
    node* left = LCA(root->left,n1,n2);
    node* right = LCA(root->right,n1,n2);
    if(left != NULL and right != NULL){
        return root;
    }
    if(left == NULL and right == NULL){
        return NULL;
    }
    if(left != NULL){
        return LCA(root->left,n1,n2);
    }
    return LCA(root->right,n1,n2);
}
int findist(node* root,int n,int dist){
  if(root == NULL){
    return -1;
  }
  if(root->data == n){
    return dist;
  }
  int left = findist(root->left,n,dist + 1);
  if(left != -1){
     return left;
  }
  return findist(root->right,n,dist+1);
}
int distBwnodes(node* root,int n1,int n2){
    node* lca = LCA(root,n1,n2);
    int d1 = findist(lca,n1,0);
    int d2 = findist(lca,n2,0);
    return (d1 + d2);
}
void subtreenodes(node* root,int k){
    if(root == NULL or k < 0){
        return ;
    }
    if(k == 0){
        cout<<root->data<<" ";
        return;
    }
    subtreenodes(root->left,k-1);
    subtreenodes(root->right,k-1);
}
int printnodesatk(node* root,node* target,int k){
    if(root == NULL){
        return -1;
    }
    if(root == target){
        subtreenodes(root,k);
        return 0;
    }
    int dl = printnodesatk(root->left,target,k);
    if(dl != -1){
        if(dl+1 == k){
            cout<<root->data<<" ";
        }else{
            subtreenodes(root->right,k-dl-2);
        }
        return dl+1;
    }
    int dr = printnodesatk(root->right,target,k);
    if(dr != -1){
        if(dr+1 == k){
            cout<<root->data<<" ";
        }else{
            subtreenodes(root->left,k-dr-2);
        }
        return dr+1;
    }
    return -1;
}

int main(){
    int postorder[] = {4,2,5,3,1};
    int inorder[] = {4,2,1,5,3};
struct node* root = new node(1);
root->left = new node(2);
root->right = new node(3);
root->left->left = new node(4);
root->left->right = new node(5);
root->right->left = new node(6);
root->right->right = new node(7);
struct node* root2 = new node(1);
root2->left = new node(4);
root2->right = new node(3);
root2->right->left = new node(6);
root2->right->right = new node(7);
root2->right->left->left = new node(8);
printnodesatk(root,root->left,1);
}