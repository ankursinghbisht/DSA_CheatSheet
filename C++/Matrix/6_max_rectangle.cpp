/*
Idea:
(Using area of histogram technique,)
finding max area at each row, where height will be sum of 1's above the current row.
*/

#include <bits/stdc++.h>
using namespace std;
#define MAX 1000



class Solution
{
public:
    int largestRectangleArea(int a[], int n)
    {
        stack<int> st;// using stack to store element's indices
        vector<int> leftSmall, rightSmall;

        for (int i = 0;i < n;++i)
        {
            while (!st.empty() && a[i] <= a[st.top()])
                //checking if current element is greater than top of stack , till we find smaller one
                st.pop();

            // if stack is empty, means no smaller element, else appending right of smaller element
            if (st.empty())
                leftSmall.push_back(0);
            else
                leftSmall.push_back(st.top() + 1);
            st.push(i);
        }
        while (!st.empty())
            st.pop(); // clearing stack


        for (int i = n - 1;i >= 0;--i)
        {
            while (!st.empty() && a[i] <= a[st.top()])
                //checking if current element is greater than top of stack , till we find smaller one
                st.pop();

            // if stack is empty, means no smaller element, else appending right of smaller element
            if (st.empty())
                rightSmall.push_back(n - 1);
            else
                rightSmall.push_back(st.top() - 1);
            st.push(i);
        }

        reverse(rightSmall.begin(), rightSmall.end()); // reversing the vector, as it's reversed to original array
        long long ans = INT_MIN;
        for (int i = 0;i < n;++i)
            // returning the answer by calculating total area using difference of 2 vectors & value at i
            ans = max(ans, (a[i] * (abs(leftSmall[i] - rightSmall[i]) + 1)));
        return ans;
    }

    int maxArea(int M[MAX][MAX], int n, int m)
    {
        int arr[n], ans = 0;
        for (int i = 0;i < n;++i)
            arr[i] = 0; // setting up the array passing as histogram 

        for (int i = 0;i < n;++i)
        {
            for (int j = 0;j < m;++j)
            {
                // at each element, if it's 0, height will be 0, else 1 will be added to height
                if (M[i][j] == 0)
                    arr[i] = 0;
                else
                    ++arr[i];
            }
            // finding max answer
            ans = max(ans, largestRectangleArea(arr, n));
        }

        return ans;
    }
};


int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}
