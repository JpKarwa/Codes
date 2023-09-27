// Count the number of subtrees in bst whose node lie within a given range

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

bool helper(Node *root,int low,int high,int &ans){
    if(root==NULL) return true;
    bool l=helper(root->left,low,high,ans);
    bool r=helper(root->right,low,high,ans);
    if(l && r && root->val>=low && root->val<=high){
        ans++;
        return true;
    }
    return false;
}
int countSubtree(Node *root,int low, int high){
    int ans=0;
    helper(root,low,high,ans);
    return ans;
}

int main(){
    Node *a=new Node(10);
    Node *b=new Node(5);
    Node *c=new Node(15);
    Node *d=new Node(3);
    Node *e=new Node(7);
    Node *f=new Node(18);
    a->left=b;
    a->right=c;
    b->left=d;
    b->right=e;
    c->right=f;
    int low=5;
    int high=15;
    cout<<countSubtree(a,low,high);
}