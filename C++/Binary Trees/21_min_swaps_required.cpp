/*
Idea:
inorder traversal of binary search tree is in sorted order,
finding no. of swaps required to get inorder traversal sorted.
*/
// C++ program for Minimum swap required
// to convert binary tree to binary search tree
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Inorder Traversal of Binary Tree
    void inorder(vector<int>& v, vector<int>& temp, int n, int index)
    {
        // if index is greater or equal to vector size
        if (index >= n)
            return;
        inorder(v, temp, n, 2 * index + 1);

        // push elements in vector
        temp.push_back(v[index]);
        inorder(v, temp, n, 2 * index + 2);
    }

    // Function to find minimum swaps to sort an array
    int minSwaps(vector<int>& v, int n)
    {
        int ans = 0;
        vector<int> temp;
        inorder(v, temp, n, 0);
        vector <pair<int, int>> t;
        for (int i = 0;i < n;++i)
            t.push_back({ temp[i],i });

        sort(t.begin(), t.end());
        for (int i = 0; i < n; i++)
        {
            // second element is equal to i
            if (i == t[i].second)
                continue;
            else
            {
                // swapping of elements
                swap(t[i].first, t[t[i].second].first);
                swap(t[i].second, t[t[i].second].second);
                --i;
            }
            ans++;
        }
        return ans;
    }
};

// Driver code
int main()
{
    vector<int> a = { 5, 6, 7, 8, 9, 10, 11 };
    int n = 7;
    Solution obj;
    cout << obj.minSwaps(a, n) << endl;
}

// This code is contributed by code_freak
