// LEETCODE 852 -> Peak index in mountain array

#include<iostream>
using namespace std;

int peakInMountainArray(int arr[],int n){
    int lo=1;
    int hi=n-2;

    // first aur last element toh peak ho nhi skta kyoki array 3 length ki h aur mountain bhi h
    while(lo<=hi){
        int mid=lo+(hi-lo)/2;

        if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1]) return mid;
        else if(arr[mid]>arr[mid+1]) hi=mid-1;
        else lo=mid+1;
    }

    return -1;
}

int main(){
    int arr[]={1,3,5,4,3,2,0};
    int n=7;

    cout<<peakInMountainArray(arr,n);
}