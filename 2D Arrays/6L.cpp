// WAP to print spiral of 2D array

/*

1 2 3
4 5 6
7 8 9  

Output-> 1 2 3 6 9 8 7 4 5
*/

// LEETCODE 54-> Spiral Matrix

#include<iostream>
using namespace std;

int main(){
    int m;
    cout<<"Enter rows of matrix:";
    cin>>m;
    int n;
    cout<<"Enter columns of matrix:";
    cin>>n;

    cout<<"Enter elements of matrix:"<<endl;
    int a[m][n];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }

    cout<<"Matrix is:"<<endl;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<"Spiral print method 1:";
    int minr=0;
    int maxr=m-1;
    int minc=0;
    int maxc=n-1;
    while(minr<=maxr && minc<=maxc){
        //right
        for(int j=minc;j<=maxc;j++){
            cout<<a[minr][j]<<" ";
        }
        minr++;
        //down
        if(minr>maxr || minc>maxc) break;
        for(int i=minr;i<=maxr;i++){
            cout<<a[i][maxc]<<" ";
        }
        maxc--;
        //left
        if(minr>maxr || minc>maxc) break;
        for(int j=maxc;j>=minc;j--){
            cout<<a[maxr][j]<<" ";
        }
        maxr--;
        //up
        if(minr>maxr || minc>maxc) break;
        for(int i=maxr;i>=minr;i--){
            cout<<a[i][minc]<<" ";
        }
        minc++;
    }
    cout<<endl;

    cout<<"Spiral print Method 2:";
    int minrow=0;
    int maxrow=m-1;
    int mincol=0;
    int maxcol=n-1;
    int count=0;
    int totalelements=n*m;
    while(minrow<=maxrow && mincol<=maxcol){
        //right
        for(int j=mincol;j<=maxcol && count<totalelements;j++){
            cout<<a[minrow][j]<<" ";
            count++;
        }
        minrow++;
        //down
        for(int i=minrow;i<=maxrow && count<totalelements;i++){
            cout<<a[i][maxcol]<<" ";
            count++;
        }
        maxcol--;
        //left
        for(int j=maxcol;j>=mincol && count<totalelements;j--){
            cout<<a[maxrow][j]<<" ";
            count++;
        }
        maxrow--;
        //up
        for(int i=maxrow;i>=minrow && count<totalelements;i--){
            cout<<a[i][mincol]<<" ";
            count++;
        }
        mincol++;
    }
}