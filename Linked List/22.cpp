// reverse linked list in groups

#include<bits\stdc++.h>
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

Node *reversed(Node *head){
    Node *temp=head;
    Node *prev=NULL,*curr=head,*aage=head;
    while(curr){
        aage=curr->next;
        curr->next=prev;
        prev=curr;
        curr=aage;
    }
    return prev;
}
Node* reverseBetween(Node* head, int left, int right) {
    if(left==right) return head;
    int idx=1;
    Node *temp=head;
    Node *a=NULL,*b=NULL,*c=NULL,*d=NULL;
    // linked list breaked into 3 linked list
    while(temp!=NULL){
        if(idx==left-1) a=temp;
        if(idx==left) b=temp;
        if(idx==right) c=temp;
        if(idx==right+1) d=temp;
        temp=temp->next;
        idx++;
    }
    if(a) a->next=NULL;
    c->next=NULL;
    c=reversed(b);
    if(a) a->next=c;
    b->next=d;
    if(a) return head;
    return c;
}

Node *reverseGroups(Node *head){
    Node *temp=head;
    int gap=1;
    while(temp && temp->next){
        int remLen=0;
        Node *t=temp->next;
        for(int i=1;i<=gap+1 && t!=NULL;i++){
            t=t->next;
            remLen++;
        }
        if(remLen < gap+1) gap=remLen-1;
        reverseBetween(temp,2,2+gap);
        gap++;
        for(int i=1;temp!=NULL && i<=gap;i++){
            temp=temp->next;
        }
    }
    return head;
}

int main(){
    Node *a =new Node(5);
    Node *b =new Node(2);
    Node *c =new Node(6);
    Node *d =new Node(3);
    Node *e =new Node(9);
    Node *f =new Node(1);
    Node *g =new Node(7);
    Node *h =new Node(3);
    Node *i =new Node(8);
    Node *j =new Node(4);
    a->next=b;
    b->next=c;
    c->next=d;
    d->next=e;
    e->next=f;
    f->next=g;
    g->next=h;
    h->next=i;
    i->next=j;
    Node *head=a;
    display(head);
    cout<<endl;
    reverseGroups(head);
    display(head);
}