// WAP to find the smallest missing positive element in the sorted Array that contains only positive elements.

// arr={-4,-2,0,2,3,5,6,7}
// Output=1

#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> arr={-4,-2,0,2,3,5,6,7};
    int x=1; //smallest positive element
    for(int i=0;i<arr.size();i++){
        if(arr[i]<=0) continue;
        else if(arr[i]>x){
            //means x is missing
            cout<<x;
            break;
        }
        else x++;
    }
}