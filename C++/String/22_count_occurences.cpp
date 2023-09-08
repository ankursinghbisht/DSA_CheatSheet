/*
Idea:
use recursion to traverse through each character of the matrix and taking each character as a start of the string to be found.
if found, repeating for all directions
*/


#include <bits/stdc++.h>
using namespace std;


class Solution {
public:

    int internalSearch(string target, int row, int col, vector<vector<char> >& mat, int row_max, int col_max, int index)
    {
        int found = 0;
        if (row >= 0 && row <= row_max && col >= 0 && col <= col_max && target[index] == mat[row][col])
        {
            // if characters are matched
            char match = target[index];
            index += 1;

            mat[row][col] = 0;

            if (target[index] == 0)
                found = 1; // if string has ended
            else
            {
                // through Backtrack searching in every directions
                found += internalSearch(target, row, col + 1, mat, row_max, col_max, index);
                found += internalSearch(target, row, col - 1, mat, row_max, col_max, index);
                found += internalSearch(target, row + 1, col, mat, row_max, col_max, index);
                found += internalSearch(target, row - 1, col, mat, row_max, col_max, index);
            }
            mat[row][col] = match;
        }
        return found;
    }

    int findOccurrence(vector<vector<char> >& mat, string target)
    {
        int found = 0, row_count = mat.size(), col_count = mat[0].size();

        for (int r = 0; r < row_count; ++r)
            for (int c = 0; c < col_count; ++c)
                found += internalSearch(target, r, c, mat, row_count - 1, col_count - 1, 0);
        return found;
    }
};


int main() {
    int t;
    cin >> t;
    while (t--) {
        int R, C;
        cin >> R >> C;
        vector<vector<char> > mat(R);
        for (int i = 0; i < R; i++) {
            mat[i].resize(C);
            for (int j = 0; j < C; j++) cin >> mat[i][j];
        }
        string target;
        cin >> target;
        Solution obj;
        cout << obj.findOccurrence(mat, target) << endl;
    }
}
