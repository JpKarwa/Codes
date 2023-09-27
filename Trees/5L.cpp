// LEETCODE 543 -> Diameter of binary tree

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
    int level=1+max(levels(root->left),levels(root->right));
    return level;
}

void helper(Node *root,int &ans){
    if(root==NULL) return;
    int dia=levels(root->left)+levels(root->right);
    ans=max(ans,dia);
    helper(root->left,ans);
    helper(root->right,ans);
}

int diameterOfBinaryTree(Node *root){
    int maxDia=0;
    helper(root,maxDia);
    return maxDia;
}

// method 2
// int helper(Node *root,int &ans){
//         if(root==NULL) return 0;
//         int l=helper(root->left,ans);
//         int r=helper(root->right,ans);
//         ans=max(ans,l+r);
//         return max(l,r)+1;
//     }
//     int diameterOfBinaryTree(Node* root) {
//         int ans=0;
//         helper(root,ans);   
//         return ans;     
//     }

int main(){
    Node *a=new Node(1);
    Node *b=new Node(2);
    Node *c=new Node(3);
    Node *d=new Node(4);
    Node *e=new Node(5);
    a->left=b;
    a->right=c;
    b->left=d;
    b->right=e;

    cout<<diameterOfBinaryTree(a);
}