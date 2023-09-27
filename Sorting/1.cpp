//sort the string in decreasing order of values 
//associated after removal of values smaller than X


// I/p-> AZYZXBDJKX
#include<bits\stdc++.h>
using namespace std;

int main(){
    string s="AZYZXBDJKX";
    string str="";
    for(int i=0;i<s.length();i++){
        if(s[i]>='X') str.push_back(s[i]);
    }
    cout<<str;
    int n=str.length();
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(str[j]<str[j+1]) swap(str[j],str[j+1]);
        }
    }
    cout<<endl;
    cout<<str;
}