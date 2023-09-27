// LEETCODE 2130 -> Maximum Twin Sum of a Linked List

#include<bits\stdc++.h>
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

Node *reversed(Node *head){
    if(head==NULL || head->next==NULL) return head;
    Node *newHead=reversed(head->next);
    head->next->next=head;
    head->next=NULL;
    return newHead;
}

int twinSum(Node *head){
    Node *slow=head;
    Node *fast=head;
    while(fast->next && fast->next->next){
        slow=slow->next;
        fast=fast->next->next;
    }
    Node *newHead=reversed(slow->next);
    int ans=0;
    while(head && newHead){
        int sum = head->val + newHead->val;
        ans=max(ans,sum);
        head=head->next;
        newHead=newHead->next;
    }
    return ans;
}

int main(){
    Node *a=new Node(4);
    Node *b=new Node(2);
    Node *c=new Node(2);
    Node *d=new Node(3);
    a->next=b;
    b->next=c;
    c->next=d;

    display(a);
    cout<<endl;
    cout<<twinSum(a);
}