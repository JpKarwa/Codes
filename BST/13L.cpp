// LEETCODE 669 -> Trim a Binary Search Tree

#include<iostream>
#include<climits>
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

void helper(Node *root,int low,int high){
    if(root==NULL) return;
    while(root->left){
        if(root->left->val < low){
            root->left=root->left->right;
        }
        else if(root->left->val > high){
            root->left=root->left->left;
        }
        else break;
    }
    while(root->right){
        if(root->right->val>high){
            root->right=root->right->left;
        }
        else if(root->right->val<low){
            root->right=root->right->right;
        }
        else break;
    }
    helper(root->left,low,high);
    helper(root->right,low,high);
}

Node *trimBST(Node *root,int low,int high){
    // Creating a dummy node (root ko check krne ke liye ki vo low high ke andar h ya nhi)
    Node *dummy=new Node(INT_MAX);
    dummy->left=root;
    helper(dummy,low,high);
    return dummy->left;
}

int main(){
    Node *a=new Node(3);
    Node *b=new Node(0);
    Node *c=new Node(4);
    Node *d=new Node(2);
    Node *e=new Node(1);
    a->left=b;
    a->right=c;
    b->right=d;
    d->left=e;
    inorder(a);
    int low=1;
    int high=3;
    Node *root=trimBST(a,low,high);
    cout<<endl;
    inorder(root);
}