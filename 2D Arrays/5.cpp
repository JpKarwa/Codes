// WAP to print the matrix in wave form

/*
1 2 3
4 5 6
7 8 9


output 1= 1 2 3 6 5 4 7 8 9
output 2= 3 2 1 4 5 6 9 8 7
output 3= 7 8 9 6 5 4 1 2 3
output 4= 1 4 7 2 5 8 3 6 9
output 5= 1 4 7 8 5 2 3 6 9 
*/
#include<iostream>
using namespace std;

int main(){
    int a[3][3]={1,2,3,4,5,6,7,8,9};

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<"Wave print 1"<<endl;
    for(int i=0;i<3;i++){  
        if(i%2==0){ // 0 2
            for(int j=0;j<3;j++){
                cout<<a[i][j]<<" ";
            }
        }
        else{ // 1
            for(int j=2;j>=0;j--){
                cout<<a[i][j]<<" ";
            }
        }
    }
    cout<<endl;
    cout<<"Wave print 2:"<<endl;
    for(int i=0;i<3;i++){ 
        if(i%2==0){ //0 2
            for(int j=2;j>=0;j--){
                cout<<a[i][j]<<" ";
            }
        }
        else{  // 1
            for(int j=0;j<3;j++){
                cout<<a[i][j]<<" ";
            }
        }
    }
    cout<<endl;
    cout<<"Wave print 3:"<<endl;
    for(int i=2;i>=0;i--){ //0 2 4 
        if(i%2==0){
            for(int j=0;j<3;j++){
                cout<<a[i][j]<<" ";
            }
        }
        else{
            for(int j=2;j>=0;j--){
                cout<<a[i][j]<<" ";
            }
        }
    }
    cout<<endl;
    cout<<"Column wise printing 1:"<<endl;
    for(int j=0;j<3;j++){ 
        for(int i=0;i<3;i++){
            cout<<a[i][j]<<" ";
        }
    }
    cout<<endl;
    cout<<"Column wise printing 2:"<<endl;
    for(int j=0;j<3;j++){ 
        if(j%2==0){
            for(int i=0;i<3;i++){
                cout<<a[i][j]<<" ";
            }
        }
        else{
            for(int i=2;i>=0;i--){
                cout<<a[i][j]<<" ";
            }
        }
    }
}