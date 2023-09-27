// LEETCODE 237 -> Delete Node in a Linked List

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

Node* delNode(Node* head,Node *target){
    if(head==target){
        head=head->next;
        return head;
    }
    Node* temp=head;
    while(temp->next!=target){
        temp=temp->next;
    }
    temp->next=temp->next->next;
    return head;
}

Node* delNodeByVal(Node* head,int target){
    if(head->val==target){
        head=head->next;
        return head;
    }
    Node* temp=head;
    while(temp->next->val!=target){
        temp=temp->next;
    }
    temp->next=temp->next->next;
    return head;
}

void deleteNode(Node* node) {
    node->val=node->next->val;
    node->next=node->next->next;
}

int main(){
    Node *a=new Node(10);
    Node *b=new Node(20);
    Node *c=new Node(30);
    Node *d=new Node(40);
    Node *e=new Node(50);
    a->next=b;
    b->next=c;
    c->next=d;
    d->next=e;

    Node* head=a;
    display(head);
    head=delNode(head,d);
    display(head);
    head=delNodeByVal(head,30);
    display(head);
    deleteNode(b);
    display(head);
}