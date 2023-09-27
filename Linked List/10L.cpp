// LEETCODE 61 -> Rotate list

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

void display(Node* head){
    if(head==NULL) return;
    cout<<head->val<<" ";
    display(head->next);
}

Node* Rotate(Node* head,int k){
    if(head==NULL || head->next==NULL) return head;

    // calculate length of LinkedList
    int n=1;
    Node *tail=head;
    while(tail->next!=NULL){
        n++;
        tail=tail->next;
    }
    k=k%n;
    // put temp at (n-k)th position 
    Node *temp=head;
    for(int i=1;i<n-k;i++){
        temp=temp->next;
    }
    tail->next=head;
    head=temp->next;
    temp->next=NULL;
    return head;
}

int main(){
    Node *a=new Node(1);
    Node *b=new Node(2);
    Node *c=new Node(3);
    Node *d=new Node(4);
    Node *e=new Node(5);
    a->next=b;
    b->next=c;
    c->next=d;
    d->next=e;

    display(a);
    cout<<endl;
    a=Rotate(a,2);
    display(a);
}

// Method 2
// s=f=head
// move fast k steps ahead
// move slow and fast until fast.next=null
// it works when k<=n


// int sizeOfLL(ListNode* head){
//     if(head==NULL) return 0;

//     ListNode* temp=head;
//     int count=0;
//     while(temp!=NULL){
//         count++;
//         temp=temp->next;
//     }
//     return count;
// }

// ListNode* rotateRight(ListNode* head, int k) {
//     if(head==NULL || head->next==NULL) return head;
//     int n=sizeOfLL(head);
//     k=k%n;
//     ListNode *slow=head;
//     ListNode *fast=head;
//     for(int i=1;i<=k;i++){
//         fast=fast->next;
//     }
//     while(fast->next!=NULL){
//         slow=slow->next;
//         fast=fast->next;
//     }
//     fast->next=head;
//     head=slow->next;
//     slow->next=NULL;
//     return head;
// }