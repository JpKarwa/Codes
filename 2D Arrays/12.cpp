// WAP TO PRINT sum of each row and column after that row and column

#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int arr[10][10]={{1,2,3,4},{5,6,7,8},{9,10,11,12}};

    for(int i=0;i<4;i++){
        for(int j=0;j<5;j++){
            cout<<arr[i][j]<<"\t";
        }
        cout<<endl;
    }
    int r=3,c=4;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            arr[i][c]+=arr[i][j];
            arr[r][j]+=arr[i][j];
        }
    }
    cout<<endl;
    for(int i=0;i<=r;i++){
        for(int j=0;j<=c;j++){
            if(i==r && j==c){
                cout<<" ";
                return 0;
            }
            cout<<arr[i][j]<<"\t";
        }
        cout<<endl;
    }
}
