#include<iostream>
using namespace std;

int main(){
    int arr[]={1,2,2,3,3,3,3,3,4,4,5,8,9};
    int n=13;
    int s=0;
    int e=n-1;
    int x=2;
    int ans=-1;
    // while(s<=e){
    //     int mid=s+(e-s)/2;
    //     if(arr[mid]==x){
    //         ans=mid;
    //         e=mid-1;
    //     }
    //     else if(arr[mid]<x){
    //         s=mid+1;
    //     }
    //     else{
    //         e=mid-1;
    //     }
    // }

    while(s<=e){
        int mid=s+(e-s)/2;
        if(arr[mid]==x){
            if(arr[mid-1]==x) e=mid-1;
            else{
                ans=mid;
                break;
            }
        }
        else if(arr[mid]<x){
            s=mid+1;
        }
        else{
            e=mid-1;
        }
    }
    cout<<ans;
}