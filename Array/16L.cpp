//Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

// LEETCODE->TRAPPING RAIN WATER(42)
#include<iostream>
#include<vector>
using namespace std;

int trap1(vector<int>& height) {
        int n=height.size();  //no. of bulidings
        int water=0;          //to store the trapped water
        vector<int> prev(n);     //previous greatest buliding ki height ko store krne ke liye
        vector<int> next(n);     //next greatest building ki height ko store krne ke liye
        vector<int> mini(n);    //prev aur major me se chote element ki store krne ke liye

        //filling the prev vector
        prev[0]=-1;
        int max1=height[0];
        for(int i=1;i<n;i++){
            prev[i]=max1;
            if(max1<height[i]) max1=height[i];
        }

        //filling the next vector;
        next[n-1]=-1;
        int max2=height[n-1];
        for(int i=n-2;i>=0;i--){
            next[i]=max2;
            if(max2<height[i]) max2=height[i];
        }

        //filling the major vector
        for(int i=0;i<n;i++){
            if(prev[i]<next[i]) mini[i]=prev[i];
            else mini[i]=next[i];
        }

        //calculating water
        //end points pe toh pani traped hi nhi hogi;
        for(int i=1;i<n-1;i++){
            if(height[i]<mini[i]) water+=(mini[i]-height[i]);
        }

        return water;
}


int trap2(vector<int>& height) {
        int n=height.size();  //no. of bulidings
        int water=0;          //to store the trapped water
        vector<int> prev(n);     //previous greatest buliding ki height ko store krne ke liye

        //filling the prev vector
        prev[0]=-1;
        int max=height[0];
        for(int i=1;i<n;i++){
            prev[i]=max;
            if(max<height[i]) max=height[i];
        }

        //prev ko hi minimum array banadenge
        prev[n-1]=-1;
        max=height[n-1];
        for(int i=n-2;i>=0;i--){
            if(max<prev[i])  prev[i]=max;
            if(max<height[i])  max=height[i];
        }
        

        //calculating water
        //end points pe toh pani traped hi nhi hogi;
        for(int i=1;i<n-1;i++){
            if(height[i]<prev[i]) water+=(prev[i]-height[i]);
        }

        return water;
}

int main(){
    vector<int> height1={0,1,0,2,1,0,1,3,2,1,2,1};
    cout<<"--------Method 1--------"<<endl;
    int water1=trap1(height1);
    cout<<water1<<endl;
    
    vector<int> height2={4,2,0,3,2,5};
    cout<<"--------Method 2--------"<<endl;
    int water2=trap2(height2);
    cout<<water2;
}