// LEETCODE 1008 -> Construct BST from preorder traversal

#include<iostream>
#include<vector>
#include<algorithm>
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

// METHOD 1 -> Construct from pre and in (copy paste)
Node *build(vector<int> &pre,int preLo,int preHi,vector<int> &in,int inLo,int inHi){
    if(preLo>preHi) return NULL;
    //creating a root
    Node *root=new Node(pre[preLo]);
    int i=inLo;
    while(i<=inHi){
        if(in[i]==pre[preLo]) break;
        i++;
    }
    // count of element in LST and RST
    int leftCount=i-inLo;
    int rightCount=inHi-i;
    root->left=build(pre,preLo+1,preLo+leftCount,in,inLo,i-1);
    root->right=build(pre,preLo+leftCount+1,preHi,in,i+1,inHi);
    return root;
}
Node *bstFromPreorder1(vector<int> &pre){
    vector<int> in=pre;
    sort(in.begin(),in.end());
    int n=in.size();
    return build(pre,0,n-1,in,0,n-1);
}

// METHOD 2 -> Insert into bst (copy paste)
void insertIntoBST(Node *root,int val){
    if(root==NULL) root=new Node(val);
    else if(root->val > val){  // go left
        if(root->left==NULL){
            root->left=new Node(val);
        }
        else insertIntoBST(root->left,val);
    }
    else{
        if(root->right==NULL){
            root->right=new Node(val);
        }
        else insertIntoBST(root->right,val);
    }
}
Node *bstFromPreorder2(vector<int> &pre){
    // create root node
    Node *root=new Node(pre[0]);
    for(int i=1;i<pre.size();i++){
        insertIntoBST(root,pre[i]);
    }
    return root;
}

int main(){
    vector<int> pre={8,5,1,7,10,12};
    Node *root=bstFromPreorder1(pre);
    inorder(root);
    cout<<endl;
    Node *roots=bstFromPreorder2(pre);
    inorder(root);
}