// Print the element of nth level

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

void nthLevel(Node *root,int level,int currLevel){
    if(root==NULL) return;
    if(currLevel==level) cout<<root->val<<" ";
    nthLevel(root->left,level,currLevel+1);
    nthLevel(root->right,level,currLevel+1);
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
    int level=2;
    int cnt=1;
    nthLevel(a,level,cnt);
}