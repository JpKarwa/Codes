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

Node *reversed(Node *head){
    if(head==NULL || head->next==NULL) return head;
    Node *newHead=reversed(head->next);
    head->next->next=head;
    head->next=NULL;
    return newHead;
}

void reorder(Node *head){
    Node *slow=head;
    Node *fast=head;
    while(fast->next!=NULL && fast->next->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    Node *b=reversed(slow->next);
    slow->next=NULL;          // break in 2 parts
    Node *a=head;
    Node *c=new Node(-1);      // Farzi node
    Node *ta=a,*tb=b,*tc=c;
    while(ta && tb){
        tc->next=ta;
        ta=ta->next;
        tc=tc->next;
        tc->next=tb;
        tb=tb->next;
        tc=tc->next;
    }
    tc->next=ta;
    head=c->next;
}

int main(){
    Node *a=new Node(1);
    Node *b=new Node(2);
    Node *c=new Node(3);
    Node *d=new Node(4);
    Node *e=new Node(5);
    a->next=b;
    b->next=c;
    c->next=d;
    d->next=e;

    display(a);
    cout<<endl;
    reorder(a);
    display(a);

}