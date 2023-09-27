// Check if the given array is sorted or not.

#include<iostream>
using namespace std;

int main(){
    int arr[]={1,6,2,4,7,5};
    int n=6;
    int flag=1;
    for(int i=0;i<n;i++){
        if(arr[i-1]>arr[i]){
            flag=0;
            break;
        }
    }
    if(flag==0) cout<<"Unsorted";
    else cout<<"Sorted";
}