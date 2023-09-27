// TOP VIEW OF A BINARY TREE

#include<iostream>
#include<vector>
#include<climits>
#include<unordered_map>
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

vector<int> topView(Node *root){
    vector<int> ans;
    if(root==NULL) return ans;
    unordered_map<int,int> m;  // key ->vertical level , value -> val of node
    queue< pair<Node*,int> > q;        // node ki val ,level
    pair<Node*,int> p;
    p.first=root;
    p.second=0;
    q.push(p);
    while(q.size()!=0){
        // current node aur level le liya
        Node *temp=(q.front()).first;
        int level=(q.front()).second;
        q.pop();
        if(m.find(level)==m.end()){
            m[level]=temp->val;
        }
        if(temp->left!=NULL){
            pair<Node*,int> t;
            t.first=temp->left;
            t.second=level-1;
            q.push(t);
        }
        if(temp->right!=NULL){
            pair<Node*,int> t;
            t.first=temp->right;
            t.second=level+1;
            q.push(t);
        }
    }
    int minLevel=INT_MAX;
    int maxLevel=INT_MIN;
    for(auto x:m){
        int level=x.first;
        minLevel=min(minLevel,level);
        maxLevel=max(maxLevel,level);
    }
    for(int i=minLevel;i<=maxLevel;i++){
        ans.push_back(m[i]);
    }
    return ans;
}
int main(){
    Node *a=new Node(1);
    Node *b=new Node(2);
    Node *c=new Node(3);
    Node *d=new Node(4);
    Node *e=new Node(5);
    Node *f=new Node(6);
    Node *g=new Node(7);
    a->left=b;
    a->right=c;
    b->left=d;
    b->right=e;
    c->left=f;
    c->right=g;
    vector<int> ans=topView(a);
    for(auto it:ans){
        cout<<it<<" ";
    }   
}