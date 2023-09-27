// LEETCODE 1019 -> Next Greater Node in a Linked List

#include<iostream>
#include<stack>
#include<vector>
using namespace std;

class Node{
    public:
        int val;
        Node *next;
        Node(int val){
            this->val=val;
            this->next=NULL;
        }
};

vector<int> nextLargerNode(Node *head){
    vector<int> values;
    while(head){
        values.push_back(head->val);
        head=head->next;
    }
    // finding next greater element array
    int n=values.size();
    vector<int> nge(n,0);
    stack<int> s;
    s.push(values[n-1]);
    for(int i=n-2;i>=0;i--){
        while(s.size()>0 && s.top()<=values[i]) s.pop();
        if(s.size()!=0) nge[i]=s.top();
        s.push(values[i]);
    }
    return nge;
}

int main(){
    Node *a=new Node(2);
    Node *b=new Node(7);
    Node *c=new Node(4);
    Node *d=new Node(3);
    Node *e=new Node(5);
    a->next=b;
    b->next=c;
    c->next=d;
    d->next=e;
    vector<int> ans=nextLargerNode(a);    
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}