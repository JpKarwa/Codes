/* Given a positive integer n, generate a n x n matrix filled with elements from 1 to n2 in spiral order.
Input 1: n = 3
Output 1: [[1,2,3],[8,9,4],[7,6,5]]
Input 2: n = 1
Output 2: [[1]]
*/

// LEETCODE 59-> Spiral Matrix II

#include <iostream>
using namespace std;

int main(){
    int n;
    cout << "Enter integer:";
    cin >> n;

    int a[n][n];

    cout << "Spiral print method 1:";
    int minr = 0;
    int maxr = n - 1;
    int minc = 0;
    int maxc = n - 1;
    int c = 1;
    int highest = n * n;
    while (c <= n * n)
    {
        // right
        for (int j = minc; j <= maxc; j++)
        {
            a[minr][j] = c;
            c++;
        }
        minr++;
        cout << c;
        // down
        if (minr > maxr || minc > maxc)
            break;
        for (int i = minr; i <= maxr; i++)
        {
            a[i][maxc] = c;
            c++;
        }
        maxc--;
        // left
        if (minr > maxr || minc > maxc)
            break;
        for (int j = maxc; j >= minc; j--)
        {
            a[maxr][j] = c;
            c++;
        }
        maxr--;
        // up
        if (minr > maxr || minc > maxc)
            break;
        for (int i = maxr; i >= minr; i--)
        {
            a[i][minc] = c;
            c++;
        }
        minc++;
    }

    cout << endl;
    cout << "Matrix is:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Spiral print method 2:" << endl;
    // index initialisation
    int b[n][n];
    int lb = 0;
    int ub = n - 1;
    int t = 1;
    while (lb <= ub)
    {
        // right
        for (int j = lb; j <= ub; j++)
        {
            b[lb][j] = t++;
        }
        // down
        for (int i = lb + 1; i <= ub; i++)
        {
            b[i][ub] = t++;
        }
        // left
        for (int j = ub - 1; j >= lb; j--)
        {
            b[ub][j] = t++;
        }
        // up
        for (int i = ub - 1; i > lb; i--)
        {
            b[i][lb] = t++;
        }
        lb++;
        ub--;
    }

    cout << "Matrix is:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << b[i][j] << " ";
        }
        cout << endl;
    }
}