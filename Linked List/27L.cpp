// LEETCODE 82 -> Remove duplicates from sorted list II

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
    while(head!=NULL){
        cout<<head->val<<" ";
        head=head->next;
    }
}

Node *removeDuplicates(Node *head){
    if(head==NULL && head->next==NULL) return head;
    Node *temp=head;
    Node *dummy=new Node(-1);
    Node *prev=dummy;
    dummy->next=head;
    Node *curr=head;
    while(curr){
        if(curr->next!=NULL && curr->val==curr->next->val){
            while(curr->next!=NULL && curr->val==curr->next->val){
                curr=curr->next;
            }
            prev->next=curr->next;
        }
        else{
            prev=prev->next;
        }
        curr=curr->next;
    }
    return head;
}

int main(){
    Node *a =new Node(1);
    Node *b =new Node(2);
    Node *c =new Node(3);
    Node *d =new Node(3);
    Node *e =new Node(4);
    Node *f =new Node(4);
    Node *g =new Node(5);
    a->next=b;
    b->next=c;
    c->next=d;
    d->next=e;
    e->next=f;
    f->next=g;

    display(a);
    cout<<endl;
    a=removeDuplicates(a);
    display(a);
}