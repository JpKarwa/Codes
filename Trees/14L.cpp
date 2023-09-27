// LEETCODE 144 -> Binary Tree Preorder Traversal

#include<iostream>
#include<vector>
#include<stack>
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

// method1 recursive
void preorder(Node *root,vector<int> &v){
    if(root==NULL) return;
    v.push_back(root->val);
    preorder(root->left,v);
    preorder(root->right,v);
}

vector<int> preorderTraversal(Node *root){
    vector<int> ans;
    preorder(root,ans);
    return ans;
}


// method2 iterative
vector<int> preorderIt(Node *root){
    vector<int> v;
    stack<Node *> s;
    if(root!=NULL) s.push(root);
    while(s.size()>0){
        Node *temp=s.top();
        s.pop();
        v.push_back(temp->val);
        if(temp->right) s.push(temp->right);
        if(temp->left) s.push(temp->left);
    }
    return v;
}

int main(){
    Node *a=new Node(1);
    Node *b=new Node(2);
    Node *c=new Node(3);
    a->right=b;
    b->left=c;
    vector<int> ans=preorderTraversal(a);
    for(auto it:ans){
        cout<<it<<" ";
    }
    cout<<endl;
    vector<int> ans1=preorderIt(a);
    for(auto it:ans1){
        cout<<it<<" ";
    }
}