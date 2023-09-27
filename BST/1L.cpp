// LEETCODE 700 -> Search in a BST

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

Node *searchBst(Node *root,int val){
    if(root==NULL || root->val==val) return root;
    // go left
    else if(root->val > val) return searchBst(root->left,val);
    // go right
    else return searchBst(root->right,val); 
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
    Node *ans=searchBst(a,2); 
    cout<<ans->val;
}