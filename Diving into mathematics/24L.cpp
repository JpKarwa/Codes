// LEETCODE 1343 -> Number of subarrays of size k and average greater than or equal to threshold

#include<iostream>
#include<vector>
using namespace std;

int totalSubarrays(vector<int> &nums,int k,int threshold){
    int n=nums.size();
    int sums=0;
    for(int i=0;i<k;i++){
        sums+=nums[i];
    }
    int cnt=0;
    if(sums>=k*threshold) cnt+=1;
    int i=1;
    int j=k;
    while(j<n){
        sums+=nums[j]-nums[i-1];
        if(sums>=k*threshold) cnt++;
        j++;
        i++;
    }
    return cnt;
}

int main(){
    vector<int> arr={2,2,2,2,5,5,5,8};
    int k=3;
    int th=4;
    cout<<totalSubarrays(arr,k,th);
}