// Find the first non repeating element of array


#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> v={2,1,2,3,4,4};
    int n=v.size();
    for(int i=0;i<n-1;i++){
        bool flag=false;
        for(int j=i+1;j<n;j++){
            if(v[i]==v[j]){
                flag=true;
                break;
            }
        }
        if(flag==false){
            cout<<v[i];
            break;
        }
    }

    return 0;
}