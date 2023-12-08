"""
Idea:
pushing all characters to stack and popping and inserting in string, will reverse it
"""


# {
# Driver Code Starts

def reverse(S):
    stack = []  # Using a list as a stack in Python
    length = len(S)
    # Inserting in stack
    for i in range(length):
        stack.append(S[i])

    i = 0
    s = ""
    # Popping from stack
    while stack:
        t = stack.pop()
        s += t
        i += 1

    return s


# {
# Driver Code Starts.
if __name__ == '__main__':
    t = int(input())
    for i in range(t):
        str1 = input()
        print(reverse(str1))
# } Driver Code Ends
