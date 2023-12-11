/*
Idea:
Recursing while popping top elements and storing in function call stack &
Inserting elements at top if all below elements are smaller
[recursing till stack is empty or is smaller than target(elements are stored in function call stack).
inserting element and pushing rest elements]
*/

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

class SortedStack {
public:
    stack<int> s;
    void sort();
};

void printStack(stack<int> s)
{
    while (!s.empty())
    {
        printf("%d ", s.top());
        s.pop();
    }
    printf("\n");
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        SortedStack* ss = new SortedStack();
        int n;
        cin >> n;
        for (int i = 0;i < n;i++)
        {
            int k;
            cin >> k;
            ss->s.push(k);
        }
        ss->sort();
        printStack(ss->s);
    }
}
// } Driver Code Ends


/*The structure of the class is
class SortedStack{
public:
    stack<int> s;
    void sort();
};
*/

// Function to insert the element x in a sorted manner into the stack s
void sortedInsert(stack<int>& s, int x)
{
    // If stack is empty or the element is greater than the top element, push it
    if (s.empty() or x > s.top())
    {
        s.push(x);
        return;
    }

    // Remove the top element and recursively insert the element in the remaining stack
    int temp = s.top();
    s.pop();
    sortedInsert(s, x);

    // Push back the removed element to its original position in the stack
    s.push(temp);
}

// Function to sort the stack in ascending order
void SortedStack::sort()
{
    // Base case: if stack is not empty
    if (!s.empty())
    {
        // Remove the top element and recursively sort the remaining stack
        int x = s.top();
        s.pop();
        sort();

        // Insert the removed element back into the stack in a sorted manner
        sortedInsert(s, x);
    }
}