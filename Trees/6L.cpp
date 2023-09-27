// LEETCODE 100 -> Same Tree

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

bool isSameTree(Node *t1,Node *t2){
    if(t1==NULL && t2==NULL) return true;
    if(t1==NULL || t2==NULL) return false;
    if(t1->val != t2->val) return false;
    bool lst=isSameTree(t1->left,t2->left);
    if(lst==0) return false;
    bool rst=isSameTree(t1->right,t2->right);
    if(rst==0) return false;
    return true;
}

int main(){
    Node *a=new Node(1);
    Node *b=new Node(2);
    Node *c=new Node(3);
    a->left=b;
    a->right=c;

    Node *A=new Node(1);
    Node *B=new Node(2);
    Node *C=new Node(3);
    A->left=B;
    A->right=C;

    cout<<isSameTree(a,A);
}