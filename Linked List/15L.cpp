// LEETCODE 86-> Partition List

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

Node *partitionList(Node *head,int x){
    // make 2 dummy node
    Node *low=new Node(-1);         // contain nodes having less than x
    Node *high=new Node(-1);        // contain nodes having value greater or equal x
    Node *tempL=low;
    Node *tempH=high;
    Node *temp=head;
    while(temp!=NULL){
        if(temp->val<x){
            tempL->next=temp;
            temp=temp->next;
            tempL=tempL->next;
        }
        else{
            tempH->next=temp;
            temp=temp->next;
            tempH=tempH->next;
        }
    }
    tempL->next=high->next;
    tempH->next=NULL;
    return low->next;
}

int main(){
    Node *a=new Node(1);
    Node *b=new Node(4);
    Node *c=new Node(3);
    Node *d=new Node(2);
    Node *e=new Node(5);
    Node *f=new Node(2);
    a->next=b;
    b->next=c;
    c->next=d;
    d->next=e;
    e->next=f;
    f->next=NULL;
    
    int x=3;

    display(a);
    cout<<endl;

    a=partitionList(a,3);

    display(a);
}