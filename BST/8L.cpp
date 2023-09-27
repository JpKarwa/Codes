// LEETCODE 450 -> Delete Node in BST

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

void inorder(Node *root){
    if(root==NULL) return;
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}

Node *inorderPredecessor(Node *root){
    // go left once
    Node* pred=root->left;
    // go right
    while(pred->right){
        pred=pred->right;
    }
    return pred;
}

Node* deleteNode(Node* root, int key) {
    if(root==NULL) return NULL;
    if(root->val==key){
        // Case 1 -> No child
        if(root->left==NULL && root->right==NULL) return NULL;

        // Case 2 -> One child
        if(root->left==NULL || root->right==NULL){
            // Jo bhi mera null ke barabar nhi h main usko hi return kr dunga
            if(root->left!=NULL) return root->left;
            else return root->right;
        }

        // Case 3 -> Two Child
        if(root->left!=NULL && root->right!=NULL){
            // replace the root within its inorder pred/succ
            Node *pred=inorderPredecessor(root);
            root->val=pred->val;
            // delete predecessor/successor also
            root->left=deleteNode(root->left,pred->val);
        }
    }
    else if(root->val > key) root->left=deleteNode(root->left,key);
    else root->right=deleteNode(root->right,key);
    return root;
}

int main(){
    Node *a=new Node(5);
    Node *b=new Node(3);
    Node *c=new Node(6);
    Node *d=new Node(2);
    Node *e=new Node(4);
    Node *f=new Node(7);
    a->left=b;
    a->right=c;
    b->left=d;
    b->right=e;
    c->right=f;
    inorder(a);
    cout<<endl;
    a=deleteNode(a,3);
    inorder(a);
}