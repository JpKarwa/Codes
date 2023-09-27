// Given a BST and two keys in it. Find the distance between two nodes with given two keys. It may 
// be assumed that both keys exist in BST

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

int distance(Node *root,int x){
    if(root==NULL) return 0;
    else if(root->val==x) return 0;
    else if(root->val>=x) return 1+distance(root->left,x);
    else return 1+distance(root->right,x);
}

int findDistance(Node *root,int start,int end){
    if(root==NULL) return 0;
    else if(root->val > start && root->val > end) return findDistance(root->left,start,end);
    else if(root->val < start && root->val < end) return findDistance(root->right,start,end);
    else return distance(root,start)+distance(root,end);
}

int main(){
    Node *a=new Node(10);
    Node *b=new Node(5);
    Node *c=new Node(15);
    Node *d=new Node(3);
    Node *e=new Node(7);
    Node *f=new Node(18);
    a->left=b;
    a->right=c;
    b->left=d;
    b->right=e;
    c->right=f;
    int low=3;
    int high=10;
    cout<<findDistance(a,low,high);
}