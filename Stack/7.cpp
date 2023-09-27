// Stock span problem

// Given an array where each element denotes share price on ith day
// we have to find stock span
// span ka matlab pehle se lekar kitne din tk continously vo price highest h
// apna din bhi include hoga
// span apne se previous dino ka hota h

/*
input -> [100,80,60,81,70,60,75,85]
output -> [1,1,1,3,1,1,3,7]
*/

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int> stockSpan(vector<int> &v){
    int n=v.size();
    vector<int> span(n);
    span[0]=1; // by default
    vector<int> pgei(n,-1);     // previous greatest element index array
    stack<int> s;
    s.push(0);
    // finding previous greatest element index array
    for(int i=1;i<n;i++){
        while(s.size()>0 && v[s.top()]<=v[i]) s.pop();
        if(s.size()==0) pgei[i]=-1;
        else pgei[i]=s.top();
        s.push(i);
    }
    // find the span array
    for(int i=1;i<n;i++){
        span[i]=i-pgei[i];
    }
    return span;
}
int main(){
    vector<int> arr={100,80,60,81,70,60,75,85};
    vector<int> span=stockSpan(arr);
    for(int i=0;i<span.size();i++){
        cout<<span[i]<<" ";
    }
}