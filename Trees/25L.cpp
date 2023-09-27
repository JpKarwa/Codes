// LEETCODE 112 -> PATH SUM 


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

bool helper(Node *root,int target){
    if(root==NULL) return 0;
    target=target-(root->val);
    if(root->left==NULL && root->right==NULL){
        if(target==0) return true;
        else return false;
    }
    bool lst=helper(root->left,target);
    bool rst=helper(root->right,target);
    return lst||rst;
}
bool pathSum(Node *root,int targetSum){
    return helper(root,targetSum);
}

int main(){
    Node *a=new Node(5);
    Node *b=new Node(4);
    Node *c=new Node(8);
    Node *d=new Node(11);
    Node *e=new Node(13);
    Node *f=new Node(4);
    Node *g=new Node(7);
    Node *h=new Node(2);
    Node *i=new Node(1);
    a->left=b;
    a->right=c;
    b->left=d;
    c->left=e;
    c->right=f;
    d->left=g;
    d->right=h;
    f->right=i;
    cout<<pathSum(a,22);
}