// LEETCODE 889 -> Construct binary tree from preorder and postorder traversal

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

Node *build(vector<int> &pre,int pl,int ph,vector<int> post,int pol,int poh){
    if(pl>ph || pol>poh) return NULL;   // dono me se ke bhi likh skte h
    // creating root node
    Node *root=new Node(pre[pl]);        
    if(pl==ph || pol==poh) return root;      /// dono me se ek bhi likh skte h
    // start of left sub tree
    int leftStart=pl+1;
    int i=pol;
    while(i<=poh){
        if(post[i]==pre[leftStart]) break;
        i++;
    }
    // nodes in left subtree
    int leftCount=i-pol+1;
    // creating lst and root
    root->left=build(pre,leftStart,pl+leftCount,post,pol,i);
    root->right=build(pre,pl+leftCount+1,ph,post,i+1,poh-1);
    return root;
}

Node *buildTree(vector<int> &preorder,vector<int> &postorder){
    int n=preorder.size();
    Node *root=build(preorder,0,n-1,postorder,0,n-1);
    return root;
}

void preOrder(Node *root){
    if(root==NULL) return;
    cout<<root->val<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(Node *root){
    if(root==NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->val<<" ";
}

int main(){
    vector<int> preorder={1,2,4,5,3,6,7};
    vector<int> postorder={4,5,2,6,7,3,1};
    Node *root=buildTree(preorder,postorder);
    preOrder(root);
    cout<<endl;
    postOrder(root);
}