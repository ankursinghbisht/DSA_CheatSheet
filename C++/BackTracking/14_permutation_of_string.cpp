/*
Idea:
using backtracking , find all possible permutations of string
*/

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    set<string>st;
public:

    void AllPermutation(string& input, int low, int high)
    {
        // base case
        if (low > high)
        {
            st.insert(input);
            return;
        }
        for (int i = low;i <= high;++i)
        {
            // at each iteration, swapping two characters , and calling the function again
            swap(input[low], input[i]);
            AllPermutation(input, low + 1, high);
            swap(input[low], input[i]);
        }

    }
    vector<string>find_permutation(string S)
    {
        vector<string>ans;
        AllPermutation(S, 0, S.size() - 1);
        for (auto it : st)
            ans.push_back(it);
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--)
    {
        string S;
        cin >> S;
        Solution ob;
        vector<string> ans = ob.find_permutation(S);
        sort(ans.begin(), ans.end());
        for (auto i : ans)
        {
            cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends