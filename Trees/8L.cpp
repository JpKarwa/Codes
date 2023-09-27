// LEETCODE 257 -> Binary paths

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

void helper(Node *root,vector<string> &v,string s){
    if(root==NULL) return;
    string temp=to_string(root->val);
    if(root->left==NULL && root->right==NULL){
        s+=temp;
        v.push_back(s);
        return;
    }
    helper(root->left,v,s+temp+"->");
    helper(root->right,v,s+temp+"->");
}

vector<string> binaryPaths(Node *root){
    vector<string> ans;
    helper(root,ans," ");
    return ans;
}

int main(){
    Node *a=new Node(1);
    Node *b=new Node(2);
    Node *c=new Node(3);
    Node *d=new Node(5);
    a->left=b;
    a->right=c;
    b->right=d;
    vector<string> ans=binaryPaths(a);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<endl;
    }
}