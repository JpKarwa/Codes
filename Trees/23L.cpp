// LEETCODE 105 -> Construct tree from preorder and inorder.

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

/*
il -> inlow(start of inorder of tree)
ih -> inhigh(end of inorder of tree)
pl -> prelow(start of preorder of tree)
ph -> prehigh(end of preorder of tree)
*/

Node* build(vector<int> pre,int pl,int ph,vector<int> in,int il,int ih){
    if(pl>ph) return NULL;
    Node *root=new Node(pre[pl]);
    if(pl==ph) return root;
    int i=il;
    while(i<=ih){
        if(in[i]==pre[pl]) break;
        i++;
    }
    int leftCount=i-il;
    int rightCount=ih-i;
    root->left=build(pre,pl+1,pl+leftCount,in,il,i-1);
    root->right=build(pre,pl+leftCount+1,ph,in,i+1,ih);
    return root;
}

Node* buildTree(vector<int> pre,vector<int> in){
    int n=pre.size();
    return build(pre,0,n-1,in,0,n-1);
}

void preorder(Node *root){
    if(root==NULL) return;
    cout<<root->val<<" ";
    preorder(root->left);
    preorder(root->right);
}

int main(){
    vector<int> pre={3,9,20,15,7};
    vector<int> in={9,3,15,20,7};
    Node *root=buildTree(pre,in);
    preorder(root);
}