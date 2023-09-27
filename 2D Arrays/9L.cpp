// 1st step 0tH column pe 1's lane h-> jis row me initially 0 h use flip krke
// 2nd step flip the columns where noz>noo

// LEETCODE 861 ->Score After Flipping Matrix
#include<iostream>
using namespace std;

int main(){
    int arr[3][4]={{0,0,1,1},{1,0,1,0},{1,1,0,0}};

    int m=3;
    int n=4;

    //making the first columns all 1's
    for(int i=0;i<m;i++){
        if(arr[i][0]==0){
            for(int j=0;j<n;j++){
                arr[i][j]=!arr[i][j];
            }
        }
    }

    //flip the columns with more no. of zeros than ones
    for(int j=0;j<n;j++){
        int noo=0;
        int noz=0;
        for(int i=0;i<m;i++){
            if(arr[i][j]==0) noz++;
            else noo++;
        }
        if(noz>noo){
            for(int i=0;i<m;i++){
                arr[i][j]=!arr[i][j];
            }
        }
    }

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    int score=0;
    for(int i=0;i<m;i++){
        int x=1;
        for(int j=n-1;j>=0;j--){
            score+=arr[i][j]*x;
            x*=2;
        }
    }
    cout<<"Score = "<<score;
}