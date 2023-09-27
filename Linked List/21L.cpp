// LEETCODE 2058 -> Find the min and max nodes between two critical points

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

vector<int> distances(Node *head){
    Node *a=head;
    Node *b=head->next;
    Node *c=head->next->next;
    if(c==NULL) return {-1,-1};         // mean ll have only 2 nodes

    vector<int> critical;
    int idx=1;
    while(c){
        bool maxima=(b->val > a->val) && (b->val > c->val);
        bool minima=(b->val < a->val) && (b->val < c->val);
        if(maxima || minima){
            critical.push_back(idx);
        }
        a=a->next;
        b=b->next;
        c=c->next;
        idx++;
    }
    if(critical.size()<2) return {-1,-1};
    int maxd=critical[critical.size()-1]-critical[0];
    int mind=INT_MAX;
    for(int i=0;i<critical.size()-1;i++){
        int dist=critical[i+1]-critical[i];
        mind=min(dist,mind);
    }
    return {mind,maxd};
}

int main(){
    Node *a =new Node(1);
    Node *b =new Node(3);
    Node *c =new Node(2);
    Node *d =new Node(2);
    Node *e =new Node(3);
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
    vector<int> dist=distances(a);
    cout<<dist[0]<<" "<<dist[1];
}