/*
Idea:
using stack, inserting till numbers are found ,if any operator is encountered,
performing operations on top 2 elements and pushing the answer on stack, performing till stack has only 1 element.
*/

//{ Driver Code Starts
// C++ program to evaluate value of a postfix expression

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
public:
    //Function to evaluate a postfix expression.
    int evaluatePostfix(const string& expression)
    {
        stack<int> stack;

        for (char ch : expression)
        {
            if (isdigit(ch))
            {
                // If the character is a digit, convert it to an integer and push onto the stack
                stack.push(ch - '0');
            }
            else
            {
                // If the character is an operator, pop the top two elements, perform the operation, and push the result back
                int operand2 = stack.top();
                stack.pop();
                int operand1 = stack.top();
                stack.pop();

                switch (ch)
                {
                case '+':
                    stack.push(operand1 + operand2);
                    break;
                case '-':
                    stack.push(operand1 - operand2);
                    break;
                case '*':
                    stack.push(operand1 * operand2);
                    break;
                case '/':
                    stack.push(operand1 / operand2);
                    break;
                default:
                    break;
                }
            }
        }
        // The result should be the only element left in the stack
        return stack.top();
    }
};

//{ Driver Code Starts.

// Driver program to test above functions
int main()
{
    int t;
    cin >> t;
    cin.ignore(INT_MAX, '\n');
    while (t--)
    {
        string S;
        cin >> S;
        Solution obj;

        cout << obj.evaluatePostfix(S) << endl;
    }
    return 0;
}

// } Driver Code Ends