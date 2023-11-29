"""
Idea:
finding min no. of unwanted brackets, and using backtracking and dp, finding all possible valid strings.
"""


class Solution:
    def __init__(self):
        self.dp = {}  # Memoization table to store intermediate results

    def removeInvalidParentheses(self, s: str) -> List[str]:
        v = []
        cnt = self.solve(s)  # Find the minimum number of parentheses needed to make the string valid
        st = set()
        self.remove_invalid_parentheses(s, cnt, st)  # Remove excess parentheses recursively
        v.extend(list(st))  # Add valid strings to the result list
        print(cnt)  # Output the minimum number of parentheses needed (for debugging)
        return v

    def remove_invalid_parentheses(self, s: str, cnt: int, st: set) -> int:
        # If cnt is 0, it means we have removed the excess parentheses, now check validity
        if cnt == 0:
            minr = self.solve(s)
            # If the string is valid, add it to the result set
            if minr == 0:
                st.add(s)
                return 1
            return 0

        # If the current string is already in the memoization table, return the result
        if s in self.dp:
            return self.dp[s]

        # Try removing each parentheses and recurse
        for i in range(len(s)):
            if s[i] == ')' or s[i] == '(':
                left = s[:i]
                right = s[i + 1:]
                # Use setdefault to set a default value if the key is not already present in the dictionary
                self.dp.setdefault(left + right, self.remove_invalid_parentheses(left + right, cnt - 1, st))

        return self.dp.get(s, 0)

    def solve(self, s: str) -> int:
        cnt = 0
        stack = []
        # Count the minimum number of parentheses needed to make the string valid
        for char in s:
            if char == '(':
                stack.append('(')
            elif char == ')':
                if stack and stack[-1] == '(':
                    stack.pop()
                else:
                    stack.append(char)
        return len(stack)