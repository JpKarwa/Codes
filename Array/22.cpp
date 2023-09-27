// EK array h 0 and 1's ki 
// WAP TO find binary value of that arr

// {1,1,0,0,1,0,1}=>101

#include<iostream>
using namespace std;

int main(){
    int arr[]={1,1,0,0,1,0,1};
    int dValue=0;
    int x=1;
    for(int i=6;i>=0;i--){
        dValue+=arr[i]*x;
        x*=2;
    }
    cout<<dValue;
}