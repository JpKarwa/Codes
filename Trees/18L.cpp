// LEETCODE 102 -> Binary Tree Level Order Traversal

#include<iostream>
#include<vector>
#include<queue>
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

// Method 1
int levels(Node *root){
    if(root==NULL) return 0;
    return 1+max(levels(root->left),levels(root->right));
}

void nthLevel(Node *root,int level,int curr,vector<int> &v){
    if(root==NULL) return;
    if(curr==level){
        v.push_back(root->val);
        return;
    }
    nthLevel(root->left,level,curr+1,v);
    nthLevel(root->right,level,curr+1,v);
}

void lot1(Node *root,vector<vector<int>> &ans){
    int n=levels(root);
    for(int i=1;i<=n;i++){
        vector<int> temp;
        nthLevel(root,i,1,temp);
        ans.push_back(temp);
    }
}

vector<vector<int>> levelOrderTraversal1(Node *root){
    vector<vector<int>> ans;
    lot1(root,ans);
    return ans;
}

// method2
void lot2(Node *root,vector<vector<int>> &ans,int level){
    if(root==NULL) return;
    ans[level].push_back(root->val);
    lot2(root->left,ans,level+1);
    lot2(root->right,ans,level+1);
} 

vector<vector<int>> levelOrderTraversal2(Node *root){
    vector<vector<int>> ans;
    int n=levels(root);
    // pushing n empty vector to our final answer
    for(int i=1;i<=n;i++){
        vector<int> temp;
        ans.push_back(temp);
    }
    lot2(root,ans,0);
    return ans;
}

// method3
void helper(Node *root,vector<vector<int>> &v){
    if(root==NULL) return;
    queue<Node*> q;
    q.push(root);
    while(q.size()>0){
        vector<int> t;
        int n=q.size();
        for(int k=0;k<n;k++){
            Node *temp=q.front();
            q.pop();
            t.push_back(temp->val);
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
        v.push_back(t);
    }
}
vector<vector<int>> levelOrder(Node* root) {
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
    vector<vector<int>> ans=levelOrderTraversal1(a);
    for(int i=0;i<ans.size();i++){
        for(auto it:ans[i]){
            cout<<it<<" ";
        }
        cout<<endl;
    }
    vector<vector<int>> ans2=levelOrderTraversal2(a);
    for(int i=0;i<ans2.size();i++){
        for(auto it:ans2[i]){
            cout<<it<<" ";
        }
        cout<<endl;
    }
    vector<vector<int>> ans3=levelOrder(a);
    for(int i=0;i<ans3.size();i++){
        for(auto it:ans3[i]){
            cout<<it<<" ";
        }
        cout<<endl;
    }
}