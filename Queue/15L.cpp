// LEETCODE 225 -> Implement stack using queues

#include<iostream>
#include<queue>
using namespace std;
class MyStack {
public:
    queue<int> q1;
    queue<int> q2;
    MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        while(q1.size()>1){
            q2.push(q1.front());
            q1.pop();
        }
        int x=q1.front();
        q1.pop();
        while(q2.size()){
            q1.push(q2.front());
            q2.pop();
        }
        return x;
    }
    
    int top() {
        return q1.back();
    }
    
    bool empty() {
        if(q1.size()!=0) return false;
        else return true;
    }
};

// using one queue
class MyStack1 {
public:
    queue<int> q;
    MyStack1() {
        
    }
    
    void push(int x) {
        q.push(x);
    }
    
    int pop() {
        int n=q.size();
        for(int i=1;i<n;i++){
            int x=q.front();
            q.pop();
            q.push(x);
        }
        int x=q.front();
        q.pop();
        return x;
    }
    
    int top() {
        return q.back();
    }
    
    bool empty() {
        if(q.size()!=0) return false;
        else return true;
    }
};

int main(){
    MyStack myStack;
    myStack.push(1);
    myStack.push(2);
    cout<<myStack.top(); // return 2
    cout<<myStack.pop(); // return 2
    cout<<myStack.empty(); // return False

    MyStack1 myStack1;
    myStack1.push(1);
    myStack1.push(2);
    cout<<myStack1.top(); // return 2
    cout<<myStack1.pop(); // return 2
    cout<<myStack1.empty(); // return False
}