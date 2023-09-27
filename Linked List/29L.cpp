// LEETCODE 328 -> Even Odd Linked List

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

Node *oddeven(Node *head){
    Node *dummy1=new Node(-1);
    Node *dummy2=new Node(-1);
    Node *a=dummy1;
    Node *b=dummy2;
    Node *temp=head;
    while(temp){
        a->next=temp;
        temp=temp->next;
        a=a->next;
        if(temp==NULL) break;
        b->next=temp;
        temp=temp->next;
        b=b->next;
    }
    a->next=dummy2->next;
    b->next=NULL;
    return dummy1->next;
}

int main(){
    Node *a =new Node(1);
    Node *b =new Node(2);
    Node *c =new Node(3);
    Node *d =new Node(4);
    Node *e =new Node(5);
    a->next=b;
    b->next=c;
    c->next=d;
    d->next=e;
    display(a);
    cout<<endl;
    Node *temp=oddeven(a);
    display(temp);
}