// Find the size of tree

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

int sizeOfTree(Node *root){
    if(root==NULL) return 0;
    // sizeoftree= 1+ size of left subtree + size of right substree
    int size=1+sizeOfTree(root->left)+sizeOfTree(root->right);
    return size;
}

int size=0;
void sizeoftree(Node *root){
    if(root==NULL) return;
    size+=1;
    sizeoftree(root->left);
    sizeoftree(root->right);
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
    cout<<sizeOfTree(a)<<endl;
    sizeoftree(a);
    cout<<size;
}