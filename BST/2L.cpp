// LEETCODE 701 -> Insert into BST

#include<iostream>
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

void preorder(Node *root){
    if(root==NULL) return;
    cout<<root->val<<" ";
    preorder(root->left);
    preorder(root->right);
}

void insert(Node *root,int val){
    if(root->val > val){  // go left
        if(root->left==NULL){
            root->left=new Node(val);
        }
        else insert(root->right,val);
    }
    else{    // go right
        if(root->right==NULL){
            root->right=new Node(val);
        }
        else insert(root->right,val);
    }
}

Node *insertIntoBST(Node *root,int val){
    if(root==NULL) return new Node(val);
    insert(root,val);
    return root;
}

int main(){
    Node *a=new Node(4);
    Node *b=new Node(2);
    Node *c=new Node(7);
    Node *d=new Node(1);
    Node *e=new Node(3);
    a->left=b;
    a->right=c;
    b->left=d;
    b->right=e;
    Node *root=insertIntoBST(a,5);
    preorder(root);
}

/*
TreeNode* insertIntoBST(TreeNode* root, int val) {
    if(root==NULL) root=new TreeNode(val);
    else if(val < root->val) root->left=insertIntoBST(root->left,val);
    else root->right=insertIntoBST(root->right,val);
    return root;
}
    */