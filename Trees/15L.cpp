// LEETCODE 94 -> Binary tree inorder traversal

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
void inorder(Node *root,vector<int> &v){
    if(root==NULL) return;
    inorder(root->left,v);
    v.push_back(root->val);
    inorder(root->right,v);
}

vector<int> inorderTraversal(Node *root){
    vector<int> ans;
    inorder(root,ans);
    return ans;
}

// method 2 iterative
vector<int> inorderIt(Node *root){
    vector<int> v;
    stack<Node*> s;
    Node *node=root;
    while(s.size()>0 || node!=NULL){
        if(node){
            s.push(node);
            node=node->left;
        }
        else{
            Node *temp=s.top();
            s.pop();
            v.push_back(temp->val);
            node=temp->right;
        }
    }
    return v;
}

int main(){
    Node *a=new Node(1);
    Node *b=new Node(2);
    Node *c=new Node(3);
    a->right=b;
    b->left=c;
    vector<int> ans=inorderTraversal(a); 
    for(auto it:ans){
        cout<<it<<" ";
    }   
    cout<<endl;
    vector<int> ans1=inorderIt(a); 
    for(auto it:ans1){
        cout<<it<<" ";
    } 
}