// deep copy of a single linked list

#include<bits\stdc++.h>
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
    while(head!=NULL){
        cout<<head->val<<" ";
        head=head->next;
    }
}

Node* deepcopy(Node *head){
    Node *dummy=new Node(-1);
    Node *td=dummy;
    Node *temp=head;
    while(temp){
        Node *newNode=new Node(temp->val);
        td->next=newNode;
        td=td->next;
        temp=temp->next;
    }
    return dummy->next;
}

int main(){
    Node *a =new Node(1);
    Node *b =new Node(3);
    Node *c =new Node(2);
    Node *d =new Node(2);
    Node *e =new Node(3);
    Node *f =new Node(2);
    Node *g =new Node(2);
    Node *h =new Node(2);
    Node *i =new Node(7);
    a->next=b;
    b->next=c;
    c->next=d;
    d->next=e;
    e->next=f;
    f->next=g;
    g->next=h;
    h->next=i;
    Node *dc=deepcopy(a);
    display(dc);
}