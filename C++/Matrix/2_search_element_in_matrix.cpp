/*
Idea:
Using Binary search in 2D matrix,
- if element is greater than target,decreasing the column
- if element is smaller than target, increasing the row value
*/

#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {
        if (matrix.size() == 0 || matrix[0].size() == 0)
            // checking if arrays is empty or not
            return false;

        int row = matrix.size() - 1;
        int col = matrix[0].size() - 1;

        if (target == matrix[0][0])
            // if matrix has only 1 element
            return true;

        int x = 0;
        int y = col; // declaring the indices to traverse the matrix
        while (x <= row && y >= 0)
        {
            if (target == matrix[x][y])
                return true;

            else if (target < matrix[x][y])
                // if element is bigger than target, decreasing the column value
                --y;
            else
                // if element is smaller than target, increasing the row value
                ++x;
        }
        return false;
    }
};
int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int r, c;
        cin >> r >> c;
        vector<vector<int> > matrix(r);

        for (int i = 0; i < r; i++)
        {
            matrix[i].assign(c, 0);
            for (int j = 0; j < c; j++)
            {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        cout << ob.searchMatrix(matrix, r, c);
    }
    return 0;

}