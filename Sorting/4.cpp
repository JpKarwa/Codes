/*
arr={5,1,3,4,2}
hme is array ke digits se banne wala 2 minimum number nikalne h jinka sum minimum ho (saare digits ko use lena h)
ex-> 51342 ye ek number h jo array ke digits se ban rha h
513 => 5+1+3+4+2 =15 (aise sum nikalne)


sum minimum ke liye no. bhi minimum hone chahiye
toh sbse pehle array ko sort krenge
arr={1,2,3,4,5}
smallest number=>12345
second number=>12354

arr={5,1,5,5,2,3}
arr={1,2,3,5,5,5}
smallest number=>123555
second number=>125355
*/

#include<iostream>
using namespace std;

int main(){
    int arr[6]={5,1,5,5,2,3};
    int n=6;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
    //sort the array
    for(int i=1;i<n;i++){
        for(int j=i;j>=1;j--){
            if(arr[j]<arr[j-1]){
                swap(arr[j],arr[j-1]);
            }
            else{
                break;
            }
        }
    }

    //minimum number
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    //storing the array into integer
    int smallestNumber=0;
    for(int i=0;i<n;i++){
        smallestNumber=smallestNumber*10+arr[i];
    }
    cout<<smallestNumber<<endl;

    for(int i=n-1;i>0;i--){
        if(arr[i]!=arr[i-1]){
            swap(arr[i],arr[i-1]);
            break;
        }   
    }
    
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    //storing the array into integer
    int secondSmallest=0;
    for(int i=0;i<n;i++){
        secondSmallest=secondSmallest*10+arr[i];
    }
    cout<<secondSmallest<<endl;

    cout<<"Minimum possible sum="<<smallestNumber+secondSmallest<<endl;
}