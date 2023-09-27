// LEETCODE 101 -> Symmetric tree

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

bool isSameTree(Node *p,Node *q){
    if(p==NULL && q==NULL) return true;
    if(p==NULL || q==NULL) return false;
    if(p->val!=q->val) return false;
    bool lst=isSameTree(p->left,q->right);
    if(lst==0) return false;
    bool rst=isSameTree(p->right,q->left);
    if(rst==0) return false;
    return true;
}

bool isSymmetric(Node *root){
    bool flag=isSameTree(root->left,root->right);
    return flag;
}

int main(){
    Node *a=new Node(1);
    Node *b=new Node(2);
    Node *c=new Node(2);
    Node *d=new Node(3);
    Node *e=new Node(4);
    Node *f=new Node(4);
    Node *g=new Node(3);
    a->left=b;
    a->right=c;
    b->left=d;
    b->right=e;
    c->left=f;
    c->right=g;

    cout<<isSymmetric(a);
}