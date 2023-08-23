
/*
Idea:
-Breaking problem into smaller parts.
-Iterating the matrix from outermost ring, then inner ring & appending the answer at each iteration.
*/
#include <bits/stdc++.h> 
using namespace std;

class Solution
{
public:
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c)
    {
        vector<int> ans;
        int row_start = 0, row_end = r - 1, col_start = 0, col_end = c - 1;

        while (row_start <= row_end && col_start <= col_end)
        {
            // Traverse top row
            for (int i = col_start; i <= col_end; ++i)
                ans.push_back(matrix[row_start][i]);
            row_start++;

            // Traverse right column
            for (int i = row_start; i <= row_end; ++i)
                ans.push_back(matrix[i][col_end]);
            col_end--;

            // Traverse bottom row
            if (row_start <= row_end)
            {
                for (int i = col_end; i >= col_start; --i)
                    ans.push_back(matrix[row_end][i]);
                row_end--;
            }

            // Traverse left column
            if (col_start <= col_end)
            {
                for (int i = row_end; i >= row_start; --i)
                    ans.push_back(matrix[i][col_start]);
                col_start++;
            }
        }

        return ans;
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
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
            cout << result[i] << " ";
        cout << endl;
    }
    return 0;

}