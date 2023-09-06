"""
Idea:
keeping track of opening and closing brackets, if closing exceeds opening, reverse it, and update values
"""


def countRev(s):
    # your code here
    n = len(s)
    opening = 0
    closing = 0
    ans = 0

    # If the string length is odd, it can't be balanced
    if n % 2 != 0:
        return -1

    for i in range(n):
        if s[i] == '{':
            opening += 1
        else:
            closing += 1

        # If there are more closing brackets than opening, reverse one of each
        if closing > opening:
            opening += 1
            closing -= 1
            ans += 1

    # Return the total number of reversals needed to balance
    return ans + (opening - closing) // 2


t = int(input())
for tc in range(t):
    s = input()
    print(countRev(s))
