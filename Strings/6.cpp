// Input string and return the number of substring that contain only vowels

#include<iostream>
#include<string>
using namespace std;

int main(){
    string s="acdeeiofg";
    int ans=0;
    int count=0;
    for(int i=0;i<s.length();i++){
        if(s[i]=='a' || s[i]=='e' || s[i]=='i' ||  s[i]=='o' || s[i]=='u'){
            count++;
        }
        else{
            //previous jo the unke liye substring count krlo
            ans+=count*(count+1)/2;
            count=0;
        }
    }
    cout<<ans;
}