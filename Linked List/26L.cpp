// Flatten a doubly multilevel linked list

#include<iostream>
using namespace std;

class Node{
    public:
        int val;
        Node *prev;
        Node *next;
        Node *child;
        Node(int data){
            this->val=data;
            this->prev=NULL;
            this->next=NULL;
            this->child=NULL;
        }
};

void display(Node *head){
    while(head!=NULL){
        cout<<head->val<<" ";
        head=head->next;
    }
}

Node *flatten(Node *head){
    Node *temp=head;
    while(temp){
        Node *a=temp->next;
        if(temp->child){
            Node *c=temp->child;
            temp->child=NULL;
            c=flatten(c);
            temp->next=c;
            c->prev=temp;
            while(c->next){
                c=c->next;
            }
            c->next=a;
            if(a!=NULL) a->prev=c;
        }
        temp=a;
    }
    return head;
}

int main(){
    // level 1
    Node *a =new Node(1);
    Node *b =new Node(2);
    Node *c =new Node(3);
    Node *d =new Node(4);
    Node *e =new Node(5);
    Node *f =new Node(6);
    a->next=b;
    b->next=c;
    c->next=d;
    d->next=e;
    e->next=f;
    b->prev=a;
    c->prev=b;
    d->prev=c;
    e->prev=d;
    f->prev=e;
    Node *g =new Node(7);
    Node *h =new Node(8);
    Node *i =new Node(9);
    Node *j =new Node(10);
    g->next=h;
    h->next=i;
    i->next=j;
    h->prev=g;
    i->prev=h;
    j->prev=i;
    Node *k =new Node(11);
    Node *l =new Node(12);
    k->next=l;
    l->prev=k;
    c->child=g;
    h->child=k;

    Node *final=flatten(a);
    display(final);
}