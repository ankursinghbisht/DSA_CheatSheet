"""
Idea:
iterating string & keeping track of each character, if it's already passed or not.
& keeping count of remaining computers, updating as character comes or leaves.
"""


class Solution:
    def solve(self, n, seq):
        # seen[i] = 0, indicates that customer 'i' is not in cafe
        # seen[1] = 1, indicates that customer 'i' is in cafe but computer is not assigned yet.
        # seen[2] = 2, indicates that customer 'i' is in cafe and has occupied a computer.

        seen = [0] * 26  # List to store entry/exit of characters
        res = 0
        occupied = 0

        for i in range(len(seq)):
            ind = ord(seq[i]) - ord('A')

            if seen[ind] == 0:  # If character hasn't entered
                seen[ind] = 1
                if occupied < n:  # If computers are available
                    occupied += 1
                    seen[ind] = 2
                else:
                    res += 1
            else:
                if seen[ind] == 2:  # If character has left
                    occupied -= 1
                seen[ind] = 0

        return res


for _ in range(int(input())):
    n = int(input())
    s = input().strip()
    ob = Solution()
    ans = ob.solve(n, s)
    print(ans)
