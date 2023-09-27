// Count Inversion

/*
Two element of an array a, a[i] and a[j] form an inversion if a[i]>a[j] and i<j.
Given an array of integers. Find the inversion count in array
*/

#include<bits\stdc++.h>
using namespace std;

int countInversionIn2SortedArray(vector<int> &a,vector<int> &b){
    int inversion=0;
    int i=0,j=0;
    while(i<a.size() && j<b.size()){
        if(a[i]>b[j]){
            inversion+=a.size()-i;
            j++;
        }
        else{
            i++;
        }
    }
    return inversion;
}

void mergeTwoSorted(vector<int> &a,vector<int> &b,vector<int> &c){
    int i=0;  // for a
    int j=0;  // for b
    int k=0;  // for c
    while(i<a.size() && j<b.size()){
        if(a[i]<=b[j]) c[k++]=a[i++];
        else c[k++]=b[j++];
    }
    while(i<a.size()) c[k++]=a[i++];
    while(j<b.size()) c[k++]=b[j++];
}

int countInversion(vector<int> &v){
    int count=0;
    int n=v.size();
    if(n==1) return 0;
    vector<int> a,b;
    for(int i=0;i<n/2;i++) a.push_back(v[i]);
    for(int i=n/2;i<n;i++) b.push_back(v[i]);

    //magical recursion
    count+=countInversion(a);
    count+=countInversion(b);

    //check inversion count
    count+=countInversionIn2SortedArray(a,b);

    //merge 2 sorted array
    mergeTwoSorted(a,b,v);
    a.clear();
    b.clear();
    return count;
}

int main(){
    vector<int> arr={5,1,8,2,3};  //4+1+1+1
    cout<<countInversion(arr);
}
// int brute(vector<int> arr){
//     int n=arr.size();
//     int inversion=0;
//     for(int i=0;i<n-1;i++){
//         for(int j=i+1;j<n;j++){
//             if(arr[i]>arr[j]) inversion++;
//         }
//     }
//     return inversion;
//     // Order of n square
// }