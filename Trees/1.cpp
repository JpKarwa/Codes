// Find the sum of all nodes of tree

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

int sumOfNode(Node *root){
    if(root==NULL) return 0;
    int sum=root->val+sumOfNode(root->left)+sumOfNode(root->right);
    return sum;
}

int sum=0;
void sums(Node *root){
    if(root==NULL) return;
    sum+=root->val;
    sums(root->left);
    sums(root->right);
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
    cout<<sumOfNode(a)<<endl;
    sums(a);
    cout<<sum;
}