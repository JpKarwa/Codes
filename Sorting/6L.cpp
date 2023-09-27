// Leetcode 169 -> Majority element (169)

/*
nums=[3,2,3]
o/p = 3

nums = [2,1,1,2,2,2]
o/p = 2
*/

#include<bits\stdc++.h>
using namespace std;

int main(){
    int n=6;
    vector<int> arr={2,1,1,2,2,2};
    sort(arr.begin(),arr.end());
    cout<<arr[n/2];
}