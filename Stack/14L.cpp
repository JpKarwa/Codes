// LEETCODE 1475 -> Final Prices with special discount in a shop

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int> finalPrices(vector<int> &v){
    int n=v.size();
    // finding next smaller element array
    vector<int> nse(n,0);
    stack<int> s;
    s.push(v[n-1]);
    for(int i=n-2;i>=0;i--){
        while(s.size()>0 && s.top()>v[i]) s.pop();
        if(s.size()!=0) nse[i]=s.top();
        s.push(v[i]);
    }
    for(int i=0;i<n;i++){
        v[i]-=nse[i];
    }
    return v;
}

int main(){
   vector<int> prices={8,4,6,2,3};
   vector<int> discounted=finalPrices(prices);
   for(int i=0;i<discounted.size();i++){
    cout<<discounted[i]<<" ";
   }
}