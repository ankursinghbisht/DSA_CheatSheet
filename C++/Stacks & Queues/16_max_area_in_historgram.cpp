/*
Idea:
Finding left & right smaller element of each element & multiplying the difference with value at index
storing the max result & returning.
*/
#include <bits/stdc++.h>
using namespace std;


class Solution
{
public:
    long long getMaxArea(long long a[], int n)
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
};

int main()
{
    long long t;

    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        long long arr[n];
        for (int i = 0;i < n;i++)
            cin >> arr[i];
        Solution ob;
        cout << ob.getMaxArea(arr, n) << endl;

    }
    return 0;
}
