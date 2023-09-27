// LEETCODE 1290 -> Convert binary number in a linked list to integer

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

int decimal(Node *head){
    vector<int> num;
    while(head){
        num.push_back(head->val);
        head=head->next;
    }
    int ans=0;
    int n=num.size();
    int x=1;
    for(int i=n-1;i>=0;i--){
        ans=ans+(num[i]*x);
        x=x*2;
    }
    return ans;
}

int main(){
    Node *a=new Node(1);
    Node *b=new Node(0);
    Node *c=new Node(1);
    a->next=b;
    b->next=c;

    display(a);
    cout<<endl;
    cout<<decimal(a);
}