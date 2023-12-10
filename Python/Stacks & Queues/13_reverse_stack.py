"""
Idea:
Recursing while popping top elements and storing in function call stack &
Inserting elements in bottom of stack.
[recursing till stack is empty (elements are stored in function call stack). inserting element and pushing rest elements]
"""

# User function Template for python3

from typing import List


class Solution:
    # Function to insert an element at the bottom of the stack
    def insert_at_bottom(self, stack, x):
        if not stack:
            # If the stack is empty, append the element and return
            stack.append(x)
            return

        # Pop the top element of the stack
        temp = stack.pop()

        # Recursively insert the element at the bottom
        self.insert_at_bottom(stack, x)

        # Append back the popped element after the recursive call
        stack.append(temp)

    # Function to reverse the elements of a stack
    def reverse(self, stack):
        if not stack:
            return  # If the stack is empty, return

        # Pop the top element of the stack
        num = stack.pop()

        # Recursively reverse the remaining elements of the stack
        self.reverse(stack)

        # Insert the popped element at the bottom of the reversed stack
        self.insert_at_bottom(stack, num)


# {
# Driver Code Starts

# Initial Template for Python 3


for _ in range(int(input())):
    N = int(input())
    St = list(map(int, input().split()))
    ob = Solution()
    ob.reverse(St)
    print(*St)
# } Driver Code Ends
