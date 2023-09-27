//Given a vector arr[] sorted in incresing order of n size and an integer x. 
// Find if there exist a pair in the array whose absolute difference is exactly x.

//Input->[5,10,15,20,26] x=10
//Output->yes


#include<iostream>
using namespace std;
int main(){
    int arr[]={5,10,15,20,26};
    int n=5;
    int x=10;

    int i=0;
    int j=1;
    while(i<n && j<n){
        if(abs(arr[i]-arr[j])==x){
            cout<<"Yes";
            return 0;
        }
        else if(abs(arr[i]-arr[j])<x){
            j++;
        }
        else{
            i++;
        }
    }
    cout<<"No";
}