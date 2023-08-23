/*
Idea:(using binary search algorithm)
there will be n/2 elements smaller than median, finding the element with this attribute.

Steps:
-finding min & max value from the matrix
- assuming the median to be average of those values,
 finding elements in matrix which are smaller than assumption
-if elements are less than expected-increase min value to average, else max value to average.
*/
#include <bits/stdc++.h>
using namespace std;



class Solution {
public:
    int median(vector<vector<int>>& matrix, int R, int C)
    {
        int minVal = INT_MAX, maxVal = INT_MIN;
        for (int i = 0;i < R;++i)
        {
            //finding min & max value of the matrix by comparing first and last element of each row of matrix
            minVal = min(minVal, matrix[i][0]);
            maxVal = max(maxVal, matrix[i][C - 1]);
        }

        int elements_smaller_than_median = (R * C + 1) / 2;

        while (minVal < maxVal)
        {
            int number_of_elements_smaller_than_median = 0, mid = minVal + (maxVal - minVal) / 2;

            for (int i = 0;i < R;++i)
                // upper bound function returns number of elements smaller than target variable
                number_of_elements_smaller_than_median += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();

            // if count<target, shifting the min value, else shifting the max value.
            if (number_of_elements_smaller_than_median < elements_smaller_than_median)
                minVal = mid + 1;
            else
                maxVal = mid;
        }
        return minVal;
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
        vector<vector<int>> matrix(r, vector<int>(c));
        for (int i = 0; i < r; ++i)
            for (int j = 0;j < c; ++j)
                cin >> matrix[i][j];
        Solution obj;
        int ans = -1;
        ans = obj.median(matrix, r, c);
        cout << ans << "\n";
    }
    return 0;
}