//Given an array, predict if the array contains duplicates or not.

#include<iostream>
using namespace std;

int main(){
    int arr[6]={1,2,3,1,5,1};
    bool flag=0;
    for(int i=0;i<5;i++){
        for(int j=i+1;j<6;j++){
            if(arr[i]==arr[j]){
                flag=1;
                break;
            }
        }
    }
    if(flag==1) cout<<"Duplicates toh h";
    else cout<<"Duplicates nhi h";
}