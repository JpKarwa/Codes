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

void reverseDisplay(Node* head){
    if(head==NULL) return;
    reverseDisplay(head->next);
    cout<<head->val<<" ";
}

int main(){
    // 10 20 30 40
    Node *a=new Node(10);
    Node *b=new Node(20);
    Node *c=new Node(30);
    Node *d=new Node(40);
    a->next=b;
    b->next=c;
    c->next=d;   

    // printing linked list in reverse order
    reverseDisplay(a);
}