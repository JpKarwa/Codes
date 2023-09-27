// LEETCODE 350 -> Intersection of two arrays

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> intersection(vector<int> &a,vector<int> &b){
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    vector<int> v;
    int n=a.size();
    int m=b.size();
    int i=0,j=0;
    while(i<n && j<m){
        if(a[i]<b[j]) i++;
        else if(a[i]>b[j]) j++;
        else if(a[i]==b[j]){
            v.push_back(a[i]);
            i++;
            j++;
        }
    }
    return v;
}

int main(){
    vector<int> nums1={1,2,2,1};
    vector<int> nums2={2,2};
    vector<int> v=intersection(nums1,nums2);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
}