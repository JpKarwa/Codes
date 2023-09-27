// LEETCODE 658 -> Find k closest elements

#include<bits\stdc++.h>
using namespace std;

vector<int> findKclosestElements(vector<int> &arr,int k,int x){
    //find the x in array
    int n=arr.size();

    vector<int> ans(k);
    if(x<arr[0]){
        // vector me starting ke k elements ko push krna h
        for(int i=0;i<k;i++){
            ans[i]=arr[i];
        }
        return ans;
    }

    if(x>arr[n-1]){
        int i=n-1;    //for given array
        int j=k-1;   //for ans array
        while(j>=0){
            ans[j]=arr[i];
            j--;
            i--;
        }
        return ans;
    }

    int lo=0;
    int hi=n-1;
    int mid=-1;
    bool flag=false;  //if x is present or not
    int t=0;          //representing current index of ans
    while(lo<=hi){
        mid=lo+(hi-lo)/2;
        
        if(arr[mid]==x){
            flag=true;
            ans[t]=arr[mid];
            t++;
            break;
        }
        else if(arr[mid]<x) lo=mid+1;
        else hi=mid-1;
    }
    int lb=hi;
    int ub=lo;
    if(flag==true){
        lb=mid-1;
        ub=mid+1;
    }
    while(t<k && lb>=0 && ub<=n-1){
        int d1=abs(x-arr[lb]);
        int d2=abs(x-arr[ub]);
        if(d1<d2){
            ans[t]=arr[lb];
            lb--;
        }
        else if(d1==d2){
            if(arr[lb]<arr[ub]){
                ans[t]=arr[lb];
                lb--;
            }
            else{
                ans[t]=arr[ub];
                ub++;
            }
        }
        else{
            ans[t]=arr[ub];
            ub++;
        }
        t++;
    }
    if(lb<0){
        while(t<k){
            ans[t]=arr[ub];
            ub++;
            t++;
        }
    }
    if(ub>n-1){
        while(t<k){
            ans[t]=arr[lb];
            lb--;
            t++;
        }
    }
    sort(ans.begin(),ans.end());
    return ans;
}
int main(){
    vector<int> arr={1,2,3,4,6};
    vector<int> ans=findKclosestElements(arr,4,3);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}

/*
SC -> O(k)
TC -> O(logn) + O(k) + O(klogk) -> O(logn + klogk)
O(logn) -> binary search
O(k) -> for inserting elements in ans vector
O(klogk) -> for sorting k size of vector in worst case
*/