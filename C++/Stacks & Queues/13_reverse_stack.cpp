/*
Recursing while popping top elements and storing in function call stack &
Inserting elements in bottom of stack.
[recursing till stack is empty (elements are stored in function call stack). inserting element and pushing rest elements]
*/

//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    // Function to insert an element at the bottom of the stack
    void insert_at_bottom(stack<int>& St, int x) {
        if (St.empty()) {
            // If the stack is empty, push the element and return
            St.push(x);
            return;
        }

        // Store the top element of the stack and pop it
        int temp = St.top();
        St.pop();

        // Recursively insert the element at the bottom
        insert_at_bottom(St, x);

        // Push back the stored top element after the recursive call
        St.push(temp);
    }

    // Function to reverse the elements of a stack
    void Reverse(stack<int>& St) {
        if (St.empty())
            return;  // If the stack is empty, return

        // Store the top element of the stack and pop it
        int num = St.top();
        St.pop();

        // Recursively reverse the remaining elements of the stack
        Reverse(St);

        // Insert the stored element at the bottom of the reversed stack
        insert_at_bottom(St, num);
    }
};

//{ Driver Code Starts.


int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        stack<int> St;
        for (int i = 0;i < N;i++) {
            int x;
            cin >> x;
            St.push(x);
        }
        Solution ob;
        ob.Reverse(St);
        vector<int>res;
        while (St.size())
        {
            res.push_back(St.top());
            St.pop();
        }
        for (int i = res.size() - 1;i >= 0;i--)
        {
            cout << res[i] << " ";
        }

        cout << endl;
    }
}
// } Driver Code Ends