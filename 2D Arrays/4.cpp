//WAP To print matrix multiplication of matrix entered by user

#include<iostream>
using namespace std;

int main(){
    int m,n;
    cout<<"Enter row of 1st matrix:";
    cin>>m;
    cout<<"Enter column of 1st matrix:";
    cin>>n;

    int p,q;
    cout<<"Enter row of 2nd matrix:";
    cin>>p;
    cout<<"Enter columns of 2nd matrix:";
    cin>>q;

    if(n==p){
        int a[m][n];
        cout<<"Enter elements of 1st matrix:";
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                cin>>a[i][j];
            }
        }
        int b[p][q];
        cout<<"Enter elements of 2nd matrix:";
        for(int i=0;i<p;i++){
            for(int j=0;j<q;j++){
                cin>>b[i][j];
            }
        }

        //resultant matrix
        int c[m][q];
        for(int i=0;i<m;i++){
            for(int j=0;j<q;j++){
                c[i][j]=0;
                // multiplication
                // res[i][j]=a[i][0]*b[0][j]+a[i][1]*b[1][j]+....... upto p
                for(int k=0;k<p;k++){
                    c[i][j]+=a[i][k]*b[k][j];
                }
            }
        }


        cout<<"Mutliplicated matrix:"<<endl;
        for(int i=0;i<m;i++){
            for(int j=0;j<q;j++){
                cout<<c[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    else{
        cout<<"The matrices cannot be multiplied";
    }
}