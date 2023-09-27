// LEETCODE 1109-> Corporate flight bookings

#include<iostream>
#include<vector>
using namespace std;

// brute force
/* 
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> ans(n+1,0);
        int rows=bookings.size();
        int cols=bookings[0].size();
        for(int i=0;i<rows;i++){
          int start=bookings[i][0];
          int end=bookings[i][1];
          int seats=bookings[i][2];
          for(int j=start;j<=end;j++){
            ans[j]+=seats;
          }
        }
        ans.erase(ans.begin());
        return ans;
    }
*/ 

vector<int> corpflightbookings(vector<vector<int>> &v,int n){
    vector<int> ans(n+1,0);
    for(int i=0;i<v.size();i++){
        ans[v[i][0]-1]+=v[i][2];
        ans[v[i][1]]-=v[i][2];
    }
    for(int i=1;i<ans.size();i++){
        ans[i]+=ans[i-1];
    }
    return {ans.begin(),ans.end()-1};
}

int main(){
    vector<vector<int>> bookings={{1,2,10},{2,3,20},{2,5,25}};
    int n=5;
    vector<int> ans=corpflightbookings(bookings,n);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}