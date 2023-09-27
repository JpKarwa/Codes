// Remove last k elements of queue

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

void reverseLastK(queue<int> &q,int k){
    int n=q.size();
    // push n-k element to the end of queue
    for(int i=1;i<=n-k;i++){
        int x=q.front();
        q.pop();
        q.push(x);
    }
    for(int i=1;i<=k;i++){
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
    reverseLastK(q,3);
    display(q); 
}