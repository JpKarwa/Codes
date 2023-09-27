// LEETCODE 1814 -> Count nice pairs of array

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int rev(int n){
    int temp=0;
    while(n!=0){
        temp=(temp*10)+(n%10);
        n=n/10;
    }
    return temp;
}


int method1(vector<int> &v){
    int n=v.size();
    int cnt=0;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(v[i]+rev(v[j])==v[j]+rev(v[i])) cnt++;
        }
    }
    return cnt;
}

int method2(vector<int> &v){
    int n=v.size();
    int cnt=0;
    unordered_map<int,int> m;
    for(int i=0;i<n;i++){
        int temp=v[i]-rev(v[i]);
        m[i]=temp;
    }
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(m[i]==m[j]) cnt++;
        }
    }
    return cnt;
}

int method3(vector<int> &v){
    int n=v.size();
    int cnt=0;
    unordered_map<int,int> m;
    for(int i=0;i<n;i++){
        int temp=v[i]-rev(v[i]);
        if(m.find(temp)==m.end()) m[temp]++;
        else{
            cnt=cnt%1000000007;
            cnt+=m[temp];
            m[temp]++;
        }
    }
    return cnt%1000000007;
}

int main(){
    vector<int> nums={42,11,1,97};    
    cout<<method1(nums)<<endl;
    cout<<method2(nums)<<endl;
    cout<<method3(nums)<<endl;
}