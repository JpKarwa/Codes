// Leetcode 39 -> Combination sum

/*
Given an array of distinct integers candidates 
and a target integer target, 
return a list of all unique combinations of candidates 
where the chosen numbers sum to target. 
You may return the combinations in any order.
*/ 
#include<bits\stdc++.h>
using namespace std;

void combination(vector<int>arr,vector<int>ans,int n, int target,int idx){
    if(target==0){
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
        return;
    }
    if(target<0) return;
    for(int i=idx;i<n;i++){
        ans.push_back(arr[i]);
        combination(arr,ans,n,target-arr[i],i);
        ans.pop_back();
    }
}

int main(){
    vector<int> arr={2,3,5};
    vector<int> v;
    combination(arr,v,3,8,0);
}