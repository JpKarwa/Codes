// Find the next permutation of array
// If not possible then print the sorted order in ascending order

// LEETCODE-> NEXT PERMUTATION(31)

// Input: {1,2,4,3}
// Output: {1,3,2,4}

#include<iostream>
#include<vector>
using namespace std;

void nextPermutation(vector<int> &v){
    //Find pivot index(Jaha change ho rha h)
    int pivotIndex=-1;
    int n=v.size();
    for(int i=n-2;i>=0;i--){
        if(v[i]<v[i+1]){
            pivotIndex=i;
            break;
        }
    }
    if(pivotIndex==-1){
        //Pura array ko reverse krdo
        for(int i=0,j=n-1;i<j;i++,j--){
            int temp=v[i];
            v[i]=v[j];
            v[j]=temp;
        }
        return;
    }
    //sort the array from pivotIndex+1;
    for(int i=pivotIndex+1,j=n-1;i<j;i++,j--){
        int temp=v[i];
        v[i]=v[j];
        v[j]=temp;
    }

    //Finding just greater element from element at idx
    int justGreater=-1;
    for(int i=pivotIndex+1;i<n;i++){
        if(v[i]>v[pivotIndex]){
            justGreater=i;
            break;
        }
    }

    //swap value at pivotIndex and pivotIndex+1
    int temp=v[pivotIndex];
    v[pivotIndex]=v[justGreater];
    v[justGreater]=temp;
}


int main(){
    vector<int> v={1,2,4,3};
    nextPermutation(v);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
}