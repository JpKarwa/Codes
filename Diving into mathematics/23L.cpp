// LEETCODE 713 -> Subarray product less than k

#include<iostream>
#include<vector>
using namespace std;

int numOfSubarrays(vector<int> &nums,int k){
    if(k==0 || k==1) return 0;
    int n=nums.size();
    int i=0;
    int j=0;
    int prod=1;
    int cnt=0;
    while(j<n){
        prod=prod*nums[j];
        while(prod>=k){
            cnt+=j-i;
            prod/=nums[i];
            i++;
        }
        j++;
    }
    while(i<n){
        cnt+=j-i;
        prod/=nums[i];
        i++;
    }
    return cnt;
}
int main(){
    vector<int> nums={10,5,2,6};
    int k=100;
    cout<<numOfSubarrays(nums,k);
}