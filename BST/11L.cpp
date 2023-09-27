// LEETCODE 1382 -> Balance a binary search tree

#include<iostream>
#include<vector>
using namespace std;

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

void inorder(Node *root,vector<int> &ans){
    if(root==NULL) return;
    inorder(root->left,ans);
    ans.push_back(root->val);
    inorder(root->right,ans);
}
//copy paste of leetcode 108
Node *build(vector<int> &in,int s,int e){
    if(s>e) return NULL;
    int mid=s+(e-s)/2;
    Node *root=new Node(in[mid]);
    root->left=build(in,s,mid-1);
    root->right=build(in,mid+1,e);
    return root;
}

Node *constructBalanceBST(Node *root){
    vector<int> ans;
    inorder(root,ans);
    int n=ans.size();
    return build(ans,0,n-1);
}

void preorder(Node *root){
    if(root==NULL) return;
    cout<<root->val;
    preorder(root->left);
    preorder(root->right);
}

int main(){
    Node *a=new Node(1);
    Node *b=new Node(2);
    Node *c=new Node(3);
    Node *d=new Node(4);
    a->right=b;
    b->right=c;
    c->right=d;
    Node *root=constructBalanceBST(a);
    preorder(root);
}