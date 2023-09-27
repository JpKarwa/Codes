// Sort 0's, 1's and 2's

// Leetcode-> SORT COLORS(75)

#include<iostream>
#include<vector>
using namespace std;

void sort1(vector<int> &v){
    int n=v.size();
    int noz=0,noo=0,notwo=0; //to store count of 0's,1's and 2's
    for(int i=0;i<n;i++){
        if(v[i]==0) noz++;
        else if(v[i]==1) noo++;
        else notwo++;
    }
    //filling elements
    for(int i=0;i<n;i++){
        if(i<noz) v[i]=0;
        else if(i<noz+noo) v[i]=1;
        else v[i]=2;
    }
}

void sort2(vector<int> &v){
    int n=v.size();
    int low=0;
    int mid=0;
    int high=n-1;
    while(mid<high){
        if(v[mid]==0){
            swap(v[mid],v[low]);
            //mid kbhi bhi low se piche nhi rahega
            low++;
            mid++;
        }
        if(v[mid]==2){
            swap(v[mid],v[high]);
            high--;
        }
        if(v[mid]==1) mid++;
    }
}

int main(){
    vector<int> v1={2,0,2,1,1,0};
    cout<<"--------Method 1---------"<<endl;
    sort1(v1);
    for(int i=0;i<v1.size();i++){
        cout<<v1[i]<<" ";
    }
    cout<<endl;
    vector<int> v2={2,0,2,1,1,0};
    cout<<"--------Method 1---------"<<endl;
    sort2(v2);
    for(int i=0;i<v2.size();i++){
        cout<<v2[i]<<" ";
    }
}