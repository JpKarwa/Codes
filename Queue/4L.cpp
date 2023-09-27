#include<iostream>
#include<vector>
using namespace std;

class MyCircularDeque{
    public:
        int front;
        int rear;
        int s;      // current size
        int c;      // capacity
        vector<int> arr;

        MyCircularDeque(int k){
            front=0;
            rear=0;
            s=0;
            c=k;
            vector<int> v(k);
            arr=v;
        }

        bool insertFront(int value){
            if(s==c) return false;
            if(front==0) front=c-1;
            else front--;
            arr[front]=value;
            s++;
            return true;       
        }

        bool insertLast(int value){
            if(s==c) return false;
            arr[rear]=value;
            rear++;
            if(rear==c) rear=0;
            s++;
            return true;
        }

        bool deleteFront(){
            if(s==0) return false;
            if(front==c-1) front=0;
            else front++;
            s--;
            return true;
        }

        bool deleteLast(){
            if(s==0) return false;
            if(rear==0) rear=c-1;
            else rear--;
            s--;
            return true;
        }

        int getFront(){
            if(s==0) return -1;
            return arr[front];
        }

        int getRear(){
            if(s==0) return -1;
            if(rear==0) return arr[c-1];
            return arr[rear-1];
        }

        bool isEmpty() {
            if(s==0) return true;
            else return false;
        }
    
        bool isFull() {
            if(s==c) return true;
            else return false;
        }
};

int main(){
    MyCircularDeque myCircularDeque(3);
    cout<<myCircularDeque.insertLast(1);  // return True
    cout<<myCircularDeque.insertLast(2);  // return True
    cout<<myCircularDeque.insertFront(3); // return True
    cout<<myCircularDeque.insertFront(4); // return False, the queue is full.
    cout<<myCircularDeque.getRear();      // return 2
    cout<<myCircularDeque.isFull();       // return True
    cout<<myCircularDeque.deleteLast();   // return True
    cout<<myCircularDeque.insertFront(4); // return True
    cout<<myCircularDeque.getFront();     // return 4
}