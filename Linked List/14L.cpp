// LEETCODE 148-> Sort List

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

Node *mergeList(Node *a,Node *b){
    Node *c=new Node(-1);   // dummy node
    Node *temp=c;
    while(a!=NULL && b!=NULL){
        if(a->val<=b->val){
            temp->next=a;
            a=a->next;
            temp=temp->next;
        }
        else{
            temp->next=b;
            b=b->next;
            temp=temp->next;
        }
    }
    if(a==NULL) temp->next=b;
    else temp->next=a;
    return c->next;
}

void display(Node *head){
    while(head!=NULL){
        cout<<head->val<<" ";
        head=head->next;
    }
}

Node* sortList(Node *head){
    // base case
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node *slow=head;
    Node *fast=head;
    while(fast->next!=NULL && fast->next->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    Node *head1=head;
    Node *head2=slow->next;
    slow->next=NULL;
    Node *a=sortList(head1);
    Node *b=sortList(head2);
    Node *c=mergeList(a,b);
    return c;
}

int main(){
    // Node *a=new Node(4);
    // Node *b=new Node(2);
    // Node *c=new Node(1);
    // Node *d=new Node(3);
    Node *a=new Node(-1);
    Node *b=new Node(5);
    Node *c=new Node(3);
    Node *d=new Node(4);
    Node *e=new Node(0);
    a->next=b;
    b->next=c;
    c->next=d;
    d->next=e;
    e->next=NULL;

    display(a);
    a=sortList(a);
    cout<<endl;
    display(a);
}