/*
Idea:
Popping front element, recursing in rest of queue, and inserting the element again.
*/

//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//function Template for C++

//Function to reverse the queue.
class Solution
{
public:
    queue<int> rev(queue<int>& q)
    {
        // Base case: if the queue is empty, return an empty queue
        if (q.empty())
            return queue<int>();

        // Recursive case: remove the front element
        int frontElement = q.front();
        q.pop();
        // Recursively reverse the remaining queue
        queue<int> reversedQueue = rev(q);

        // Insert the front element at the rear
        reversedQueue.push(frontElement);

        return reversedQueue;
    }
};


//{ Driver Code Starts.
int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        queue<int> q;
        int n, var;
        cin >> n;
        while (n--)
        {
            cin >> var;
            q.push(var);
        }
        Solution ob;
        queue<int> a = ob.rev(q);
        while (!a.empty())
        {
            cout << a.front() << " ";
            a.pop();
        }
        cout << endl;
    }
}
// } Driver Code Ends