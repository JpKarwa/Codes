// Subsets of a string with duplicates
// left call jb chalegi jb hamara flag=true h

// hmne dekha ki left call ke right me aur right call ke left me same kaam ho rha h


#include<bits\stdc++.h>
using namespace std;

void printSubsets(string org,string ans,vector<string> &v,bool flag){
    //base case
    if(org.size()==0){
        v.push_back(ans);
        return;
    }
    char ch=org[0];
    if(org.length()==1){
        // matlab hum org[1] ko compare hi nhi krskte org[0] se
        // out of bound
        if(flag==true) printSubsets(org.substr(1),ans+ch,v,true);
        printSubsets(org.substr(1),ans,v,true);
        return;
        //taki neeche ki 2 condition na chale
    }
    char dh=org[1];
    if(ch==dh){ //duplicate
        if(flag==true) printSubsets(org.substr(1),ans+ch,v,true);
        printSubsets(org.substr(1),ans,v,false);
    }
    else{  //no duplicate
        if(flag==true) printSubsets(org.substr(1),ans+ch,v,true);
        printSubsets(org.substr(1),ans,v,true);
    }
}
int main(){
    string s="aab";
    vector<string> v;
    sort(s.begin(),s.end());
    printSubsets(s,"",v,true);
    // printSubsets1(s,"",0);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<endl;
    }
}