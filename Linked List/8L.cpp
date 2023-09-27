// LEETCODE 142-> Linked List Cycle II

#include<iostream>
using namespace std;

class Node{
    public:
        int val;
        Node* next;
        Node(int v){
            this->val=v;
            this->next=NULL;
        }
};

Node *detectCycle(Node *head) {
    Node* slow=head;
    Node* fast=head;
    bool cycle=0;   // no cycle
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast) {
            cycle=1;
            break;
        }
    }

    if(cycle==0) return NULL;
    else{
        Node* temp=head;
        while(temp!=slow){
            temp=temp->next;
            slow=slow->next;
        }
        return temp;
    }
}

int main(){
    Node *a=new Node(10);
    Node *b=new Node(20);
    Node *c=new Node(30);
    Node *d=new Node(40);
    Node *e=new Node(50);
    Node *f=new Node(60);
    a->next=b;
    b->next=c;
    c->next=d;
    d->next=e;
    e->next=f;
    f->next=c;
    cout<<detectCycle(a)->val;
}