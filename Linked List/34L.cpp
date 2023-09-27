// LEETCODE 24 -> Swap nodes in pairs

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

Node *method1(Node *head){
    Node *temp=head;
    while(temp && temp->next){
        if(temp->next) swap(temp->val,temp->next->val);
        temp=temp->next->next;
    }
    return head;
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

Node *method2(Node *head){
    int size=sizeofll(head);
    if(size<2 || head==NULL) return head;
    Node *dummy=new Node(-1);
    dummy->next=head;
    Node *curr=dummy;
    Node *prev=dummy;
    Node *agla=dummy;
    while(size>=2){
        curr=prev->next;
        agla=curr->next;
        curr->next=agla->next;
        agla->next=prev->next;
        prev->next=agla;
        agla=curr->next;
        prev=curr;
        size=size-2;
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
    a=method1(a);
    display(a);
    cout<<endl;
    a=method2(a);
    display(a);
}