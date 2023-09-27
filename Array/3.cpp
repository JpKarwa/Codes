// Find the last index of element x in array or vector
// given a vector and element x

#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> v={1,3,2,4,3,4,1,6};
    int x=1;
    cout<<"--------Method 1--------"<<endl;
    int idx1=-1;
    for(int i=0;i<v.size();i++){
        if(v[i]==x) idx1=i;
    }
    cout<<"Last index of x is "<<idx1;
    cout<<endl;

    cout<<"--------Method 2--------"<<endl;
    int idx2=-1;
    for(int i=v.size()-1;i>=0;i--){
        if(v[i]==x){
            idx2=i;
            break;
        }
    }   
    cout<<"Last index of x is "<<idx2;  
}