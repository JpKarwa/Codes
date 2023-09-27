// Reverse of stack

#include<bits\stdc++.h>
using namespace std;

void topToBottom(stack<int> st){
    while(st.size()){
        cout<<st.top()<<" ";
        st.pop();
    }
}

int main(){
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    topToBottom(st);
    cout<<endl;

    // Method 1 -> using 2 more stacks  O(n) both time and space
    stack<int> gt;
    stack<int> rt;
    // empty gt to st
    while(st.size()){
        gt.push(st.top());
        st.pop();
    }
    // empty gt to rt
    while(gt.size()){
        rt.push(gt.top());
        gt.pop();
    }
    while(rt.size()){
        st.push(rt.top());
        rt.pop();
    }
    topToBottom(st);
    cout<<endl;
    
    // Method 2 -> using an array
    vector<int> arr;
    while(st.size()){
        arr.push_back(st.top());
        st.pop();
    }
    while(arr.size()){
        st.push(arr.back());
        arr.pop_back();
    }
    topToBottom(st);
}