/*
Idea: ( using stack )
store the indices of elements for which we have to find the next smaller element in a stack and
while traversing the array, if we find a greater element,
we will pair it with the elements from the stack till the top element of the stack is less than the current element.
*/

//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h> 
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {

public:
    vector<int> help_classmate(vector<int> arr, int n)
    {
        stack<int> st;
        vector<int> ans(n, -1);

        for (int i = 0;i < arr.size();++i)
        {
            while (!st.empty() && arr[st.top()] > arr[i]) // element is next smaller element to top element
            {
                ans[st.top()] = arr[i];
                st.pop();
            }
            // pushing elements of array in stack
            st.push(i);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> array(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> array[i];
        }
        Solution obj;
        vector<int> result = obj.help_classmate(array, n);
        for (int i = 0; i < n; ++i)
        {
            cout << result[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}


// } Driver Code Ends