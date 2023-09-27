// LEETCODE 622-> Design Circular queue

#include<iostream>
#include<vector>
using namespace std;

class MyCircularQueue{
    public:
        int front;
        int rear;
        int s;         // current size
        int c;         // current capacity
        vector<int> arr;
        MyCircularQueue(int k){
            front=0;
            rear=0;
            s=0;
            c=k;
            vector<int> v(k);
            arr=v;
        }

        bool enQueue(int val){       // push back
            if(s==c) return false;
            arr[rear]=val;
            rear++;
            if(rear==c) rear=0;
            s++;
            return true;
        }

        bool deQueue(){              // pop front
            if(s==0) return false;
            front++;
            if(front==c) front=0;
            s--;
            return true;
        }     

        int Front(){
            if(s==0) return -1;
            return arr[front];
        }          

        int Rear(){
            if(s==0) return -1;
            if(rear==0) return arr[c-1];
            return arr[rear-1];
        }   

        bool isEmpty(){
            if(s==0) return true;
            else return false;
        }
    
        bool isFull(){
            if(s==c) return true;
            else return false;
        }       
};

int main(){
    MyCircularQueue myCircularQueue(3);
    cout<<myCircularQueue.enQueue(1); // return True
    cout<<myCircularQueue.enQueue(2); // return True
    cout<<myCircularQueue.enQueue(3); // return True
    cout<<myCircularQueue.enQueue(4); // return False
    cout<<myCircularQueue.Rear();     // return 3
    cout<<myCircularQueue.isFull();   // return True
    cout<<myCircularQueue.deQueue();  // return True
    cout<<myCircularQueue.enQueue(4); // return True
    cout<<myCircularQueue.Rear();     // return 4
}