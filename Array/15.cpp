// WAP to make previousGreatestElementArray and nextGreatestElementArray in the array

#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> v={0,1,0,2,1,0,1,3,2,1,2,1};
    vector<int> previousGreatest(v.size());
    vector<int> nextGreatest(v.size());

    //previousGreatest
    int max1=v[0];
    previousGreatest[0]=-1;
    for(int i=1;i<v.size();i++){
        previousGreatest[i]=max1;
        if(max1<v[i]) max1=v[i];
    }

    for(int i=0;i<previousGreatest.size();i++){
        cout<<previousGreatest[i]<<" ";
    }
    cout<<endl;

    //nextGreatest
    int n=nextGreatest.size();
    int max2=v[n-1];
    nextGreatest[n-1]=-1;
    for(int i=n-2;i>=0;i--){
        nextGreatest[i]=max2;
        if(max2<v[i]) max2=v[i];
    }
    for(int i=0;i<nextGreatest.size();i++){
        cout<<nextGreatest[i]<<" ";
    }
    cout<<endl;
}