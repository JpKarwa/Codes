// Leetcode 138 -> Copy linked list with random pointer

#include<bits\stdc++.h>
using namespace std;

class Node{
    public:
        int val;
        Node *next;
        Node *random;
        Node(int data){
            this->val=data;
            this->next=NULL;
            this->random=NULL;
        }
};

void display(Node *head){
    while(head!=NULL){
        cout<<head->val<<" ";
        head=head->next;
    }
}

Node *copyRandomList(Node *head){
    // step 1 -> create a copy list without random pointers
    Node *temp=head;
    Node *dummy1=new Node(-1);
    Node *td1=dummy1;
    while(temp){
        Node *newNode=new Node(temp->val);
        td1->next=newNode;
        td1=td1->next;
        temp=temp->next;
    }
    Node *copyKaHead=dummy1->next;

    // step 2 -> create alternate connection (merge both list)
    Node *dummy2=new Node(-1);
    Node *td2=dummy2;
    Node *a=head;
    Node *b=copyKaHead;
    while(a){
        td2->next=a;
        td2=td2->next;
        a=a->next;
        td2->next=b;
        td2=td2->next;
        b=b->next;
    }
    Node *mergeKaHead=dummy2->next;

    // step 3 -> assigning random pointers of duplicates
    Node *c=mergeKaHead;
    while(c){
        Node *d=c->next;                     // travelling on copied list
        if(c->random) d->random=c->random->next;
        c=c->next->next;                     // travelling on original list
    }

    // step 4 -> removing connections
    Node *dummy3=new Node(-1);
    Node *dummy4=new Node(-1);
    Node *td3=dummy3;
    Node *td4=dummy4;
    Node *lTemp=mergeKaHead;
    while(lTemp){
        td3->next=lTemp;
        lTemp=lTemp->next;
        td3=td3->next;
        td4->next=lTemp;
        lTemp=lTemp->next;
        td4=td4->next;
    }
    td3->next=NULL;
    td4->next=NULL;
    return dummy4->next;
}

//Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
// Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]
int main(){
    Node *a =new Node(7);
    Node *b =new Node(13);
    Node *c =new Node(11);
    Node *d =new Node(10);
    Node *e =new Node(1);
    a->next=b;
    b->next=c;
    c->next=d;
    d->next=e;
    b->random=a;
    c->random=e;
    d->random=c;
    e->random=a;
    Node *dc=copyRandomList(a);
    display(dc);
}