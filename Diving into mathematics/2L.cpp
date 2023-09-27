// Leetcode 238 -> Product of array except self


#include<iostream>
#include<vector>
using namespace std;

vector<int> productExceptSelf(vector<int> nums) {
    int n=nums.size();
    vector<int> pref(n,1);
    vector<int> suff(n,1);
    // pref me nums[i] se pehle ke product pref[i] me aa rha h
    for(int i=1;i<n;i++){
        pref[i]=pref[i-1]*nums[i-1];
    }
    // suff[i] me nums[i] ke baad ka product aa rha h
    for(int i=n-2;i>=0;i--){
        suff[i]=suff[i+1]*nums[i+1];
    }
    for(int i=0;i<n;i++){
        nums[i]=pref[i]*suff[i];
    }
    return nums;
}

vector<int> productExceptSelfOptimised(vector<int>& nums) {
    int n=nums.size();
    vector<int> pref(n,1);
    vector<int> suff(n,1);
    // pref me nums[i] se pehle ke product pref[i] me aa rha h
    for(int i=1;i<n;i++){
        pref[i]=pref[i-1]*nums[i-1];
    }
    // suff[i] me nums[i] ke baad ka product aa rha h
    int p=nums[n-1];
    for(int i=n-2;i>=0;i--){
        pref[i]*=p;
        p*=nums[i];
    }
    return pref;
}

int main(){
    vector<int> v={1,2,3,4};
    vector<int> v1=productExceptSelf(v);
    vector<int> v2=productExceptSelf(v);
    for(int i=0;i<v1.size();i++){
        cout<<v1[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<v2.size();i++){
        cout<<v2[i]<<" ";
    }
}