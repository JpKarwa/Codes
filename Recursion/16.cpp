// Generate all binary strings of length n without consecutive 1's

#include<iostream>
using namespace std;

void bString(string s,int n){
    if(s.size()==n){
        cout<<s<<" ";
        return;
    }
    bString(s+'0',n);
    if(s[s.size()-1]=='0' || s.size()==0) bString(s+'1',n);
}
int main(){
    int n=3;
    bString("",3);
}

// no. of binary string is power(2,n)