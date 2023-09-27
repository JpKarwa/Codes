// Push zeroes to the end while maintaing the relative order of other elements

#include<iostream>
using namespace std;

void print(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
int main(){
    int arr[]={5,0,1,2,0,0,4,0,3};
    int n=9;

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    // for(int i=0;i<n-1;i++){
    //     for(int j=0;j<n-1-i;j++){
    //         if(arr[j]==0) swap(arr[j],arr[j+1]);
    //         print(arr,n);
    //         cout<<endl;
    //     }
    //     cout<<endl;
    // }
    int i=0;
    for(int j=0;j<n;j++){
        if(arr[j]!=0) swap(arr[i++],arr[j]);
    }

    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}