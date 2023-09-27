// Reorder Queue(INTERLEAVE 1st half with 2nd half)
// Do this using one stack
// queue is only of even length

// Input-> 1 2 3 4 5 6 7 8
// Ouptut-> 1 5 2 6 3 7 4 8

#include<iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

void display(queue<int> &q){
    int n=q.size();
    for(int i=0;i<n;i++){
        int x=q.front();
        cout<<x<<" ";
        q.pop();
        q.push(x);
    }
    cout<<endl;
}

void method1(queue<int> &q){
    // using array
    vector<int> arr;
    while(q.size()>0){
        arr.push_back(q.front());
        q.pop();
    }
    int n=arr.size();
    for(int i=0,j=n/2;i<n/2 && j<n;i++,j++){
        q.push(arr[i]);
        q.push(arr[j]);
    }
}

void method2(queue<int> &q){
    // using stack
    stack<int> s;
    int n=q.size();
    // push first half to stack
    for(int i=1;i<=n/2;i++){
        s.push(q.front());
        q.pop();
    }
    // push stack element to queue
    while(s.size()>0){
        q.push(s.top());
        s.pop();
    }
    // push second half of queue to stack
    for(int i=1;i<=n/2;i++){
        s.push(q.front());
        q.pop();
    }
    // take front of q and push it to end and take top of stack and push it to end
    while(s.size()>0){
        int ele1=s.top();
        q.push(ele1);
        s.pop();
        int ele2=q.front();
        q.push(ele2);
        q.pop();
    }
    // pushing queue elements to stack
    while(q.size()>0){
        s.push(q.front());
        q.pop();
    }
    // pushing all stack element to queue
    while(s.size()>0){
        q.push(s.top());
        s.pop();
    }
}

int main(){
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    q.push(7);
    q.push(8);
    q.push(9);
    q.push(10);
    display(q);
    // method1(q);
    // display(q);
    method2(q);
    display(q);
}