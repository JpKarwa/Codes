// LEETCODE 2487 -> Remove node from linked list

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

// Node *removeNodes(Node *head){
//     if(head==NULL || head->next==NULL) return head;
//     Node *newNode=removeNodes(head->next);
//     if(head->val<newNode->val) return newNode;
//     head->next=newNode;
//     return head;
// }

Node *removeNodes(Node *head){
    vector<int> values;
    // push all element of linked list into array
    while(head){
        values.push_back(head->val);
        head=head->next;
    }
    // creating next greater element array of values array
    int n=values.size();
    vector<int> nge(n,-1);
    stack<int> s;
    s.push(values[n-1]);
    for(int i=n-2;i>=0;i--){
        while(s.size()>0 && s.top()<=values[i]) s.pop();
        if(s.size()!=0) nge[i]=s.top();
        s.push(values[i]);
    }
    // take only that values having no greater element from them
    // convert that into linked list
    Node *dummy=new Node(-1);
    Node *tc=dummy;
    for(int i=0;i<n;i++){
        if(nge[i]==-1){
            Node *temp=new Node(values[i]);
            tc->next=temp;
            tc=tc->next;
        }
    }
    return dummy->next;
}

int main(){
    Node *a=new Node(5);
    Node *b=new Node(2);
    Node *c=new Node(13);
    Node *d=new Node(3);
    Node *e=new Node(8);
    a->next=b;
    b->next=c;
    c->next=d;
    d->next=e;
    Node *temp=removeNodes(a);
    while(temp){
        cout<<temp->val<<" ";
        temp=temp->next;
    }
}