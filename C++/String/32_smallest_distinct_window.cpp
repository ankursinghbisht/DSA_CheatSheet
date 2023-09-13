/*
Idea:
Hashing all unique characters of string, and using sliding windows technique to find the substring which
fits hash value of unique characters string. returning the length of shortest substring
*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



class Solution {
public:
    const int no_of_chars = 256;
    int findSubString(string str)
    {
        int len1 = s.size();
        string pattern = "";
        set<char> char_set;

        // Iterate through the input string to find unique characters
        for (char c : s) {
            char_set.insert(c);
        }

        // Build the pattern string from unique characters
        for (char c : char_set) {
            pattern += c;
        }

        int len2 = pattern.size();

        // If the length of the input string is less than the pattern length, no valid window exists
        if (len1 < len2) {
            return 0;
        }

        int hash_pattern[256] = { 0 };
        int hash_string[256] = { 0 };

        // Count the occurrences of characters in the pattern
        for (char c : pattern) {
            hash_pattern[c]++;
        }

        int start = 0;
        int start_index = -1;
        int ans = INT_MAX;
        int count = 0;

        // Iterate through the input string
        for (int i = 0; i < len1; ++i) {
            char c = s[i];
            hash_string[c]++;

            // If the character is part of the pattern and the count is less than or equal to the pattern count
            if (hash_pattern[c] != 0 && hash_string[c] <= hash_pattern[c]) {
                count++;
            }

            // If all characters in the pattern are found in the window
            if (count == len2) {
                // Shrink the window by moving the start index
                while (hash_string[s[start]] > hash_pattern[s[start]]) {
                    hash_string[s[start]]--;
                    start++;
                }

                // Calculate the length of the current window
                int len_window = i - start + 1;

                // Update the minimum window length if necessary
                if (ans > len_window) {
                    ans = len_window;
                    start_index = start;
                }
            }
        }

        // If no valid window is found, return 0; otherwise, return the minimum window length
        if (start_index == -1) {
            return 0;
        }

        return ans;


    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;
    }
    return 0;
}
