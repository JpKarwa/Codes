// LEETCODE 2 -> Add two numbers

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

Node *addBoth(Node *l1,Node *l2){
    Node *a=l1;
    Node *b=l2;
    Node *dummy=new Node(-1);
    Node *c=dummy;
    int carry=0;
    while(a or b){
        int x=a?a->val:0;
        int y=b?b->val:0;
        int sum=x+y+carry;
        Node *node=new Node(sum%10);
        c->next=node;
        carry=sum/10;
        c=c->next;
        if(a) a=a->next;
        if(b) b=b->next;
    }
    if(carry) c->next=new Node(carry);
    return dummy->next;
}

int main(){
    Node *a=new Node(2);
    Node *b=new Node(4);
    Node *c=new Node(3);
    a->next=b;
    b->next=c;

    Node *d=new Node(5);
    Node *e=new Node(6);
    Node *f=new Node(4);
    d->next=e;
    e->next=f;

    display(a);
    cout<<endl;
    display(d);
    cout<<endl;
    Node *ans=addBoth(a,d);    
    display(ans);
}