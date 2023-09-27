// LEETCODE 141 -> Linked List Cycle

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

bool hasCycle(Node *head) {
    Node* slow=head;
    Node* fast=head;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast) return true;
    }
    return false;
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
    cout<<hasCycle(a);
}