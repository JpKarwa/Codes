// Given a sorted array of non-negative distinct integers 

// Find the smallest missing non negative element in it

// arr={}
// missing -> 5,6,7,11
// but smallest -> 5

#include<iostream>
using namespace std;

int main(){
    int arr[]={0,1,3,4,6,7,8,9,11};
    int n=9;
    // for(int i=0;i<n;i++){
    //     if(i!=arr[i]){
    //         cout<<"Smallest missing non negative element :"<<i;
    //         break;
    //     }
    // }

    int lo=0,hi=n-1;
    int ans=-1;     //when there is no missing number
    while(lo<=hi){
        int mid=lo+(hi-lo)/2;

        if(arr[mid]==mid){
            lo=mid+1;
        }
        else{
            // if(arr[mid-1]==mid-1){
            //     ans=mid;
            //     break;
            // }
            // else{
            //     hi=mid-1;
            // }
            ans=mid;
            hi=mid-1;
        }
    }
    cout<<ans;
}