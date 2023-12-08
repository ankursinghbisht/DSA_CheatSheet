/*
Idea:
for min element, popping till empty and returning the min element
*/

//{ Driver Code Starts
#include<iostream>
#include<stack>
using namespace std;
void push(stack<int>& s, int a);
bool isFull(stack<int>& s, int n);
bool isEmpty(stack<int>& s);
int pop(stack<int>& s);
int getMin(stack<int>& s);
stack<int> s;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, a;
        cin >> n;
        while (!isEmpty(s)) {
            pop(s);
        }
        while (!isFull(s, n)) {
            cin >> a;
            push(s, a);
        }
        cout << getMin(s) << endl;
    }
}
// } Driver Code Ends



void push(stack<int>& s, int a)
{
    s.push(a);
}

bool isFull(stack<int>& s, int n)
{
    if (s.size() == n)
        return true;
    return false;
}

bool isEmpty(stack<int>& s)
{
    return s.empty();
}

int pop(stack<int>& s)
{
    int popped = s.top();
    s.pop();
    return popped;
}

int getMin(stack<int>& s)
{
    int min = pop(s);
    while (!isEmpty(s))
    {
        if (min > s.top()) min = s.top();
        s.pop();
    }
    return min;
}