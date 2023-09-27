// Find all the permutation of an string given all the 
// elements of all string are unique

// for n size string permutations are factorial(n)


#include<iostream>
using namespace std;

void permutations(string org,string ans){

    if(org.size()==0){
        cout<<ans<<endl;
        return;
    }
    for(int i=0;i<org.size();i++){
        // if(i==0) permutations(org.substr(i+1),ans+org[i]);
        // else if(i==org.size()-1) permutations(org.substr(0,org.size()-1),ans+org[i]);
        // else permutations(org.substr(0,i)+org.substr(i+1),ans+org[i]);
        char ch=org[i];
        string left=org.substr(0,i);   //left subtring
        string right=org.substr(i+1);  //right substring
        permutations(left+right,ans+ch);
    }
}
int main(){
    string s="abc";
    // cout<<s.substr(0,1)+s.substr(2);
    permutations(s,"");
}

// substr(a,b)-> here a is starting index and b is length of substring