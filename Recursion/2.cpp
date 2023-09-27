// Maze path

/*
Given a maze having m rows and n columns
We have to find the no. of ways to reach from (0,0) to (m-1,n-1)
We only goes down and right
*/

// Total no. of ways= right ways + down ways


#include<iostream>
using namespace std;

int maze(int sr,int sc,int er,int ec){
    //base case
    if(sr==er && sc==ec) return 1; // if we reach destination
    if(sr>er || sc>ec) return 0;   // if we escapes out

    //recursive call
    int rightWays=maze(sr,sc+1,er,ec);
    int downWays=maze(sr+1,sc,er,ec);
    int totalWays=rightWays+downWays;

    return rightWays+downWays;
}

int maze2(int er,int ec){
    //base case
    if(er==1 && ec==1) return 1; // if we reach destination
    if(er<1 || ec<1) return 0;   // if we escapes out

    //recursive call
    int rightWays=maze2(er,ec-1);
    int downWays=maze2(er-1,ec);
    int totalWays=rightWays+downWays;

    return rightWays+downWays;
}

void printPath(int sr,int sc,int er,int ec,string path){
    //base case
    if(sr>er || sc>ec) return;   // if we escapes out
    if(sr==er && sc==ec){
        cout<<path<<endl;
        return; // if we reach destination
    } 

    //recursive call
    printPath(sr,sc+1,er,ec,path+'R');
    printPath(sr+1,sc,er,ec,path+'D');
}

void printPath2(int er,int ec,string path){
    //base case
    if(er<1 || ec<1) return;   // if we escapes out
    if(er==1 && ec==1){
        cout<<path<<endl;
        return; // if we reach destination
    } 

    //recursive call
    printPath2(er,ec-1,path+'R');
    printPath2(er-1,ec,path+'D');
}

int main(){
    cout<<maze(1,1,3,4); // 3 by 3 maze
    cout<<endl;
    cout<<maze2(2,3);
    cout<<endl;
    printPath(1,1,3,4,"");
    cout<<endl;
    cout<<endl;
    printPath2(3,4,"");
}

// (m,n) and (n,m) matrix have same no. of ways