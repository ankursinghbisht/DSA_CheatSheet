/*
Idea:
Insertion- transferring elements from A to B & appending the value
Deletion - transferring elements from B to A & deleting top element
*/

//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

class StackQueue {
private:
    stack<int> s1;
    stack<int> s2;
public:
    void push(int B);
    int pop();

};
int main()
{

    int T;
    cin >> T;
    while (T--)
    {
        StackQueue* sq = new StackQueue();

        int Q;
        cin >> Q;
        while (Q--) {
            int QueryType = 0;
            cin >> QueryType;
            if (QueryType == 1)
            {
                int a;
                cin >> a;
                sq->push(a);
            }
            else if (QueryType == 2) {
                cout << sq->pop() << " ";

            }
        }
        cout << endl;
    }


}

// } Driver Code Ends




/* The structure of the class is
class StackQueue{
private:
    // These are STL stacks ( http://goo.gl/LxlRZQ )
    stack<int> s1;
    stack<int> s2;
public:
    void push(int);
    int pop();
}; */

//Function to push an element in queue by using 2 stacks.
// Function to push an element in the queue by using 2 stacks.
void StackQueue::push(int x)
{
    // Your Code

    // Transfer all elements from s1 to s2
    while (!s1.empty())
    {
        s2.push(s1.top());
        s1.pop();
    }

    // Push the new element onto s2
    s2.push(x);
}

// Function to pop an element from the queue by using 2 stacks.
int StackQueue::pop()
{
    // Your Code

    // Transfer all elements from s2 to s1
    while (!s2.empty())
    {
        s1.push(s2.top());
        s2.pop();
    }

    // Check if s1 is empty, indicating the queue is empty
    if (s1.empty())
        return -1; // Return -1 to indicate an empty queue

    // Pop the front element from s1
    int frontElement = s1.top();
    s1.pop();

    // Return the popped element
    return frontElement;
}
