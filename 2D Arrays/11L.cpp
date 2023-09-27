/* Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.
 */

// LEETCODE 73-> SET MATRIX ZEROES

#include <iostream>
#include<vector>
using namespace std;

void setZeroes(vector<vector<int>> &matrix){
    int rows = matrix.size();
    int cols = matrix[0].size();

    vector<vector<int>> v(rows, vector<int>(cols));
    v = matrix;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (matrix[i][j] == 0)
            {
                for (int t = 0; t < rows; t++)
                    v[t][j] = 0;
                for (int p = 0; p < cols; p++)
                    v[i][p] = 0;
            }
        }
    }
    matrix = v;
}

void setZeroes1(vector<vector<int>>& matrix) {
        int rows=matrix.size();
        int cols=matrix[0].size();

        vector<int> v1(rows,0); 
        vector<int> v2(cols,0);
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(matrix[i][j]==0){
                    v1[i]=1;
                    v2[j]=1;
                }
            }
        }

        //change the matrix
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(v1[i]==1 || v2[j]==1){
                    matrix[i][j]=0;
                }
            }
        }
}

void setZeroes2(vector<vector<int>>& matrix) {
        int rows=matrix.size();
        int cols=matrix[0].size();
        bool flag=0;
        for(int i=0;i<rows;i++){
            if(matrix[i][0]==0) flag=1;
            for(int j=1;j<cols;j++){
                if(matrix[i][j]==0){
                    matrix[0][j]=matrix[i][0]=0;
                }
            }
        }

        //change the matrix
        for(int i=rows-1;i>=0;i--){
            for(int j=cols-1;j>0;j--){
                if(matrix[i][0]==0 || matrix[0][j]==0) matrix[i][j]=0;
            }
            if(flag) matrix[i][0]=0;
        }
    }

int main(){
    vector<vector<int>> matrix={{1,1,1},{1,0,1},{1,1,1}};
    cout<<"---------Method 1----------"<<endl;
    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[0].size();j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    setZeroes(matrix);   //O(m*n) space
    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[0].size();j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }

    vector<vector<int>> matrix1={{0,1,2,0},{3,4,5,2},{1,3,1,5}};
    cout<<"---------Method 2----------"<<endl;
    for(int i=0;i<matrix1.size();i++){
        for(int j=0;j<matrix1[0].size();j++){
            cout<<matrix1[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    setZeroes1(matrix1);  //O(m+n) space
    for(int i=0;i<matrix1.size();i++){
        for(int j=0;j<matrix1[0].size();j++){
            cout<<matrix1[i][j]<<" ";
        }
        cout<<endl;
    }

    vector<vector<int>> matrix2={{0,1,2,0},{3,4,5,2},{1,3,1,5}};
    cout<<"---------Method 3----------"<<endl;
    for(int i=0;i<matrix2.size();i++){
        for(int j=0;j<matrix2[0].size();j++){
            cout<<matrix2[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    setZeroes2(matrix2);  //no extra space
    for(int i=0;i<matrix2.size();i++){
        for(int j=0;j<matrix2[0].size();j++){
            cout<<matrix2[i][j]<<" ";
        }
        cout<<endl;
    }
}