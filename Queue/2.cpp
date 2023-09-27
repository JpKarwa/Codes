// Remove all the elements present at even positions in queue. Consider 0-based indexing

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

void removeEven(queue<int> &q){
    int n=q.size();
    for(int i=0;i<n;i++){
        if(i%2==0) q.pop();
        else{
            int x=q.front();
            q.pop();
            q.push(x);
        }
        // if(i%2!=0){
        //     int x=q.front();
        //     q.push(x);
        // }
        // q.pop();
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
    removeEven(q);
    display(q);
}