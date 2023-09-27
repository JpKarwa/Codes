// LEETCODE 235 -> LCA of BST

/*
bool exist(TreeNode *root,TreeNode *target){
    if(root==NULL) return 0;
    if(root==target) return 1;
    bool lst=exist(root->left,target);
    bool rst=exist(root->right,target);
    return lst||rst;
}

TreeNode *lca(TreeNode *root,TreeNode *p,TreeNode *q){
    if(root==p || root==q) return root;
    // p is left subtree and q exist in right subtree
    else if(exist(root->left,p) && exist(root->right,q)) return root;
    // q is in left subtree and p exist in right subtree
    else if(exist(root->left,q) && exist(root->right,p)) return root;
    // p and q both are in left subtree
    else if(exist(root->left,p) && exist(root->left,q)) return lca(root->left,p,q);
    // p and q both are in right subtree
    else return lca(root->right,p,q);
}
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    // if(exists(root->left,p) && exists(root->left,q)) return lowestCommonAncestor(root->left,p,q);
    // else if(exists(root->right,p) && exists(root->right,q)) return lowestCommonAncestor(root->right,p,q);
    // else return root;
    return lca(root,p,q);
}
*/

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


Node *LCA(Node *root,Node *p,Node *q){
    if(root==p || root==q) return root;
    else if(root->val > p->val && root->val < q->val) return root;
    else if(root->val < p->val && root->val > q->val) return root;
    else if(root->val > p->val && root->val > q->val) return LCA(root->left,p,q);
    else return LCA(root->right,p,q);
    /*
    if(root->val > p->val && root->val > q->val) return LCA(root->left,p,q);
    else if(root->val < p->val && root->val < q->val) return LCA(root->right,p,q);
    else return root;
    */
}

int main(){
    Node *a=new Node(6);
    Node *b=new Node(2);
    Node *c=new Node(8);
    Node *d=new Node(0);
    Node *e=new Node(4);
    Node *f=new Node(7);
    Node *g=new Node(9);
    Node *h=new Node(3);
    Node *i=new Node(5);
    a->left=b;
    a->right=c;
    b->left=d;
    b->right=e;
    c->left=f;
    c->right=g;
    e->left=h;
    e->right=i;
    Node* ans=LCA(a,d,g);
    cout<<ans->val;
}