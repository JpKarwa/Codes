// LEETCODE 1004 -> Max consecutive ones III

#include<iostream>
#include<vector>
using namespace std;

int longestOnes(vector<int>& nums, int k) {
    int n=nums.size();
    int i=0;
    int j=0;
    int flips=0;
    int len;
    int maxLen=INT32_MIN;
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
    return maxLen;
}

int main(){
    vector<int> nums={1,1,1,0,0,0,1,1,1,1,0};
    int k=2;
    cout<<longestOnes(nums,2);
}