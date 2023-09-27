// Find minimum and maximum value of bst

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

vector<int> minMax(Node *root){
    vector<int> ans;
    Node* mini=root;
    Node* maxi=root;
    while(mini->left){
        mini=mini->left;
    }
    while(maxi->right){
        maxi=maxi->right;
    }
    ans.push_back(mini->val);
    ans.push_back(maxi->val);
    return ans;
}
int main(){
    Node *a=new Node(4);
    Node *b=new Node(2);
    Node *c=new Node(7);
    Node *d=new Node(1);
    Node *e=new Node(3);
    a->left=b;
    a->right=c;
    b->left=d;
    b->right=e;
    vector<int> ans=minMax(a);
    cout<<ans[0]<<" "<<ans[1];
}