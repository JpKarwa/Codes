// LEETCODE 85 -> Maximal rectangle

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int largestRectangleArea(vector<int> &heights){
    int n=heights.size();
    vector<int> nsei(n,n);
    vector<int> psei(n,-1);
    // making next smaller element index array
    stack<int> st;
    st.push(n-1);
    for(int i=n-2;i>=0;i--){
        while(st.size()>0 && heights[st.top()]>=heights[i]) st.pop();
        if(st.size()!=0) nsei[i]=st.top();
        st.push(i);
    }
    // making prev smaller element index array
    stack<int> gt;
    gt.push(0);
    for(int i=1;i<n;i++){
        while(gt.size()>0 && heights[gt.top()]>=heights[i]) gt.pop();
        if(gt.size()!=0) psei[i]=gt.top();
        gt.push(i);
    }
    // calculating max area
    int maxArea=-1;
    for(int i=0;i<n;i++){
        int breadth=nsei[i]-psei[i]-1;
        int area=heights[i]*breadth;
        maxArea=max(maxArea,area);
    }
    return maxArea;
}

int maximalRectangle(vector<vector<string>> &v){
    int maxArea=-1;
    int m=v.size();
    int n=v[0].size();
    vector<int> temp(n,0);
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(v[i][j]=="1") temp[j]++;
            else temp[j]=0;
        }
        maxArea=max(maxArea,largestRectangleArea(temp));
    }
    return maxArea;
}

int main(){
    vector<vector<string>> matrix={
        {"1","0","1","0","0"},
        {"1","0","1","1","1"},
        {"1","1","1","1","1"},
        {"1","0","0","1","0"}
    };
    cout<<maximalRectangle(matrix);
}