//Given a string consist lowercase alphabets 
//print the character that is occuring most no. of time

#include<iostream>
using namespace std;

int main(){
    string s="physicswallah";
    int maxcount=0;
    char ch;
    int n=s.length();
    cout<<"----------Method 1----------"<<endl;
    //maxcount nikalne ke liye loop
    for(int i=0;i<n;i++){
        int count=1;
        for(int j=i+1;j<n;j++){
            if(s[i]==s[j]) count++;
        }
    //    cout<<s[i]<<":"<<count<<endl;
        maxcount=max(count,maxcount);
    }
    //max character print krwane ke liye
    for(int i=0;i<n;i++){
        int count=1;
        for(int j=i+1;j<n;j++){
            if(s[i]==s[j]) count++;
        }
        if(count==maxcount) cout<<s[i]<<" ";   
    }
    cout<<endl;
    
    cout<<"----------Method 2----------"<<endl;
    string st="leetcode";
    int arr[26]={0};
    for(int i=0;i<st.length();i++){
        char ch=st[i];
        int ascii=int(ch);
        int index=ascii-97;
        arr[index]+=1;
    }
    int max=0;
    for(int i=0;i<26;i++){
        if(arr[i]>max) max=arr[i];
    }
    for(int i=0;i<26;i++){
        if(arr[i]==max){
            cout<<char(i+97)<<" "<<max;
        }
    }
}