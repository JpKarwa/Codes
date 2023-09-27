// LEETCODE 108 -> Convert sorted array to Balanced bst

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

void inorder(Node *root){
    if(root==NULL) return;
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}

Node* helper(vector<int> &arr,int s,int e){
    if(s>e) return NULL;
    // find the mid or root of a tree
    int mid=s+(e-s)/2;
    Node *root=new Node(arr[mid]);
    root->left=helper(arr,s,mid-1);
    root->right=helper(arr,mid+1,e);
    return root;
}

Node* sortedArrayToBST(vector<int> &arr){
    int n=arr.size();
    return helper(arr,0,n-1);
}

int main(){
    vector<int> arr={-10,-3,0,5,9};
    Node *root=sortedArrayToBST(arr);
    inorder(root);
}