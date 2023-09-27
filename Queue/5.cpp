// Reverse first k element of queue

#include<iostream>
#include<queue>
#include<stack>
using namespace std;

void display(queue<int> &q){
    int n=q.size();
    for(int i=1;i<=n;i++){
        int x=q.front();
        cout<<x<<" ";
        q.pop();
        q.push(x);
    }
    cout<<endl;
}

void reverseFirstK(queue<int> &q,int k){
    int n=q.size();
    stack<int> s;
    // pushing the first k elements to stack
    for(int i=1;i<=k;i++){
        int x=q.front();
        s.push(x);
        q.pop();
    }
    // pushing the elements from stack to q
    while(s.size()>0){
        int x=s.top();
        q.push(x);
        s.pop();
    }
    // pushing n-k element to end
    for(int i=1;i<=n-k;i++){
        int x=q.front();
        q.push(x);
        q.pop();
    }
}

int main(){
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    display(q);
    reverseFirstK(q,3);
    display(q); 
}