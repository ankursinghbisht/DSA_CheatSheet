/*
Idea:
Preprocessing the matrix such that index(i, j) stores max of elements in matrix from (i, j) to (N-1, N-1)
and finding max value by subtracting the max value from that current index to max value matrix.
*/
#include <bits/stdc++.h>
using namespace std;
#define N 5

int findMaxValue(int mat[][N])
{
    int MaxArr[N][N], ans = INT_MIN;

    MaxArr[N - 1][N - 1] = mat[N - 1][N - 1];
    int MaxValue = MaxArr[N - 1][N - 1];

    //preprocess last row
    for (int i = N - 2;i >= 0;--i)
    {
        if (MaxValue < mat[N - 1][i])
            MaxValue = mat[N - 1][i];
        MaxArr[N - 1][i] = MaxValue;
    }

    MaxValue = MaxArr[N - 1][N - 1];
    //preprocess last column
    for (int i = N - 2;i >= 0;--i)
    {
        if (MaxValue < mat[i][N - 1])
            MaxValue = mat[i][N - 1];
        MaxArr[i][N - 1] = MaxValue;
    }

    //preprocess rest of the matrix from bottom
    for (int i = N - 2;i >= 0;--i)
    {
        for (int j = N - 2;j >= 0;--j)
        {
            ans = max(ans, MaxArr[i + 1][j + 1] - mat[i][j]);
            MaxArr[i][j] = max(mat[i][j], max(MaxArr[i][j + 1], MaxArr[i + 1][j]));

        }
    }
    return ans;
}

int main()
{
    int mat[N][N] = { { 1, 2, -1, -4, -20 },
                    { -8, -3, 4, 2, 1 },
                    { 3, 8, 6, 1, 3 },
                    { -4, -1, 1, 7, -6 },
                    { 0, -4, 10, -5, 1 } };
    cout << "Maximum Value is " << findMaxValue(mat);

    return 0;
}
