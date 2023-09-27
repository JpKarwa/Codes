// LEETCODE 21 -> MERGE 2 SORTED LISTS

#include<bits\stdc++.h>
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

Node* MergeList1(Node *list1,Node *list2){
    Node* dummy=new Node(-1);
    Node* tc=dummy;
    Node* ta=list1;
    Node* tb=list2;
    while(ta!=NULL && tb!=NULL){
        if(ta->val<=tb->val){
            Node *temp=new Node(ta->val);
            tc->next=temp;
            tc=temp;
            ta=ta->next;
        }
        else{
            Node *temp=new Node(tb->val);
            tc->next=temp;
            tc=temp;
            tb=tb->next;
        }
    }
    if(ta==NULL){
        tc->next=tb;
    }
    else{
        tc->next=ta;
    }
    return dummy->next;
}

Node* MergeList2(Node *a,Node *b){
    Node* dummy=new Node(-1);
    Node* tc=dummy;
    while(a!=NULL && b!=NULL){
        if(a->val<=b->val){
            tc->next=a;
            tc=tc->next;
            a=a->next;
        }
        else{
            tc->next=b;
            tc=tc->next;
            b=b->next;
        }
    }
    if(a==NULL){
        tc->next=b;
    }
    else{
        tc->next=a;
    }
    return dummy->next;

    // O(1) space
}

int main(){
    Node *a=new Node(1);
    Node *b=new Node(2);
    Node *c=new Node(4);
    Node *A=new Node(1);
    Node *B=new Node(3);
    Node *C=new Node(4);
    a->next=b;
    b->next=c;
    
    A->next=B;
    B->next=C;

    display(a);
    cout<<endl;
    display(A);
    cout<<endl;

    Node *ans1=MergeList1(a,A);
    display(ans1);
    cout<<endl;
    Node *ans2=MergeList2(a,A);
    display(ans2);
}