// LEETCODE 1823-> Find the winner of the circular game

#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int winner1(int n,int k){
    queue<int> q;
    for(int i=1;i<=n;i++){
        q.push(i);
    }

    while(q.size()>1){
        int count=1;
        while(count<k){
            count++;
            q.push(q.front());
            q.pop();
        }
        q.pop();
    }
    return q.front();
}

void solve(queue<int> &q,int k){
    if(q.size()==1) return;
    int count=1;
    while(count<k){
        count++;
        q.push(q.front());
        q.pop();
    }
    q.pop();
    solve(q,k);
}

int winner2(int n,int k){
    queue<int> q;
    for(int i=1;i<=n;i++){
        q.push(i);
    }
    solve(q,k);
    return q.front();
}

int winner3(int n,int k){
    int ans=0;
    for(int i=1;i<=n;i++){
        ans=(ans+k)%i;
    }
    return ans+1;
}

int main(){
    int n=5,k=2;
    cout<<winner1(n,k);
    cout<<winner2(n,k);
    cout<<winner3(n,k);
}