// Given an array nums in which exactly 2 element
// appear only once and all other element appear twice
// find two number that appear only once

#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> arr={1,2,1,3,2,5};
    int ans=0;
    for(int i=0;i<arr.size();i++){
        ans^=arr[i];
    }
    int k=0;
    int temp=ans;
    // find set bit and store it in k
    while(true){
        if(temp&1==1){
            break;
        }
        temp=temp>>1;
        k++;
    }
    int retval=0;
    // check the number whose kth bit is set
    // ek hi number hoga
    for(int i=0;i<arr.size();i++){
        int num=arr[i];
        if(((num>>k)&1)==1) retval^=num;
    }
    int num1=retval;
    int num2=retval^ans;
    cout<<num1<<" "<<num2;
}