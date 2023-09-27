// LEETCODE 83 -> Remove duplicates in sorted linked list

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

Node* removeDuplicatesIndSortedList(Node *head){
    // if there are 0 nodes or 1 nodes
    if(head==NULL || head->next==NULL) return head;

    Node *a=head;
    Node *b=head->next;
    while(b!=NULL){
        while(b!=NULL && a->val==b->val){
            b=b->next;
        }
        // at this point a and b have different elements
        a->next=b;
        a=b;
        if(b!=NULL) b=b->next;
    }

    return head;
}

void display(Node* head){
    if(head==NULL) return;
    cout<<head->val<<" ";
    display(head->next);
}

int main(){
    Node *a=new Node(10);
    Node *b=new Node(10);
    Node *c=new Node(10);
    Node *d=new Node(20);
    Node *e=new Node(30);
    Node *f=new Node(30);
    Node *g=new Node(40);
    Node *h=new Node(40);
    a->next=b;
    b->next=c;
    c->next=d;
    d->next=e;
    e->next=f;
    f->next=g;
    g->next=h;

    display(a);
    cout<<endl;
    a=removeDuplicatesIndSortedList(a);
    display(a);
}