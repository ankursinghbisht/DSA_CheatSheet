
/*
Idea:
using backtracking , find all possible permutations of string
*/
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:

    void AllPermutation(string& input, int low, int high, set<string>& st)
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
            AllPermutation(input, low + 1, high, ans);
            swap(input[low], input[i]);
        }

    }
    vector<string>find_permutation(string S)
    {
        set<string>st; //using set for any duplicates
        vector<string>ans;
        AllPermutation(S, 0, S.size() - 1, st);
        for (auto it : st)
            ans.push_back(it);
        return ans;
    }
};



int main() {
    int t = 1;
    //cin >> t;
    while (t--)
    {
        string S = "ABC";
        // cin >> S;
        Solution ob;
        vector<string> ans = ob.find_permutation(S);
        // sort(ans.begin(), ans.end());
        for (auto i : ans)
        {
            cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends