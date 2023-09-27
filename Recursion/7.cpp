// Print all the subsets of string

#include<iostream>
using namespace std;

void printSubsets(string org,string ans){
    //base case
    if(org.size()==0){
        cout<<ans<<endl;
        return;
    }
    printSubsets(org.substr(1),ans+org[0]);
    printSubsets(org.substr(1),ans);
}

void printSubsets1(string org,string ans,int idx){
    //base case
    if(idx==org.size()){
        cout<<ans<<endl;
        return;
    }
    printSubsets1(org,ans+org[idx],idx+1);  //ek baar character add krrhe h
    printSubsets1(org,ans,idx+1);           // ek baar khali rkh rhe h
}


int main(){
    string s="abc";
    printSubsets(s,"");
    // printSubsets1(s,"",0);

}