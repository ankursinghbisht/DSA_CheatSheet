"""
Idea:
using stack, inserting till numbers are found ,if any operator is encountered,
performing operations on top 2 elements and pushing the answer on stack, performing till stack has only 1 element.

"""


# User function Template for python3

class Solution:

    # Function to evaluate a postfix expression.
    def evaluatePostfix(self, expression):
        stack = []

        for char in expression:
            if char.isdigit():
                stack.append(int(char))
            else:
                operand2 = stack.pop()
                operand1 = stack.pop()

                if char == '+':
                    stack.append(operand1 + operand2)
                elif char == '-':
                    stack.append(operand1 - operand2)
                elif char == '*':
                    stack.append(operand1 * operand2)
                elif char == '/':
                    stack.append(operand1 // operand2)

        # The result should be the only element left in the stack
        return stack[0]


# code here


# {
# Driver Code Starts
# Initial Template for Python 3

import atexit
import io
import sys


_INPUT_LINES = sys.stdin.read().splitlines()
input = iter(_INPUT_LINES).__next__
_OUTPUT_BUFFER = io.StringIO()
sys.stdout = _OUTPUT_BUFFER


@atexit.register
def write():
    sys.__stdout__.write(_OUTPUT_BUFFER.getvalue())


if __name__ == '__main__':
    test_cases = int(input())
    for cases in range(test_cases):
        S = input()
        obj = Solution()
        print('{0:g}'.format(float(obj.evaluatePostfix(S))))
# } Driver Code Ends