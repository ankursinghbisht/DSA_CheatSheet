/*
Idea:
using choosing or not choosing , via recursion.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void printSubsequence(string input, string output)
    {
        // Base Case, if the input is empty print the output string
        if (input.empty()) {
            cout << output << endl;
            return;
        }

        // output is passed with including the Ist character of  Input string
        printSubsequence(input.substr(1), output + input[0]);

        // output is passed without  including the Ist character of Input string
        printSubsequence(input.substr(1), output);
    }

};

int main() {
    int tc;
    cin >> tc;
    while (tc--)
    {
        string str, ans;
        cin >> str;
        Solution obj;
        obj.AllSubSequence(str, ans);
    }
    return 0;

}