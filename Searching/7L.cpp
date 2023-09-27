#include<iostream>
using namespace std;

// if mid=0 toh mid-1 calculate nhi krskte (out of bound)
// if mid=n-1 toh mid+1 calculate nhi krskte
// If array is already sorted then you won't find pivot element

int binarySearch(int arr[],int lo,int hi,int x){
    while(lo<=hi){
        int mid=lo+(hi-lo)/2;

        if(arr[mid]==x) return mid;
        else if(arr[mid]>x) hi=mid-1;
        else lo=mid+1;
    }
    return -1;
}

int searchInRotatedSortedArray(int arr[],int target,int n){
    //finding pivot
    if(n==2){
        if(target==arr[0]) return 0;
        else if(target==arr[1]) return 1;
        else return -1;
    }
        
    int lo=0;
    int hi=n-1;
    int pivotIdx=-1;

    int ans=-1;
    while(lo<=hi){
        int mid=lo+(hi-lo)/2;

        if(mid==0) lo=mid+1;
        else if(mid==n-1) hi=mid-1;
        else if(arr[mid]<arr[mid-1] && arr[mid]<arr[mid+1]){
            pivotIdx=mid;
            break;
        }
        else if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1]){
            pivotIdx=mid+1;
            break;
        }
        else if(arr[mid]>arr[hi]) lo=mid+1;
        else if(arr[mid]<arr[hi]) hi=mid-1;
    }

    if(pivotIdx==-1){   //array already sorted or decreasing sorted if size is 2
        ans=binarySearch(arr,0,n-1,target);
    }
    if(target>=arr[0] && target<=arr[pivotIdx-1]){
        //binary search on first half
        ans=binarySearch(arr,0,pivotIdx-1,target);
    }
    else{
        ans=binarySearch(arr,pivotIdx,n-1,target);
    }

    return ans;
}

int main(){
    int arr[]={4,5,6,7,0,1,2};
    int target=6;
    int n=7;
    cout<<searchInRotatedSortedArray(arr,target,n);
}