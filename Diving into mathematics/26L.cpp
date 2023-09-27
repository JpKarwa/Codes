// LEETCODE 1248 -> Count number of nice subarray

#include<iostream>
#include<vector>
using namespace std;

int countNiceSubarray(vector<int> &nums,int k){
    int n=nums.size();
    int i=0;
    int j=0;
    int oddCnt=0;
    int cnt=0;
    int ans=0;
    while(j<n){
        if(nums[j]%2){
            oddCnt++;
            cnt=0;
        }
        while(oddCnt>=k){
            cnt++;
            if(nums[i]%2) oddCnt--;
            i++;
        }
        ans+=cnt;
        j++;
    }
    return ans;
}

int main(){
    vector<int> nums={1,1,2,1,1};
    int k=3;
    cout<<countNiceSubarray(nums,k);
}