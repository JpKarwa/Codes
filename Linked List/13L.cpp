// LEETCODE 23 -> Merge K Sorted Lists

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

// Node* mergeKLists(vector<Node*> lists){
//     if(lists.size()==0) return NULL;
//     while(lists.size()!=1){
//         Node* list1=lists[lists.size()-1];
//         lists.pop_back();
//         Node* list2=lists.back();
//         lists.pop_back();
//         Node* res=MergeList2(list1,list2);
//         lists.push_back(res);
//     }
//     return lists[0];
// }
// Suppose there are k lists 
// each LL has an average n elements
// hm har 2 lists ko merge krte h toh no. of operation 2n 
// toh ek LL bani jisme 2n elements h
// phir ye agle LL se merge hogi toh 2n + n toh 3n elements lagenge
// aise krte krte 3n,4n,5n,6n,....,Kn
// operation -> 2n+3n+4n+......+kn=O(n.k_square)


// suppose n=8 total ops=35n

Node* mergeKListsOptimised(vector<Node*> lists){
    if(lists.size()==0) return NULL;
    while(lists.size()!=1){
        Node* list1=lists[0];
        lists.erase(lists.begin());
        Node* list2=lists[0];
        lists.erase(lists.begin());
        Node* res=MergeList2(list1,list2);
        lists.push_back(res);
    }
    return lists[0];
    // O(n.KlogK)
    // O(k) space
}

int main(){
    Node *a=new Node(1);
    Node *b=new Node(2);
    Node *c=new Node(5);
    Node *A=new Node(1);
    Node *B=new Node(3);
    Node *C=new Node(4);
    Node *X=new Node(2);
    Node *Y=new Node(6);
    a->next=b;
    b->next=c;
    
    A->next=B;
    B->next=C;

    X->next=Y;
    display(a);
    cout<<endl;
    display(A);
    cout<<endl;
    display(X);
    cout<<endl;

    vector<Node*> lists={a,A,X};
    // Node* ans=mergeKLists(lists);
    // display(ans);
    // cout<<endl;
    vector<Node*> lists2={a,A,X};
    Node *ansOpt=mergeKListsOptimised(lists2);
    display(ansOpt);
}