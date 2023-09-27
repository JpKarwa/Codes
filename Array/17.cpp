//Given a vector arr[] sorted in incresing order of n size and an integer x. Find if there exist a pair in the array whose sum is exactly x.

// Input->[-1,0,1,2,3] x=2
// Output-> Yes

#include <iostream>
using namespace std;
int main() {
    int arr[]={-1,0,1,2,3};
    int n=5;
    int x=2;
    int i=0,j=n-1;
    while(i<j){
        if(arr[i]+arr[j]<x){
            i++;
        }
        else if(arr[i]+arr[j]>x){
            j--;
        }
        else{
            cout<<"Yes";
            return 0;
        }
    }
    cout<<"No";
}