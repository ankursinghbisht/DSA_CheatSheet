/*
Idea:
storing frequencies of each character, inserting in priority queue and updating frequencies and returning answer
*/

//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int minValue(string s, int k)
    {
        int temp = 0, ans = 0;
        vector<int> vc(26, 0);

        // Count the frequency of each character in the string.
        for (int i = 0; i < s.size(); ++i)
            vc[s[i] - 'a']++;

        // Priority queue to store the frequencies in descending order.
        priority_queue<int> q;

        // Push non-zero frequencies to the priority queue.
        for (int i = 0; i < 26; ++i)
            if (vc[i])
                q.push(vc[i]);

        // Perform k operations on the priority queue.
        while (k--)
        {
            // Get the top element from the priority queue.
            int temp = q.top();
            // Decrement its value and push it back to the priority queue.
            q.pop();
            --temp;
            q.push(temp);
        }

        // Calculate the minimum value after k operations.
        while (!q.empty())
        {
            // Get the top element from the priority queue.
            temp = q.top();
            // Add the square of its value to the final answer.
            ans += (temp * temp);
            // Remove the element from the priority queue.
            q.pop();
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        int k;
        cin >> s >> k;

        Solution ob;
        cout << ob.minValue(s, k) << "\n";
    }
    return 0;
}
// } Driver Code Ends