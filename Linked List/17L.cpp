// LEETCODE 234 - Palindrome Linked LIST

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

Node *recursive(Node *head){
    if(head==NULL || head->next==NULL) return head;
    Node *newHead=recursive(head->next);
    head->next->next=head;
    head->next=NULL;
    return newHead;

    // TC->O(N) SC->O(N) stack frames
}

bool method1(Node *head){
    Node *c=new Node(-1);
    Node *tc=c;
    Node *temp=head;
    while(temp!=NULL){
        Node* node=new Node(temp->val);
        tc->next=node;
        tc=tc->next;
        temp=temp->next;
    }
    c=recursive(c->next);
    Node *a=head;
    Node *b=c;
    while(a){
        if(a->val !=b->val) return false;
        a=a->next;
        b=b->next;
    }
    return true;
}

bool method2(Node *head){
    // if first and second half are reverse of each other than it is palindrome
    Node *slow=head;
    Node *fast=head;
    while(fast->next!=NULL && fast->next->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    // slow is at left middle
    Node *newHead=recursive(slow->next);  // head of reverse second half
    Node *a=head;
    Node *b=newHead;
    while(b!=NULL){
        if(a->val!=b->val) return false;
        a=a->next;
        b=b->next;
    }
    // O(n)time and O(1)space
    return true;
}

int main(){
    Node *a=new Node(1);
    Node *b=new Node(2);
    Node *c=new Node(3);
    Node *d=new Node(3);
    Node *e=new Node(2);
    Node *f=new Node(1);
    a->next=b;
    b->next=c;
    c->next=d;
    d->next=e;
    e->next=f;

    cout<<method1(a);
}