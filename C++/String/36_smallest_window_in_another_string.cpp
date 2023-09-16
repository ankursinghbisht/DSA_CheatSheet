/*
Idea:
The idea is to use the two pointer approach on the hash array of pattern string
and then find the minimum window by eliminating characters from the start of the window.
*/

#include<bits/stdc++.h>
using namespace std;


const int NO_OF_CHARS = 256; // Define the number of characters in the character set (256 ASCII characters)

class Solution {
public:
    string smallestWindow(string str, string pat)
    {
        int len1 = str.length();
        int len2 = pat.length();

        // Check if the length of the input string is less than the length of the pattern
        if (len1 < len2)
            return "-1";

        vector<int> hash_pat(NO_OF_CHARS, 0); // Initialize an array to store character frequencies in the pattern
        vector<int> hash_str(NO_OF_CHARS, 0); // Initialize an array to store character frequencies in the current window

        // Calculate the frequency of each character in the pattern
        for (char c : pat)
            hash_pat[c]++;

        int start = 0; // Initialize the start of the window
        int start_index = -1; // Initialize the starting index of the minimum window
        int min_len = INT_MAX; // Initialize the minimum window length to a large value
        int count = 0; // Initialize a counter for characters matched

        for (int j = 0; j < len1; j++) {
            hash_str[str[j]]++;

            // If the current character in the window is in the pattern, increment the count
            if (hash_str[str[j]] <= hash_pat[str[j]])
                count++;

            // If all characters in the pattern are matched in the window
            if (count == len2) {
                // Shrink the window by removing unnecessary characters from the beginning
                while (hash_str[str[start]] > hash_pat[str[start]] || hash_pat[str[start]] == 0) {
                    hash_str[str[start]]--;
                    start++;
                }

                // Calculate the length of the current window
                int len_window = j - start + 1;

                // Update the minimum window length and starting index if a smaller window is found
                if (min_len > len_window) {
                    min_len = len_window;
                    start_index = start;
                }
            }
        }


        if (start_index == -1)
            return "-1";


        return str.substr(start_index, min_len);
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        string pat;
        cin >> pat;
        Solution obj;
        cout << obj.smallestWindow(s, pat) << endl;

    }
    return 0;
}
