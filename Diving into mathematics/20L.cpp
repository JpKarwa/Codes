// LEETCODE 209 -> Minimum Size Subaary Sum

#include<iostream>
#include<vector>
using namespace std;

int minSizeSubarraySum1(vector<int> &v,int target){
    int n=v.size();
    int minSize=INT32_MAX;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int sums=0;
            for(int k=i;k<=j;k++){
                sums+=v[k];
            }
            if(sums>=target){
                minSize=min(minSize,j-i+1);
            }
        }
    }
    if(minSize==INT32_MAX) return 0;
    return minSize;
}

int minSizeSubarraySum2(vector<int> &v,int target){
    int n=v.size();
    int minSize=INT32_MAX;
    for(int i=0;i<n;i++){
        int sums=0;
        for(int j=i;j<n;j++){
            sums+=v[j];
            if(sums>=target){
                minSize=min(minSize,j-i+1);
                break;
            }
        }
    }
    if(minSize==INT32_MAX) return 0;
    return minSize;
}

// int minSubArrayLen(int target, vector<int>& nums) {
//     int n=nums.size();
//     int minLen=INT_MAX;
//     int i=0;
//     int j=0;
//     int sum=0;
//     while(j<n){
//         sum+=nums[j];
//         if(sum<target) j++;
//         else{
//             sum=0;
//             minLen=min(minLen,j-i+1);
//             i++;
//             j=i;
//         }
//     }
//     if(minLen==INT_MAX) return 0;
//     return minLen;
// }

int minSizeSubarraySum3(vector<int> nums,int target){
    int n=nums.size();
    int i=0;
    int j=0;
    int sum=0;
    int minLen=INT32_MAX;
    while(j<n){
        sum+=nums[j];
        while(sum>=target){
            int len=j-i+1;
            minLen=min(len,minLen);
            sum-=nums[i];
            i++;
        }
        j++;
    }
    // maxto max j pura array ek baar hi travel krega
    // ops 2*n se less than hi rhenge
    if(minLen==INT32_MAX) return 0;
    return minLen;

    // j jaha pe bhi ruk rha vha me saare i's ke sath use check kr rha hu using while loop
}

int main(){
    vector<int> nums={2,3,1,2,4,3};
    int target=7;
    cout<<minSizeSubarraySum1(nums,target)<<endl;
    cout<<minSizeSubarraySum2(nums,target)<<endl;
    cout<<minSizeSubarraySum3(nums,target)<<endl;
}