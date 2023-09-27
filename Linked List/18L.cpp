// LEETCODE 92 - Reverse Linked List II

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

Node *reverseLL2(Node *head,int left,int right){
    if(left==right) return head;
    Node *temp=head;
    Node *a=NULL,*b=NULL,*c=NULL,*d=NULL;
    int idx=1;
    while(temp!=NULL){
        if(idx==left-1) a=temp;
        if(idx==left) b=temp;
        if(idx==right) c=temp;
        if(idx==right+1) d=temp;
        idx++;
        temp=temp->next;
    }
    if(a) a->next=NULL;
    c->next=NULL;
    c=iterative(b);
    if(a) a->next=c;
    b->next=d;
    if(a) return head;
    return c;
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
    int left=2,right=4;
    cout<<endl;
    a=reverseLL2(a,left,right);
    display(a);
}