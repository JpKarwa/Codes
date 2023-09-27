// LEETCODE 437 -> Path Sum III

#include<iostream>
using namespace std;
#define ll long long
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

void helper(Node *root,int target,int &count){
    if(root==NULL) return;
    if(target-(ll)(root->val)==0){
        count++;
    }
    target=target-(ll)(root->val);
    helper(root->left,target,count);
    helper(root->right,target,count);
}

int pathSum(Node *root,int target){
    if(root==NULL) return 0;
    int count=0;
    helper(root,target,count);
    count+=pathSum(root->left,target)+pathSum(root->right,target);
    return count;
}

int main(){
    Node *a=new Node(10);
    Node *b=new Node(5);
    Node *c=new Node(-3);
    Node *d=new Node(3);
    Node *e=new Node(2);
    Node *f=new Node(11);
    Node *g=new Node(3);
    Node *h=new Node(-2);
    Node *i=new Node(1);
    a->left=b;
    a->right=c;
    b->left=d;
    b->right=e;
    c->right=f;
    d->left=g;
    d->right=h;
    e->right=i;
    cout<<pathSum(a,8);
}

/*
int helper(TreeNode *root,long long target){
    if(root==NULL) return 0;
    int count=0;
    if(target-(ll)root->val==0){
        count++;
    }
    target=target-(ll)(root->val);
    return count+helper(root->left,target)+helper(root->right,target);
}
int pathSum(TreeNode* root, int targetSum) {
    if(root==NULL) return 0;
    int count=helper(root,(ll)targetSum);
    // to add the sums of every node path
    count+=pathSum(root->left,targetSum)+pathSum(root->right,targetSum);
    return count;
}
*/