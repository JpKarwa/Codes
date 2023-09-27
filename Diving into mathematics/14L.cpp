// LEETCODE 724 -> Find Pivot

#include<iostream>
#include<vector>
using namespace std;

int pivotIndex(vector<int> &v){
    int n=v.size();
    vector<int> pre(n,-1);
    vector<int> suf(n,-1);
    
    pre[0]=v[0];
    for(int i=1;i<n;i++){
        pre[i]=v[i]+pre[i-1];
    }
    suf[n-1]=v[n-1];
    for(int i=n-2;i>=0;i--){
        suf[i]=v[i]+suf[i+1];
    }

    for(int i=0;i<n;i++){
        if(pre[i]==suf[i]) return i;
    }
    return -1;
}

int main(){
    vector<int> nums={1,7,3,6,5,6};
    cout<<pivotIndex(nums);
}