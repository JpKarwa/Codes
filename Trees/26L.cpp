// LEETCODE 106 -> Construct tree from inorder and postorder.

#include<iostream>
#include<vector>
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
/*
il -> inlow(start of inorder of tree)
ih -> inhigh(end of inorder of tree)
pl -> postlow(start of postorder of tree)
ph -> posthigh(end of postorder of tree)
*/
Node *build(vector<int> &in,int il,int ih,vector<int> &post,int pl,int ph){
    if(il>ih) return NULL;
    // creating a root node
    Node *root=new Node(post[ph]);
    if(il==ih) return root;
    // find the index of that divides tree into 2 part -> lst and rst
    int i=il;
    while(i<=ih){
        if(in[i]==post[ph]) break;
        i++;
    }
    // count of nodes in lst and rst
    int leftCount=i-il;
    int rightCount=ih-i;
    // creating lst and rst
    root->left=build(in,il,i-1,post,pl,pl+leftCount-1);
    root->right=build(in,i+1,ih,post,pl+leftCount,ph-1);
    return root;
}

Node* buildTree(vector<int> &inorder,vector<int> &postorder){
    int n=inorder.size();
    Node *root=build(inorder,0,n-1,postorder,0,n-1);
    return root;
}

void postorder(Node *root){
    if(root==NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->val<<" ";
}

int main(){
    vector<int> post={9,15,7,20,3};
    vector<int> in={9,3,15,20,7};
    Node *root=buildTree(in,post);
    postorder(root);
}