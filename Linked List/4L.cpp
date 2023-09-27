// LEETCODE 876 -> Find middle in a Linked List

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

void display(Node *head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->val<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

Node* getMiddle(Node* head){
    Node* temp=head;
    int size=0;
    while(temp!=NULL){
        size++;
        temp=temp->next;
    }

    int midIdx=size/2;
    Node* mid=head;
    for(int i=1;i<=midIdx;i++){
        mid=mid->next;
    }
    return mid;
    // O(n) but it in 2 pass
}

Node* middleNode(Node* head) {
    Node* slow=head;
    Node* fast=head;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}

int main(){
    Node *a=new Node(10);
    Node *b=new Node(20);
    Node *c=new Node(30);
    Node *d=new Node(40);
    Node *e=new Node(50);
    Node *f=new Node(60);
    a->next=b;
    b->next=c;
    c->next=d;
    d->next=e;
    e->next=f;

    cout<<getMiddle(a)->val<<endl;
    cout<<middleNode(a)->val;
}