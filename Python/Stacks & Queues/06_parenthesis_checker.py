"""
Idea:
Using stack to store all opening brackets & pooping if similar closing bracket is found
return false , if stack is empty, else true.
"""


class Solution:

    # Function to check if brackets are balanced or not.
    def ispar(self, x):
        stack = []
        for char in s:

            if char in "({[":  # inserting in stack
                stack.append(char)
            elif char in ")}]":  # deleting from stack
                if not stack:
                    return False
                top = stack.pop()
                if (char == ')' and top != '(') or (char == '}' and top != '{') or (char == ']' and top != '['):
                    # if element not found, returning false
                    return False
        return not stack


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
        # n = int(input())
        # n,k = map(int,imput().strip().split())
        # a = list(map(int,input().strip().split()))
        s = str(input())
        obj = Solution()
        if obj.ispar(s):
            print("balanced")
        else:
            print("not balanced")
