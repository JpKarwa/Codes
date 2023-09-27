// Given an array
// find the length of longest subarray
// which has maximum possible and value

// bitwise and maximum jb aayega tb sb bit same h
// nhi toh value choti hoti jayegi

#include<iostream>
#include<vector>
using namespace std;
int main(){
    int arr[]={12,3,1,6,1,6,6,6,6,4,3,8,13,13,13,13,8};
    int n=17;
    int ans=0;
    int maxe=INT32_MIN;
    int cnt=0;
    for(int i=0;i<n;i++){
        if(arr[i]>maxe){
            maxe=arr[i];
            cnt=1;
        }
        else if(arr[i]==maxe){
            cnt++;
        }
        ans=max(ans,cnt);
    }
    cout<<ans;
}