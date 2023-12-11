"""
Idea:
pushing opening bracket and operators in a stack.
While encountering closed brackets, if top element is opening bracket-then there is redundancy
"""


class Solution():

    def checkRedundancy(self, s):
        stack = []

        for char in s:
            if char in {'(', '+', '-', '*', '/'}:
                stack.append(char)
            elif char == ')':
                # Check for redundancy when encountering ')'
                if stack and stack[-1] == '(':
                    return 1  # Redundant expression found

                # Pop operators until '(' is found
                while stack and stack[-1] != '(':
                    stack.pop()

                # Remove the '(' from the stack
                if stack:
                    stack.pop()

        return 0  # No redundancy found


# {
# Driver Code Starts

if __name__ == "__main__":
    for _ in range(int(input())):
        s = input()
        print(Solution().checkRedundancy(s))

# } Driver Code Ends