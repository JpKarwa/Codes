/*
Sort the array of strings using bubble sort

arr={"raghav","sanket","harsh","urvi","vishwa"}

arr={"harsh","raghav","sanket","urvi","vishwa"}

*/
#include<iostream>
#include<string>
using namespace std;

int main(){
    string name[9]={"raghav","sanket","harsh","urvi","vishwa","manvi","hyder","priya","sudhanshu"};
    int n=9;
    for(int i=0;i<n;i++){
        cout<<name[i]<<endl;
    }
    cout<<endl;
    for(int i=0;i<n-1;i++){
        bool swapping=false;
        for(int j=0;j<n-1-i;j++){
            if(name[j]>name[j+1]){
                swap(name[j],name[j+1]);
                swapping=true;
            }
        }
        if(swapping==false) break;
        // cout<<endl;
    }

    for(int i=0;i<n;i++){
        cout<<name[i]<<endl;
    }
}