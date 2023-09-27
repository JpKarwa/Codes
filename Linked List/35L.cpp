// LEETCODE 2181 -> Merge Nodes in between Zeroes

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
    while(head){
        cout<<head->val<<" ";
        head=head->next;
    }
}

Node *mergeNodes(Node *head){
    Node *temp=head->next;
    Node *dummy=new Node(-1);
    Node *t=dummy;
    int sum=0;
    while(temp){
        if(temp->val==0){
            Node *node=new Node(sum);
            t->next=node;
            t=t->next;
            sum=0;
        }
        sum=sum+(temp->val);
        temp=temp->next;
    }
    return dummy->next;
}

int main(){
    Node *a=new Node(0);
    Node *b=new Node(3);
    Node *c=new Node(0);
    Node *d=new Node(0);
    Node *e=new Node(4);
    Node *f=new Node(5);
    Node *g=new Node(2);
    Node *h=new Node(0);
    a->next=b;
    b->next=c;
    c->next=d;
    d->next=e;
    e->next=f;
    f->next=g;
    g->next=h;
    display(a);
    cout<<endl;
    Node *temp=mergeNodes(a);
    display(temp);
}