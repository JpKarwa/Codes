//Move all zeros to the end of the array.

#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> v={2,0,0,1,0,2,0,65};
    int n=v.size();
    int i=0;
    int j=n-1;

    while(i<=j){
        if(v[i]==0 && v[j]!=0){
            swap(v[i],v[j]);
            i++;
            j--;
        }
        else if(v[i]!=0) i++;
        else if(v[j]==0) j--;
    }
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }
}