// Find the min value of binary tree

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

int minOfNode(Node *root){
    if(root==NULL) return INT16_MAX;
    int lst=minOfNode(root->left);
    int rst=minOfNode(root->right);
    int mini=min(root->val,min(lst,rst));
    return mini;
}

int main(){
    Node *a=new Node(1);
    Node *b=new Node(2);
    Node *c=new Node(3);
    Node *d=new Node(-1);
    Node *e=new Node(5);
    Node *f=new Node(6);
    Node *g=new Node(7);
    a->left=b;
    a->right=c;
    b->left=d;
    b->right=e;
    c->left=f;
    c->right=g;
    cout<<minOfNode(a)<<endl;
}