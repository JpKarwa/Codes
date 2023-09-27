// LEETCODE 303 -> Range Sum Query Immuatable

#include<iostream>
#include<vector>
using namespace std;

class NumArray{
    public: 
        vector<int> pref;
        NumArray(vector<int> &nums){
            int n=nums.size();
            vector<int> v(n,0);
            pref=v;
            pref[0]=nums[0];
            for(int i=1;i<n;i++){
                pref[i]=pref[i-1]+nums[i];
            }
        }

        int sumRange(int left,int right){
            if(left==0) return pref[right];
            return pref[right]-pref[left-1];
        }
};

int main(){
    vector<int> nums={-2, 0, 3, -5, 2, -1};
    NumArray numArray(nums);
    cout<<numArray.sumRange(0, 2); // return (-2) + 0 + 3 = 1
    cout<<numArray.sumRange(2, 5); // return 3 + (-5) + 2 + (-1) = -1
    cout<<numArray.sumRange(0, 5); // return (-2) + 0 + 3 + (-5) + 2 + (-1) = -3
}