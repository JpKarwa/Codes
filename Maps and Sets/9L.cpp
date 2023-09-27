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
    // step 2-> create a map with unordered_map 
    unordered_map<Node*,Node*> m;
    // key -> original node
    // value -> duplicate node
    Node *a=head;
    Node *b=dummy1->next;
    while(a && b){
        m[a]=b;
        a=a->next;
        b=b->next;
    }
    // step 3 -> iterate over the map and make the connections
    for(auto it:m){
        Node *org=it.first;
        Node *dup=it.second;
        if(org->random!=NULL){
            Node *oran=org->random;
            Node *dupRan=m[oran];
            dup->random=dupRan;
        }
    }
    return dummy1->next;
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