// LEETCODE 1038 -> Binary Search tree to greater sum tree

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
// kind of ulta prefix sum
void revInorder(Node* root,int &currSum){
    if(root==NULL) return;
    revInorder(root->right,currSum);
    root->val+=currSum;
    currSum=root->val;
    revInorder(root->left,currSum);
}

Node *GST(Node *root){
    int currSum=0;
    revInorder(root,currSum);
    return root;
}

void inorder(Node* root){
    if(root==NULL) return;
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}

int main(){
    Node *a=new Node(4);
    Node *b=new Node(1);
    Node *c=new Node(6);
    Node *d=new Node(0);
    Node *e=new Node(2);
    Node *f=new Node(5);
    Node *g=new Node(7);
    Node *h=new Node(3);
    Node *i=new Node(8);
    a->left=b;
    a->right=c;
    b->left=d;
    b->right=e;
    c->left=f;
    c->right=g;
    e->right=h;
    g->right=i;
    Node *root=GST(a);
    inorder(root);
}