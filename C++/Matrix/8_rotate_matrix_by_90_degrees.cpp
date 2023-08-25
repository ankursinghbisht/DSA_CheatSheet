/*

00 01 02                20 10 00
10 11 12       ---->>   21 11 01
20 21 22                22 12 02

Idea:
In any row, for every decreasing row index i,
there exists a constant column index j, such that j = current_row_index.

*/

#include <bits/stdc++.h>
using namespace std;

#define N 4

void rotate90Clockwise(int arr[N][N])
{
    // printing the matrix on the basis of
    // observations made on indices.
    for (int j = 0; j < N; j++)
    {
        for (int i = N - 1; i >= 0; i--)
            cout << arr[i][j] << " ";
        cout << '\n';
    }
}

// Driver code
int main()
{
    int arr[N][N] = { { 1, 2, 3, 4 },
                    { 5, 6, 7, 8 },
                    { 9, 10, 11, 12 },
                    { 13, 14, 15, 16 } };
    rotate90Clockwise(arr);
    return 0;
}

// This code is contributed by yashbeersingh42
