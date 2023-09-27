// LEETCODE 2640 -> Find the score of all the prefixes of array

#include<iostream>
#include<vector>
using namespace std;


vector<long long> findmaxScores(vector<int> &nums){
    int n=nums.size();
    vector<int> maxi(n,-1);
    maxi[0]=nums[0];
    for(int i=1;i<n;i++){
        maxi[i]=max(nums[i],maxi[i-1]);
    }

    vector<long long> ans(n,0);
    for(int i=0;i<n;i++){
        ans[i]+=nums[i]+maxi[i];
    }

    vector<long long> pref(n,-1);
    pref[0]=ans[0];
    for(int i=1;i<n;i++){
        pref[i]=ans[i]+pref[i-1];
    }

    return pref;
}

int main(){
    vector<int> nums={2,3,7,5,10};
    vector<long long> ans=findmaxScores(nums);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}