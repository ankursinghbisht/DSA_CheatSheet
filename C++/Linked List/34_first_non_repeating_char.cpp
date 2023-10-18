/*
Idea:
using 2 vectors to store frequency of each character & it's last occurrence
While iterating the string-checking if element has occurred before or not & if yes, finding the second unique element occured
& updating the answer string.
*/

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    string FirstNonRepeating(string A)
    {
        //storing the size of the string.
        int n = A.size();

        //creating a frequency array for all the characters in the string.
        vector<int> f(26, 0);

        //creating an array to store the last occurrence of each character.
        vector<int> last(26, -1);

        //iterating over the string to update the last occurrence of each character.
        for (int i = 0; i < A.size(); i++)
        {
            if (last[A[i] - 'a'] == -1)
                last[A[i] - 'a'] = i;
        }

        //string to store the answer.
        string ans = "";

        //iterating over the string again to update the frequency of each character and find the first non-repeating character.
        for (int i = 0; i < A.size(); i++)
        {
            f[A[i] - 'a']++;
            //character to store the first non-repeating character.
            char ch = '#';

            //variable to store the last occurrence index of the first non-repeating character.
            int x = A.size() + 1;

            //iterating over the frequency array to find the first non-repeating character.
            for (int j = 0; j < 26; j++)
                if (f[j] == 1 and x > last[j])
                {
                    ch = char(j + 'a');
                    x = last[j];
                }


            //appending the first non-repeating character to the answer string.
            ans += ch;
        }

        //returning the answer string.
        return ans;
    }

};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        string A;
        cin >> A;
        Solution obj;
        string ans = obj.FirstNonRepeating(A);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends