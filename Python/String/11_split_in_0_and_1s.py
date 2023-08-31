"""
Idea:
Iterating each element, keeping count of 0's and 1's
Adding 1 to answer , each time count gets equal.
"""


class Solution:
    def maxSubStr(self, str):
        ans = zero = one = 0

        for i in range(len(str)):
            # keeping count of 0 & 1
            if str[i] == '0':
                zero += 1
            else:
                one += 1

            if zero == one:
                ans += 1

        if zero != one:  # if count of 0 and 1 weren't equal, return -1, as condition isn't satisfied
            return -1
        return ans


if __name__ == "__main__":
    for _ in range(int(input())):
        s = input()
        obj = Solution()
        ans = obj.maxSubStr(s)
        print(ans)
