// LEETCODE 103 -> Binary Tree ZIG ZAG order traversal

#include<iostream>
#include<vector>
#include<queue>
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

void helper(Node *root,vector<vector<int>> &v){
    if(root==NULL) return;
    queue<Node*> q;
    q.push(root);
    int curr=0;
    while(q.size()>0){
        int n=q.size();
        vector<int> t;
        for(int i=0;i<n;i++){
            Node *temp=q.front();
            q.pop();
            t.push_back(temp->val);
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
        if(curr%2!=0) reverse(t.begin(),t.end());
        curr++;
        v.push_back(t);
    }
}

vector<vector<int>> zigzagOrder(Node *root){
    vector<vector<int>> ans;
    helper(root,ans);
    return ans;
}

int main(){
    Node *a=new Node(3);
    Node *b=new Node(9);
    Node *c=new Node(20);
    Node *d=new Node(15);
    Node *e=new Node(7);
    a->left=b;
    a->right=c;
    c->left=d;
    c->right=e;
    vector<vector<int>> ans=zigzagOrder(a);
    for(int i=0;i<ans.size();i++){
        for(auto it:ans[i]){
            cout<<it<<" ";
        }
        cout<<endl;
    }
}