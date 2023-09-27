// Given a square matrix change this matrix into its transpose

#include<iostream>
using namespace std;

int main(){
    int m,n;
    cout<<"Enter no. of rows:";
    cin>>m;
    cout<<"Enter no. of columns:";
    cin>>n;
    int arr[m][n];
    //Input the array
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    cout<<"Array before transpose:"<<endl;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
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
}