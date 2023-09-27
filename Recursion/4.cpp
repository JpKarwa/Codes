// Max value of an array using recursion

#include<iostream>
#include<climits>
using namespace std;

void printMax(int arr[],int size,int idx,int maximum){
    if(idx==size){
        // index size tk ja chuka h means main pure array ko travel kr chuka hu toh ab maximum print krwado 
        cout<<maximum;
        return;
    } 
    if(arr[idx]>maximum) maximum=arr[idx];
    printMax(arr,size,idx+1,maximum);
}

int storeMax(int arr[],int size,int idx){
    if(idx==size) return INT_MIN;
    return max(arr[idx],storeMax(arr,size,idx+1));
}
int main(){
    int arr[]={-1,0,1,3,2,5};
    printMax(arr,6,0,INT_MIN);;
}