// Find the height of tree

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

int levels(Node *root){
    if(root==NULL) return 0;
    int leftLevels=levels(root->left);
    int rightLevels=levels(root->right);
    int level=1+max(leftLevels,rightLevels);
    return level;
}

int main(){
    Node *a=new Node(1);
    Node *b=new Node(2);
    Node *c=new Node(3);
    Node *d=new Node(4);
    Node *e=new Node(5);
    Node *f=new Node(6);
    Node *g=new Node(7);
    Node *h=new Node(0);
    a->left=b;
    a->right=c;
    b->left=d;
    b->right=e;
    c->left=f;
    c->right=g;
    g->right=h;
    cout<<levels(a)<<" ";
    int height=levels(a)-1;
    cout<<height;
}