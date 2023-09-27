// Rotate the array 'a' by k steps,where k is non negative
// Note: k can be greater than n as well where n is size of array 'a'

#include<iostream>
#include<vector>
using namespace std;

void reversePart(int i,int j,vector<int> &v){
    while(i<=j){
        int temp=v[i];
        v[i]=v[j];
        v[j]=temp;
        i++;
        j--;
    }
}

int main(){
    vector<int> v={1,6,2,3,7,4,8};
    int k=4; //steps to rotate

    int n=v.size();

    if(k>n) k=k%n;

    reversePart(0,n-k-1,v);
    reversePart(n-k,n-1,v);
    reversePart(0,n-1,v);

    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }
}