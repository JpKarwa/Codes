// LEETCODE 160 -> Intersection of 2 Linked List

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

int length(Node* head){
    int size=0;
    Node* temp=head;
    while(temp!=NULL){
        temp=temp->next;
        size++;
    }
    return size;
}

Node *getIntersectionNode(Node *headA, Node *headB) {
    // find the length of two LL
    int len1=length(headA);
    int len2=length(headB);

    Node* temp2=headB;
    Node* temp1=headA;
    int pos=abs(len1-len2);
    if(len1>len2){
        for(int i=1;i<=pos;i++){
            temp1=temp1->next;
        }
    }
    else{
        for(int i=1;i<=pos;i++){
            temp2=temp2->next;
        }
    }
    while(temp1!=temp2){
        temp1=temp1->next;
        temp2=temp2->next;
    }
    return temp1; 
}

int main(){
    Node *a=new Node(4);
    Node *b=new Node(1);
    Node *c=new Node(8);
    Node *d=new Node(4);
    Node *e=new Node(5);
    a->next=b;
    b->next=c;
    c->next=d;
    d->next=e;
    Node *A=new Node(5);
    Node *B=new Node(6);
    Node *C=new Node(1);
    A->next=B;
    B->next=C;
    C->next=c;
    Node *headA=a;
    Node *headB=A;
    cout<<getIntersectionNode(headA,headB)->val;
}