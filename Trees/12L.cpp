// LEETCODE 110 -> Balanced Binary Tree

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
    int lst=levels(root->left);
    int rst=levels(root->right);
    int level=1+max(lst,rst);
    return level;
}

bool isBalanced(Node *root){
    if(root==NULL) return true;
    int lstLevels=levels(root->left);
    int rstLevels=levels(root->right);
    int diff=abs(lstLevels-rstLevels);
    if(diff>1) return false;
    bool lst=isBalanced(root->left);
    if(lst==0) return false;
    bool rst=isBalanced(root->right);
    if(rst==0) return false;
    return true;    
}

int main(){
    Node *a=new Node(3);
    Node *b=new Node(9);
    Node *c=new Node(20);
    Node *d=new Node(15);
    Node *e=new Node(7);
    a->left=b;
    a->right=c;
    c->left=d;
    c->right=e;
    cout<<isBalanced(a);
}