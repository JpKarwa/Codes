/* You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.
Merge nums1 and nums2 into a single array sorted in non-decreasing order.
The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.
*/

// LEETCODE->MERGE SORTED ARRAY(88)

// Input:
// nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3

// Output:
// nums1=[1,2,2,3,5,6]

#include<iostream>
#include<vector>
using namespace std;

void mergeInSame(vector<int> &v1,int m,vector<int> &v2,int n){
    int i=m-1;     //v1
    int j=n-1;     //v2
    int k=m+n-1;   //v1

    while(i>=0 && j>=0){
        if(v1[i]<v2[j]){
            v1[k]=v2[j];
            j--;
        }
        else{
            v1[k]=v1[i];
            i--;
        }
        k--;
    }

    while(j>=0){
        v1[k]=v2[j];
        j--;
        k--;
    }
}

int main(){
    vector<int> nums1={4,5,6,0,0,0};
    vector<int> nums2={1,2,3};
    int m=3,n=3;

    mergeInSame(nums1,m,nums2,n);

    for(int i=0;i<m+n;i++){
        cout<<nums1[i]<<" ";
    }
}