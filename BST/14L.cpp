// LEETCODE 114 -> Flatten a Binary tree to linked list

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

void print(Node *root){
    if(root==NULL) return;
    print(root->left);
    cout<<root->val<<" ";
    print(root->right);
}

// Method 1 -> Make a preorder vector of tree nodes
void preorder(Node *root,vector<Node*> &ans){
    if(root==NULL) return;
    ans.push_back(root);
    preorder(root->left,ans);
    preorder(root->right,ans);
}

void flatten1(Node *root){
    // create a vector ans to store the nodes in preorder
    vector<Node*> ans;
    preorder(root,ans);
    int n=ans.size();
    for(int i=0;i<n-1;i++){
        ans[i]->right=ans[i+1];
    }
    // make all left connection to NULL;
    for(auto it:ans){
        it->left=NULL;
    }
}

// Method 2-> Simple recursion
void flatten2(Node *root){
    if(root==NULL) return;
    // segregate root,lst,rst
    Node *l=root->left;
    Node *r=root->right;
    root->left=NULL;
    root->right=NULL;
    flatten2(l);
    flatten2(r);
    root->right=l;
    Node *temp=root;
    while(temp->right){
        temp=temp->right;
    }
    temp->right=r;
}

// Method 3-> Kind of morris traversal
void flatten3(Node *root){
    if(root==NULL) return;
    Node *curr=root;
    while(curr!=NULL){
        if(curr->left!=NULL){
            // store right of curr
            Node *r=curr->right;
            // remove the right connections
            curr->right=curr->left;
            // find the predecessor
            Node *pred=curr->left;
            while(pred->right!=NULL){
                pred=pred->right;
            }
            // link
            pred->right=r;
            curr=curr->left;
        }
        else curr=curr->right;
    }
    // making the left connections to NULL
    Node *temp=root;
    while(temp->right!=NULL){
        temp->left=NULL;
        temp=temp->right;
    }
}

int main(){
    Node *a=new Node(1);
    Node *b=new Node(2);
    Node *c=new Node(5);
    Node *d=new Node(3);
    Node *e=new Node(4);
    Node *f=new Node(6);
    a->left=b;
    a->right=c;
    b->left=d;
    b->right=e;
    c->right=f;
    flatten1(a);
    print(a);
}