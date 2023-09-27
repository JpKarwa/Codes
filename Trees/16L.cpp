// LEETCODE 145 -> Binary Tree PostOrder traversal

#include<iostream>
#include<vector>
#include<stack>
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

// method1 recursive
void postorder(Node *root,vector<int> &v){
    if(root==NULL) return;
    postorder(root->left,v);
    postorder(root->right,v);
    v.push_back(root->val);
}

vector<int> postorderTraversal(Node *root){
    vector<int> ans;
    postorder(root,ans);
    return ans;
}


// method2 iterative
vector<int> postorderIt(Node *root){
    vector<int> v;
    stack<Node *> s;
    if(root) s.push(root);
    while(s.size()>0){
        Node *temp=s.top();
        s.pop();
        v.push_back(temp->val);
        if(temp->left) s.push(temp->left);
        if(temp->right) s.push(temp->right);
    }
    reverse(v.begin(),v.end());
    return v;
}

int main(){
    Node *a=new Node(1);
    Node *b=new Node(2);
    Node *c=new Node(3);
    a->right=b;
    b->left=c; 
    vector<int> ans=postorderTraversal(a); 
    for(auto it:ans){
        cout<<it<<" ";
    }
    cout<<endl;
    vector<int> ans1=postorderIt(a); 
    for(auto it:ans1){
        cout<<it<<" ";
    }
}