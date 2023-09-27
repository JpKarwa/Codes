// Given an integer array where every element occur twice except one occur only one
// find unique element

// xor is cummutative
#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> arr={2,1,3,2,1,5,5,6,3};
    int ans=0;
    for(int i=0;i<arr.size();i++){
        ans^=arr[i];
    }
    cout<<ans;
}