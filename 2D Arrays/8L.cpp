//Given an inetger numRows generate pascal triangle

// LEETCODE 118-> PASCAL's Triangle

// numsrows ki size ka 2d vector

#include<iostream>
#include<vector>
using namespace std;

int main(){
    int numRows=5;
    vector<vector<int>> v;

    for(int i=0;i<numRows;i++){
        vector<int> v1(i+1);
        v.push_back(v1);
        for(int j=0;j<=i;j++){
            if(j==0 || i==j){
                v[i][j]=1;
            }
            else{
                v[i][j]=v[i-1][j]+v[i-1][j-1];
            }
        }
    }

    for(int i=0;i<numRows;i++){
        for(int j=0;j<=i;j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
}