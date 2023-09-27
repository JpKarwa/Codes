// LEETCODE 155 -> Min Stack

#include<iostream>
#include<vector>
#include<stack>
#include<climits>
#define ll long long
using namespace std;

// method 1
// class MinStack {
// public:
//     stack<int> st;
//     MinStack() {

//     }
    
//     void push(int val) {
//         st.push(val);
//     }
    
//     void pop() {
//         st.pop();
//     }
    
//     int top() {
//         return st.top();
//     }
    
//     int getMin() {
//         stack<int> helper;
//         int mn=INT_MAX;
//         while(st.size()>0){
//             mn=min(mn,st.top());
//             helper.push(st.top());
//             st.pop();
//         }
//         while(helper.size()>0){
//             st.push(helper.top());
//             helper.pop();
//         }
//         return mn;
//     }
//     // TC-> O(N)
//     // SC-> O(N)
// };

// method 2 
// class MinStack {
// public:
//     stack<int> st;
//     stack<int> helper;
//     MinStack() {

//     }
    
//     void push(int val) {
//         st.push(val);
//         if(helper.size()==0 || val<helper.top()) helper.push(val);
//         else helper.push(helper.top());
//     }
    
//     void pop() {
//         st.pop();
//         helper.pop();
//     }
    
//     int top() {
//         return st.top();
//     }
    
//     int getMin() {
//         return helper.top();
//     }
//    TC-> O(1)  
//    SC->O(N)
// };

// method 3
// class MinStack {
// public:
//     vector<int> v;
//     MinStack() {

//     }
    
//     void push(int val) {
//         v.push_back(val);
//     }
    
//     void pop() {
//         v.pop_back();
//     }
    
//     int top() {
//         return v[v.size()-1];
//     }
    
//     int getMin() {
//         int mn=INT_MAX;
//         for(int i=0;i<v.size();i++){
//             mn=min(mn,v[i]);
//         }
//         return mn;
//     }
// };


// method 4
class MinStack{
    public:
        stack<ll> s;
        ll mn;
        MinStack(){
            mn=LLONG_MAX;
        }
        void push(int val){
            ll x=(ll)val;
            if(s.size()==0){
                s.push(x);
                mn=x;
            }
            else if(x>=mn) s.push(x);
            else{
                int farzi=2*x-mn;
                s.push(farzi);
                mn=x;
            }
        }
        void pop(){
            if(s.top()<mn){
                long long old_min=2*mn-s.top();
                mn=old_min;
            }
            s.pop();
        }
        int top(){
            if(s.top()<mn) return (int)mn;
            else return (int)s.top();
        }
        int getMin(){
            return int(mn);
        }
};

int main(){
    MinStack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    cout<<minStack.getMin()<<endl; // return -3
    minStack.pop();
    cout<<minStack.top()<<endl;    // return 0
    cout<<minStack.getMin()<<endl; // return -2
}

/*
 val<min;
 val-min<0;
 val+val-min<val;
 */

 /*
 2*min-old_min=st.top();
 */