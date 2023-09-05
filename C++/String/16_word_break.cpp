/*
Idea:
using recursion to find all possible combinations of words & searching if all exist in dictionary.
*/

//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


class Solution
{
public:
    int wordBreak(string word, vector<string>& dictionary) {
        if (word.empty())
            return 1;  // Base case: an empty string can always be broken.

        for (int i = 1; i <= word.size(); ++i)
        {
            //trying all possible combination of words
            string prefix = word.substr(0, i);
            // If the prefix is in the dictionary and the remaining part can be broken
            if (find(dictionary.begin(), dictionary.end(), prefix) != dictionary.end() && wordBreak(word.substr(i), dictionary))
                return 1;
        }

        return 0;
    }

};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<string> dict;
        for (int i = 0;i < n;i++) {
            string S;
            cin >> S;
            dict.push_back(S);
        }
        string line = "lrbbmqbabowkkab";
        cin >> line;
        Solution ob;
        cout << ob.wordBreak(line, dict) << "\n";
    }
}
