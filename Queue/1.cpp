// Reverse the queue using stack

#include<iostream>
#include<queue>
#include<stack>
using namespace std;

void display(queue<int> &q){
    int n=q.size();
    int i=0;
    for(int i=1;i<=n;i++){
        int x=q.front();
        cout<<x<<" ";
        q.pop();
        q.push(x);
    }
    cout<<endl;
}

void reverse(queue<int> &q){
    stack<int> s;
    //empty the queue into stack
    while(q.size()>0){
        int x=q.front();
        s.push(x);
        q.pop();
    }
    // empty the stack into queue
    while(s.size()>0){
        int x=s.top();
        q.push(x);
        s.pop();
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
    reverse(q);
    display(q);
}