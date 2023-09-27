// LEETCODE 236 -> LCA Of a Binary tree

// p and q are two nodes

// if left subtree me p or right substree me q nikal jaye aur vicevera the uska root hi hamara lca h

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

bool exist(Node *root,Node *target){
    if(root==NULL) return 0;
    if(root==target) return 1;
    bool lst=exist(root->left,target);
    bool rst=exist(root->right,target);
    return lst||rst;
}

Node *lca(Node *root,Node *p,Node *q){
    if(root==p || root==q) return root;
    // p is left subtree and q exist in right subtree
    else if(exist(root->left,p) && exist(root->right,q)) return root;
    // q is in left subtree and p exist in right subtree
    else if(exist(root->left,q) && exist(root->right,p)) return root;
    // p and q both are in left subtree
    else if(exist(root->left,p) && exist(root->left,q)) return lca(root->left,p,q);
    // p and q both are in right subtree
    else return lca(root->right,p,q);

    // if(exist(root->left,p) && exist(root->left,q)) return lca(root->left,p,q);
    // else if(exist(root->right,p) && exist(root->right,q)) return lca(root->right,p,q);
    // else return root;
}

int main(){
    Node *a=new Node(3);
    Node *b=new Node(5);
    Node *c=new Node(1);
    Node *d=new Node(6);
    Node *e=new Node(2);
    Node *f=new Node(0);
    Node *g=new Node(8);
    Node *h=new Node(7);
    Node *i=new Node(4);
    a->left=b;
    a->right=c;
    b->left=d;
    b->right=e;
    e->left=h;
    e->right=i;
    c->left=f;
    c->right=g;
    Node *p=b;
    Node *q=c;
    cout<<lca(a,p,q)->val;
}