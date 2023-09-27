// Binary tree left side view

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

int levels(Node *root){
    if(root==NULL) return 0;
    int level=1+max(levels(root->left),levels(root->right));
    return level;
}

// method 1
void preorder(Node *root,vector<int> &ans,int level){
    if(root==NULL) return;
    ans[level]=root->val;
    preorder(root->right,ans,level+1);
    preorder(root->left,ans,level+1);
}

vector<int> leftSideView(Node *root){
    int n=levels(root);
    vector<int> v(n,0);
    preorder(root,v,0);
    return v;    
}

// method 2
void nthLevel(Node *root,vector<int> &v,int level,int curr){
    if(root==NULL) return;
    if(curr==level){
        v[curr]=root->val;
        return;
    }
    nthLevel(root->right,v,level,curr+1);
    nthLevel(root->left,v,level,curr+1);
}
void lorder(Node *root,vector<int> &v){
    int n=v.size();
    for(int i=0;i<n;i++){
        nthLevel(root,v,i,0);
    }
}

vector<int> leftsideview(Node *root){
    int n=levels(root);
    vector<int> v(n,0);
    lorder(root,v);
    return v;
}

int main(){
    Node *a=new Node(1);
    Node *b=new Node(2);
    Node *c=new Node(3);
    Node *d=new Node(4);
    Node *e=new Node(5);
    Node *f=new Node(6);
    a->left=b;
    a->right=c;
    b->right=e;
    c->right=d;
    d->left=f;
    vector<int> ans=leftSideView(a);
    for(auto it:ans){
        cout<<it<<" ";
    }
    cout<<endl;
    vector<int> ans1=leftsideview(a);
    for(auto it:ans1){
        cout<<it<<" ";
    }
}