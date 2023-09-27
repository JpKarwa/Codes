// LEETCODE 19 -> Remove nth node from the end of list


#include<iostream>
using namespace std;

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

Node* removeNthFromEnd(Node* head, int n) {
    int len=0;
    Node* temp=head;
    while(temp!=NULL){
        len++;
        temp=temp->next;
    }
    int idx=len-n;  // index of node to be deleted

    if(len==n){
        head=head->next;
        return head;
    }
    
    temp=head;
    for(int i=1;i<idx;i++){
        temp=temp->next;
    }

    temp->next=temp->next->next;
    return head;
}

Node* removeNthFromEnd2(Node* head, int n) {
    Node* slow=head;
    Node* fast=head;

    // fast ko n+1 steps aage le jao
    for(int i=1;i<=n+1;i++){
        if(fast==NULL){
            head=head->next;
            return head;
        }
        fast=fast->next;
    }

    // move fast and slow by 1 step
    while(fast!=NULL){
        slow=slow->next;
        fast=fast->next;
    }
    // now slow is at one place before nth node from end
    slow->next=slow->next->next;
    return head;
}

void display(Node *head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->val<<" ";
        temp=temp->next;
    }
    cout<<endl;
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

    Node *head=a;
    display(head);
    head=removeNthFromEnd(head,2);
    display(head);
    head=removeNthFromEnd2(head,5);
    display(head);
}