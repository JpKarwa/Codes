// LEETCODE 84 -> Largest Rectangle in Histogram

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int largestRectangleArea(vector<int> &heights){
    int n=heights.size();
    vector<int> nsei(n,n);
    vector<int> psei(n,-1);
    int maxArea=-1;
    // making next smallest element index array
    stack<int> s1;
    s1.push(n-1);
    for(int i=n-2;i>=0;i--){
        while(s1.size()>0 && heights[s1.top()]>=heights[i]) s1.pop();
        if(s1.size()==0) nsei[i]=n;
        else nsei[i]=s1.top();
        // if(s1.size()!=0) nsei[i]=s1.top();
        s1.push(i);
    }

    // making previous smallest element index array
    stack<int> s2;
    s2.push(0);
    for(int i=1;i<n;i++){
        while(s2.size()>0 && heights[s2.top()]>=heights[i]) s2.pop();
        if(s2.size()==0) psei[i]=-1;
        else psei[i]=s2.top();
        // if(s2.size()!=0) psei[i]=s2.top();
        s2.push(i);
    }

    // finding area
    for(int i=0;i<n;i++){
        int breadth=nsei[i]-psei[i]-1;
        int area=heights[i]*breadth;
        maxArea=max(area,maxArea);
    }
    return maxArea;
}
int main(){
    vector<int> heights={2,1,5,6,2,3};
    cout<<largestRectangleArea(heights);
}