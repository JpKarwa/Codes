// WAP to copy the contents of one array into another in reverse order

#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int>v={1,2,3,4,5,6,7,8};
    vector<int> v1(v.size());
    for(int i=0;i<=v.size();i++){
        v1[i]=v[v.size()-i-1];
    }
    for(int i=0;i<v1.size();i++){
        cout<<v1[i]<<" ";
    }
}