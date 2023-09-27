// LEETCODE 25 -> Reverse Nodes in K group

#include<iostream>
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

void display(Node *head){
    while(head!=NULL){
        cout<<head->val<<" ";
        head=head->next;
    }
}

int sizeofll(Node *head){
    int count=0;
    Node *temp=head;
    while(temp){
        count++;
        temp=temp->next;
    }
    return count;
}

Node *reverseKgroups(Node *head,int k){
    int size=sizeofll(head);
    if(size<k || head==NULL || k==1) return head;
    Node *dummy=new Node(-1);
    dummy->next=head;
    Node *curr=dummy;
    Node *prev=dummy;
    Node *agla=dummy;
    while(size>=k){
        curr=prev->next;
        agla=curr->next;
        for(int i=1;i<k;i++){
            curr->next=agla->next;
            agla->next=prev->next;
            prev->next=agla;
            agla=curr->next;
        }
        prev=curr;
        size=size-k;
    }
    return dummy->next;
}

int main(){
    Node *a=new Node(1);
    Node *b=new Node(2);
    Node *c=new Node(3);
    Node *d=new Node(4);
    Node *e=new Node(5);
    Node *f=new Node(6);
    Node *g=new Node(7);
    a->next=b;
    b->next=c;
    c->next=d;
    d->next=e;
    e->next=f;
    f->next=g;
    display(a);
    cout<<endl;
    Node *temp=reverseKgroups(a,3);
    display(temp);
}