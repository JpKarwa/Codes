// Leetcode 725 -> Split list in parts

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

vector<Node*> splitIntoParts(Node *head,int k){
    vector<Node*> ans;
    // find the length of linked list
    int n=0;
    Node *temp=head;
    while(temp!=NULL){
        temp=temp->next;
        n++;
    }
    int sizeOfEachPart=n/k;
    int rem=n%k;
    temp=head;
    while(temp){
        Node *c=new Node(100);
        Node *tc=c;
        int s=sizeOfEachPart;
        if(rem>0) s++;
        rem--;
        for(int i=1;i<=s;i++){
            tc->next=temp;
            temp=temp->next;
            tc=tc->next;
        }
        tc->next=NULL;
        ans.push_back(c->next);
    }
    if(ans.size()<k){
        int extra=k-ans.size();
        for(int i=1;i<=extra;i++){
            ans.push_back(NULL);
        }
    }
    return ans;
}

int main(){
    Node *a =new Node(1);
    Node *b =new Node(2);
    Node *c =new Node(3);
    Node *d =new Node(4);
    Node *e =new Node(5);
    Node *f =new Node(6);
    Node *g =new Node(7);
    Node *h =new Node(8);
    Node *i =new Node(9);
    Node *j =new Node(10);
    Node *l =new Node(11);
    a->next=b;
    b->next=c;
    c->next=d;
    d->next=e;
    e->next=f;
    f->next=g;
    g->next=h;
    h->next=i;
    i->next=j;
    j->next=l;
    int k=3;
    vector<Node*> ans=splitIntoParts(a,k);
    for(int i=0;i<ans.size();i++){
        display(ans[i]);
        cout<<endl;
    }
}