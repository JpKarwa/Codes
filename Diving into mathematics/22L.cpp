// LEETCODE 1493 -> Longest Subarray of 1's after deleting one element

#include<iostream>
#include<vector>
using namespace std;

int longestSubarray(vector<int>& nums) {
    int n=nums.size();
    int i=0;
    int j=0;
    int flips=0;
    int len;
    int maxLen=INT32_MIN;
    int k=1;
    while(j<n){
        if(nums[j]==1) j++;
        else{
            if(flips<k){
                flips++;
                j++;
            }
            else{ // nums[j]=0 and flips>=k
                len=j-i;
                maxLen=max(maxLen,len);
                // i ko us window ke pehle zero ke ek index aage le aao
                // us zero ko unflip krdo
                while(nums[i]==1) i++;  // after that we sure that nums[i] is now 0
                i++; // now our i is at 1
                j++;
            }
        }
    }
    len=j-i;
    maxLen=max(maxLen,len);        
    return maxLen-1;
}

int longestsubarray(vector<int> &nums){
    int n=nums.size();
    int zeroPos=-1;
    int i=0;
    int j=0;
    int maxlen=0;
    int count=0;
    while(j<n){
        int prev=zeroPos;
        if(nums[j]==0){
            count++;
            zeroPos=j;
        }
        if(count<=1) j++;
        else{
            maxlen=max(maxlen,j-i);
            i=prev+1;
            count--;
            j++;
        }
    }
    maxlen=max(maxlen,j-i);
    return maxlen-1;
}

int main(){
    vector<int> nums={0,1,1,1,0,1,1,0,1};
    cout<<longestSubarray(nums)<<" "<<longestsubarray(nums);
}