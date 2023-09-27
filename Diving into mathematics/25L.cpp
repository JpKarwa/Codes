// LEETCODE 2302 -> Count Subarray with score less than k

#include<iostream>
#include<vector>
using namespace std;

#define ll long long

ll countSubarrays(vector<int> &nums,ll k){
    int n=nums.size();
    int i=0;
    int j=0;
    ll sums=0;
    ll cnt=0;
    ll score=0;
    while(j<n){
        sums+=nums[j];
        int len=j-i+1;
        score=sums*len;
        while(score>=k){
            sums=sums-nums[i];
            i++;
            score=sums*(j-i+1);
        }
        cnt+=(j-i+1);
        j++;
    }
    return cnt;
}

int main(){
    vector<int> nums={2,1,4,3,5};
    int k=10;
    cout<<countSubarrays(nums,k);
}