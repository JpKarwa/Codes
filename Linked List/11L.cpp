// LEETCODE 2326 -> SPIRAL MATRIX IV

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

vector<vector<int>> spiralMatrix(Node *head,int m,int n){
    vector<vector<int>> ans(m,vector<int>(n,-1));
    if(head==NULL) return ans;

    Node *temp=head;
    int minr=0;
    int maxr=m-1;
    int minc=0;
    int maxc=n-1;
    while(minr<=maxr && minc<=maxc){
        //right
        for(int i=minc;i<=maxc;i++){
            if(temp==NULL) return ans;
            ans[minr][i]=temp->val;
            temp=temp->next;
        }
        minr++;
        if(minr>maxr || minc>maxc) break;
        //down
        for(int i=minr;i<=maxr;i++){
            if(temp==NULL) return ans;
            ans[i][maxc]=temp->val;
            temp=temp->next;
        }
        maxc--;
        if(minr>maxr || minc>maxc) break;
        //left
        for(int i=maxc;i>=minc;i--){
            if(temp==NULL) return ans;
            ans[maxr][i]=temp->val;
            temp=temp->next;
        }
        maxr--;
        //up
        if(minr>maxr || minc>maxc) break;
        for(int i=maxr;i>=minr;i--){
            if(temp==NULL) return ans;
            ans[i][minc]=temp->val;
            temp=temp->next;
        }
        minc++;
    }
    return ans;
}
int main(){
    Node *a=new Node(1);
    Node *b=new Node(2);
    Node *c=new Node(3);
    Node *d=new Node(4);
    Node *e=new Node(5);
    Node *f=new Node(6);
    Node *g=new Node(7);
    Node *h=new Node(8);
    a->next=b;
    b->next=c;
    c->next=d;
    d->next=e;
    e->next=f;
    f->next=g;
    g->next=h;

    display(a);
    cout<<endl;
    int m=3,n=4;
    vector<vector<int>> ans=spiralMatrix(a,m,n);
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}

