/*
Idea:
inserting first 'K' elements in stack, then pushing in new queue, and appending rest of elements as well
*/

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
queue<int> modifyQueue(queue<int> q, int k);
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n, k;
        cin >> n >> k;
        queue<int> q;
        while (n-- > 0) {
            int a;
            cin >> a;
            q.push(a);
        }
        queue<int> ans = modifyQueue(q, k);
        while (!ans.empty()) {
            int a = ans.front();
            ans.pop();
            cout << a << " ";
        }
        cout << endl;
    }
}
// } Driver Code Ends


// User function Template for C++

// Function to reverse the first k elements of a queue.
queue<int> modifyQueue(queue<int> q, int k)
{
    // Create a stack to temporarily store the first k elements.
    stack<int> st;

    // Create a queue to store the final modified elements.
    queue<int> ans;

    // Step 1: Move the first k elements from the front of the original queue to the stack.
    while (k--)
    {
        st.push(q.front()); // Push the front element of the original queue onto the stack.
        q.pop(); // Remove the front element from the original queue.
    }

    // Step 2: Pop elements from the stack and push them onto the final queue to reverse their order.
    while (!st.empty())
    {
        ans.push(st.top()); // Push the top element of the stack onto the final queue.
        st.pop(); // Pop the top element from the stack.
    }

    // Step 3: Move the remaining elements from the original queue to the final queue.
    while (!q.empty())
    {
        ans.push(q.front()); // Push the front element of the original queue onto the final queue.
        q.pop(); // Remove the front element from the original queue.
    }

    // Return the modified queue with the first k elements reversed.
    return ans;
}