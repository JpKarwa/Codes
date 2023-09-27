// LEETCODE 232 -> Implement Queue using stacks

#include<iostream>
#include<stack>
using namespace std;

// class MyQueue{
//     // push efficient approach 
//     // Push->O(1)
//     // Pop/Peek ->O(n)
//     public:
//         stack<int> s;
//         MyQueue(){

//         }

//         void push(int val){
//             s.push(val);
//         }

//         int pop(){
//             // remove at bottom
//             stack<int> t;
//             while(s.size()>0){
//                 t.push(s.top());
//                 s.pop();
//             }
//             int x=t.top();
//             t.pop();
//             while(t.size()>0){
//                 s.push(t.top());
//                 t.pop();
//             }
//             return x;
//         }

//         int peek(){
//             // remove at bottom
//             stack<int> t;
//             while(s.size()>0){
//                 t.push(s.top());
//                 s.pop();
//             }
//             int x=t.top();
//             while(t.size()>0){
//                 s.push(t.top());
//                 t.pop();
//             }
//             return x;
//         }

//         bool empty(){
//             return !s.size();
//         }
// };

class MyQueue{
    // pop efficient approach 
    // POP/PEEK -> O(1)
    // Push -> O(n)
    public:
        stack<int> s;
        MyQueue(){

        }

        void push(int val){
            if(s.size()==0){
                s.push(val);
                return;
            }
            stack<int> t;
            while(s.size()>0){
                t.push(s.top());
                s.pop();
            }
            s.push(val);
            while(t.size()>0){
                s.push(t.top());
                t.pop();
            }
        }

        int pop(){
            // remove at top
            int x=s.top();
            s.pop();
            return x;
        }

        int peek(){
            // return at top of stack
            return s.top();
        }

        bool empty(){
            return !s.size();
        }
};

int main(){
    MyQueue myQueue;
    myQueue.push(1); // queue is: [1]
    myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)
    cout<<myQueue.peek(); // return 1
    cout<<myQueue.pop(); // return 1, queue is [2]
    cout<<myQueue.empty(); // return false
}