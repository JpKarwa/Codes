// LEETCODE 113 -> Path Sum II

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

void helper(Node *root,vector<int> temp,vector<vector<int>> &ans,int target){
    if(root==NULL) return;
    if(root->left==NULL && root->right==NULL){
        temp.push_back(root->val);
        target=target-(root->val);
        if(target==0) ans.push_back(temp);
        return;
    }
    temp.push_back(root->val);
    target=target-(root->val);
    helper(root->left,temp,ans,target);
    helper(root->right,temp,ans,target);
}

vector<vector<int>> pathSum(Node *root,int targetSum){
    vector<vector<int>> ans;
    vector<int> temp;
    helper(root,temp,ans,targetSum);
    return ans;
}

int main(){
    Node *a=new Node(5);
    Node *b=new Node(4);
    Node *c=new Node(8);
    Node *d=new Node(11);
    Node *e=new Node(13);
    Node *f=new Node(4);
    Node *g=new Node(7);
    Node *h=new Node(2);
    Node *i=new Node(5);
    Node *j=new Node(1);
    a->left=b;
    a->right=c;
    b->left=d;
    c->left=e;
    c->right=f;
    d->left=g;
    d->right=h;
    f->left=i;
    f->right=j;
    vector<vector<int>> ans=pathSum(a,22);
    for(int i=0;i<ans.size();i++){
        for(auto it:ans[i]){
            cout<<it<<" ";
        }
        cout<<endl;
    }
}