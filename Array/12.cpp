// Merge two sorted arrays by making new array

// Input:
// arr1={1,4,5,8}
// arr2={2,3,6,7,10}

//Output:
// arr={1,2,3,4,5,6,7,8,10}

#include<iostream>
#include<vector>
using namespace std;

vector<int> merge1(vector<int> &v1,vector<int> &v2){
    int m=v1.size();
    int n=v2.size();
    vector<int> ans(m+n);
    int i=0; //v1
    int j=0; //v2
    int k=0; //ans

    while(i<m && j<n){
        if(v1[i]<v2[j]){
            ans[k]=v1[i];
            i++;
        }
        else{
            ans[k]=v2[j];
            j++;
        }
        k++;
    }
    //remaining elements of v1 and v2
    while(i<m){
        ans[k]=v1[i];
        i++;
        k++;
    }
    while(j<n){
        ans[k]=v2[j];
        j++;
        k++;
    }
    return ans;
}

vector<int> merge2(vector<int> &v1,vector<int> &v2){
    int m=v1.size();
    int n=v2.size();
    vector<int> ans(m+n);
    int i=m-1; //v1
    int j=n-1; //v2
    int k=m+n-1; //ans

    while(i>=0 && j>=0){
        if(v1[i]<v2[j]){
            ans[k]=v2[j];
            j--;
        }
        else{
            ans[k]=v1[i];
            i--;
        }
        k--;
    }
    // remaining elements of v1 and v2
    if(i==0) ans[k]=v1[i];
    if(j==0) ans[k]=v2[j];
    return ans;
}

int main(){
    cout<<"--------Method 1--------"<<endl;
    vector<int> arr1={1,4,5,8};
    vector<int> arr2={2,3,6,7,10};
    vector<int> v=merge1(arr1,arr2);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    cout<<"--------Method 2--------"<<endl;
    vector<int> arr3={1,4,5,8};
    vector<int> arr4={2,3,6,7,10};
    vector<int> v_new=merge2(arr1,arr2);
    for(int i=0;i<v_new.size();i++){
        cout<<v_new[i]<<" ";
    }
}