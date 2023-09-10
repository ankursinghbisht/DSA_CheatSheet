"""
Idea:
keeping count of left & right brackets, and adding value of imbalance to ans
"""


# User function Template for python3
class Solution:
    def minimumNumberOfSwaps(self, S):
        countLeft = countRight = ans = imbalance = 0
        for i in range(len(S)):
            if S[i] == '[':
                countLeft += 1
                if imbalance > 0:
                    # If there is an imbalance, we need to swap brackets
                    ans += imbalance
                    imbalance -= 1
            elif S[i] == ']':
                countRight += 1
                imbalance = countRight - countLeft
        return ans


# code here


# {
# Driver Code Starts
# Initial Template for Python 3
if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        S = str(input())
        ob = Solution()
        print(ob.minimumNumberOfSwaps(S))
# } Driver Code Ends
