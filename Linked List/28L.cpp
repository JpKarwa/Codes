// Leetcode 147 -> Insertion Sort Linked LIST

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

Node *insertionSort(Node *head){
    Node *dummy=new Node(-1);
    dummy->next=head;
    Node *curr=head;
    Node *prev=dummy;
    while(curr){
        if(curr->next && curr->next->val<curr->val){
            while(prev->next && prev->next->val < curr->next->val){
                prev=prev->next;
            }
            Node *temp=prev->next;
            prev->next=curr->next;
            curr->next=curr->next->next;
            prev->next->next=temp;
            prev=dummy;
        }
        else{
            curr=curr->next;
        }
    }
    return dummy->next;
}

int main(){
    Node *a =new Node(-1);
    Node *b =new Node(5);
    Node *c =new Node(3);
    Node *d =new Node(4);
    Node *e =new Node(0);
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
    display(a);
    cout<<endl;
    Node *temp=insertionSort(a);
    display(temp);
}