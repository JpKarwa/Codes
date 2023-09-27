// Leetcode 455 -> Assign Cookies

// Cookies ko aise distribute krna h ki jya se jyada child ko de pau

/*
greed=[2,3,1]
cookies=[3,2,1]
o/p=3

greed=[10,9,8,7]
cookies=[5,6,7,8]
o/p=2

greed=[16,15,14,7]
cookies=[5,6,7,8,9,15,14,13,10,16]
o/p=4
*/

#include<bits\stdc++.h>
using namespace std;

int main(){
    vector<int> g={16,15,14,7};
    vector<int> s={5,6,7,8,9,15,14,13,10,16};

    sort(g.begin(),g.end());
    sort(s.begin(),s.end());

    int maxChild=0;
    int i=0;     //greed array
    int j=0;     //cookies array

    while(i<g.size() && j<s.size()){
        if(s[j]>=g[i]){
            maxChild++;
            i++;
            j++;
        }
        else{
            j++;
        }
    }

    cout<<maxChild<<endl;
}