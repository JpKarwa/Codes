// LEETCODE 230 -> kth smallest element in BST

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

void inorder1(Node *root,vector<int> &ans){
    if(root==NULL) return;
    inorder1(root->left,ans);
    ans.push_back(root->val);
    inorder1(root->right,ans);
}

int kthSmallest1(Node *root,int k){
    vector<int> ans;
    inorder1(root,ans);
    return ans[k-1];
}

void inorder2(Node *root,int &ans,int &k){
    if(root==NULL) return;
    inorder2(root->left,ans,k);
    k=k-1;
    if(k==0){
        ans=root->val;
        return;
    }
    inorder2(root->right,ans,k);
}

int kthSmallest2(Node *root,int k){
    int ans=0;
    inorder2(root,ans,k);
    return ans;
}
int main(){
    Node *a=new Node(3);
    Node *b=new Node(1);
    Node *c=new Node(4);
    Node *d=new Node(2);
    a->left=b;
    a->right=c;
    b->right=d;
    cout<<kthSmallest1(a,2)<<" "<<kthSmallest2(a,2);
}