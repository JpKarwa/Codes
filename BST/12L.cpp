// LEETCODE 938 -> Range Sum of a BST

#include<iostream>
#include<vector>
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
// Method 1
void inorder(Node *root,int &ans,int low,int high){
    if(root==NULL) return;
    inorder(root->left,ans,low,high);
    if(root->val >=low && root->val<=high) ans+=(root->val);
    inorder(root->right,ans,low,high);
}
int rangeSumBST1(Node *root,int low,int high){
    int ans=0;
    inorder(root,ans,low,high);
    return ans;
}

// Method2
void helper(Node *root,int &ans,int low,int high){
    if(root==NULL) return;
    if(root->val>=low && root->val<=high){ // go left and right
        ans+=root->val;
        helper(root->left,ans,low,high);
        helper(root->right,ans,low,high);
    }
    else if(root->val<low){ // go left
        helper(root->right,ans,low,high);
    }
    else if(root->val>high){
        helper(root->left,ans,low,high);
    }
}
int rangeSumBST2(Node *root,int low,int high){
    int ans=0;
    helper(root,ans,low,high);
    return ans;
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
    int low=7;
    int high=15;
    cout<<rangeSumBST1(a,low,high)<<" "<<rangeSumBST2(a,low,high);
}