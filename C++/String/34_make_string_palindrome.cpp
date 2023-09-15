/*
Using LPS(Longest Prefix Suffix) array in KMP (Knuth Morris Pratt) algorithm
(used to find string inside a string)

Idea:
reversing and appending the string to itself, the last element of array will give number of elements already in palindromic order
return the rest of the element count.

*/



#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int minChar(string str)
    {

        string temp = str;
        reverse(str.begin(), str.end()); // reversing the string
        temp = temp + "#" + str; // appending it to itself, with buffer char

        int stringSize = str.size(), patternSize = temp.size(), i = 1, j = 0;
        vector<int> arr(temp.size(), 0); // creating lps array


        while (i < patternSize)
        {
            // updating values of lps array
            if (temp[i] == temp[j]) // Match found, increment both pointers
                arr[i++] = ++j;
            else
            {
                if (j == 0) // No match, but we can't go back further, so increment i only
                    arr[i++] = j;

                else
                    j = arr[j - 1]; // No match; use the LPS value to backtrack j
            }
        }
        return stringSize - arr[patternSize - 1]; // returning the difference

    }
};


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        Solution ob;
        int ans = ob.minChar(str);
        cout << ans << endl;
    }
    return 0;
}

