// LEETCODE 206 - Reverse Linked List 

#include<iostream>
using namespace std;

class Node{
    public:
        int val;
        Node *next;
        Node(int data){
            this->val=data;
            this->next=NULL;
        }
};

void display(Node *head){
    Node *temp=head;
    while(temp!=NULL){
        cout<<temp->val<<" ";
        temp=temp->next;
    }
}

Node* iterative(Node *head){
    Node *prev=NULL;
    Node *curr=head;
    Node *aage=NULL;      // aage ke adddress preserve krke rkhne ke liye
    while(curr){
        aage=curr->next;
        curr->next=prev;
        prev=curr;
        curr=aage;
    }
    return prev;
}

Node *recursive(Node *head){
    if(head==NULL || head->next==NULL) return head;
    Node *newHead=recursive(head->next);
    head->next->next=head;
    head->next=NULL;
    return newHead;

    // TC->O(N) SC->O(N) stack frames
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

    display(a);
    cout<<endl;
    a=iterative(a);
    display(a);
    cout<<endl;
    a=recursive(a);
    display(a);
}