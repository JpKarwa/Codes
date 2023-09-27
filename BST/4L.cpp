// LEETCODE 98 -> Validate BST

#include<bits/stdc++.h>
using namespace std;

#define ll long long 

class Node{
    public:
        int val;
        Node *left;
        Node *right;
        Node(int val){
            this->val=val;
            this->left=NULL;
            this->right=NULL;
        }
};
// finding maximum of tree
ll maxOfTree(Node *root){
    if(root==NULL) return LLONG_MIN;
    ll lst=maxOfTree(root->left);
    ll rst=maxOfTree(root->right);
    ll maxi=max((ll)root->val,max(lst,rst));
    return maxi;
}

// finding minimum of tree
ll minOfTree(Node *root){
    if(root==NULL) return LLONG_MAX;
    ll lstMin=minOfTree(root->left);
    ll rstMin=minOfTree(root->right);
    ll mini=min((ll)root->val,min((ll)lstMin,(ll)rstMin));
    return mini;
}

// binary tree is bst if 
// value of root is greater maxium of its left subtree and less than minimum of its right subtree
// this is to be valid for each node 
bool isValidBST(Node *root){
    if(root==NULL) return true;
    ll maxi=maxOfTree(root->left);
    ll mini=minOfTree(root->right);
    if((ll)root->val <= maxi || (ll)root->val >=mini) return false;
    bool lst=isValidBST(root->left);
    bool rst=isValidBST(root->right);
    return lst && rst;
}

// Method 2
void inorder(Node *root,vector<int> &ans){
    if(root==NULL) return;
    inorder(root->left,ans);
    ans.push_back(root->val);
    inorder(root->right,ans);
}

bool isValidBST1(Node *root){
    vector<int> ans;
    inorder(root,ans);
    // check that inorder is sorted or not
    for(int i=1;i<ans.size();i++){
        if(ans[i]<=ans[i-1]) return false;
    }
    return true;
}

// method 3
void inorder1(Node* root,Node* &prev,bool &flag){
    if(root==NULL) return;
    inorder1(root->left,prev,flag);
    if(prev!=NULL){
        if(root->val<=prev->val){
            flag=0;
            return;
        }
    }
    prev=root;
    inorder1(root->right,prev,flag);
}

bool isValidBST2(Node *root){
    Node *prev=NULL;
    bool flag=true;
    inorder1(root,prev,flag);
    return flag;
}

int main(){
    Node *a=new Node(6);
    Node *b=new Node(2);
    Node *c=new Node(8);
    Node *d=new Node(0);
    Node *e=new Node(4);
    Node *f=new Node(7);
    Node *g=new Node(9);
    Node *h=new Node(3);
    Node *i=new Node(5);
    a->left=b;
    a->right=c;
    b->left=d;
    b->right=e;
    c->left=f;
    c->right=g;
    e->left=h;
    e->right=i;
    cout<<isValidBST(a)<<" "<<isValidBST1(a)<<" "<<isValidBST2(a);
}