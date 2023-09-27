/*

Replace with 0 to n-1

nums=[19,12,23,8,16]
o/p=> [3,1,4,0,2]
*/

#include<bits\stdc++.h>
using namespace std;

int main(){
   int arr[]={19,12,-23,8,16};
   int n=5;
   vector<int> visited(n,0);      //0 means not visited
   int x=0;
   for(int i=0;i<n;i++){
        int min=INT32_MAX;
        int minIdx=-1;
        for(int j=0;j<n;j++){
            if(visited[j]==1) continue;
            else if(arr[j]<min && visited[j]==0){
                min=arr[j];
                minIdx=j;
            }
        }
        arr[minIdx]=x;
        visited[minIdx]=1;
        x++;
    }

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

//TC=O(n_square)
//SC=O(n)