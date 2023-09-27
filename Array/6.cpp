// WAP to reverse the array without using extra array

#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> v={1,2,3,4,5,6,7};
    cout<<"Before reversing"<<endl;
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;

    //main code(two pointers)
    int i=0;
    int j=v.size()-1;
    while(i<j){
        //swap v[i] and v[j];
        int temp=v[i];
        v[i]=v[j];
        v[j]=temp;
        i++;
        j--;
    }

    cout<<"After reversing"<<endl;
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }

    //using for loop
    for(int i=0,j=v.size()-1;i<=j;i++,j--){
        int temp=v[i];
        v[i]=v[j];
        v[j]=temp;
    }
    cout<<endl;

    cout<<"After reversing again"<<endl;
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
}
