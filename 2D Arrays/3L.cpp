// WAP to rotate the square matrix by 90 degrees clockwise

// LEETCODE 48 -> ROTATE IMAGE

#include<iostream>
#include<math.h>
using namespace std;

int main(){
    int m,n;
    cout<<"Enter no. of rows and columns:";
    cin>>m;
    int arr[m][m];
    //Input the array
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    cout<<"Array before rotation:"<<endl;
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    for(int i=0;i<m;i++){
        for(int j=0;j<i;j++){
            int temp=arr[i][j];
            arr[i][j]=arr[j][i];
            arr[j][i]=temp;
        }
    }
    cout<<"Array after transpose:"<<endl;
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<"Reverse each row of transposed matrix:"<<endl;
    for(int i=0;i<m;i++){
        int s=0;
        int e=m-1;
        while(s<=e){
            // swapping (i,s) & (i,e)
            int temp=arr[i][s];
            arr[i][s]=arr[i][e];
            arr[i][e]=temp;
            s++;
            e--;
        }
    }

    cout<<"Array after rotate 90 degree:"<<endl;
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}