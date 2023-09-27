// Remove kth element from top of stack

#include<iostream>
#include<stack>
using namespace std;

void removeKthElement(int k,stack<int> &s){
    stack<int> temp;
    int i=1;
    while(i<k){
        temp.push(s.top());
        s.pop();
        i++;
    }
    s.pop();
    while(temp.size()){
        s.push(temp.top());
        temp.pop();
    }
}

void topToBottom(stack<int> st){
    while(st.size()){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
}

int main(){
    stack<int>st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    topToBottom(st);
    removeKthElement(3 , st);
    topToBottom(st);
}