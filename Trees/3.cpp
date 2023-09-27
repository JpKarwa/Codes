// Find the max tree node

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

int maxOfTree(Node *root){
    if(root==NULL) return INT16_MIN;
    // sizeoftree= 1+ size of left subtree + size of right substree
    int leftMax=maxOfTree(root->left);
    int rightMax=maxOfTree(root->right);
    int maxi=max(root->val,max(leftMax,rightMax));
    return maxi;
}

int maxi=0;
void maxoftree(Node *root){
    if(root==NULL) return;
    maxi=max(maxi,root->val);
    maxoftree(root->left);
    maxoftree(root->right);
}

int main(){
    Node *a=new Node(1);
    Node *b=new Node(2);
    Node *c=new Node(3);
    Node *d=new Node(4);
    Node *e=new Node(5);
    Node *f=new Node(6);
    Node *g=new Node(7);
    a->left=b;
    a->right=c;
    b->left=d;
    b->right=e;
    c->left=f;
    c->right=g;
    cout<<maxOfTree(a)<<endl;
    maxoftree(a);
    cout<<maxi;
}