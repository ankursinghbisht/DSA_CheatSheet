"""
Idea:
each overlapping case pair will have 2nd number greater than 1st number of other pair,
choosing other 2 elements as border elements will be the answer.
"""


class Solution:
    def mergeIntervals(self, intervals):
        # sorting the pairs for easy traversal
        intervals.sort()
        ans = []
        for interval in intervals:
            # checking if last element is smaller or not
            if not ans or ans[-1][1] < interval[0]:
                ans.append(interval)
            else:
                ans[-1][1] = max(ans[-1][1], interval[1])
        return ans


if __name__ == "__main__":
    T = int(input())
    for _ in range(T):
        nums = []
        n = int(input())
        for _ in range(n):
            x, y = map(int, input().split())
            nums.append([x, y])
        obj = Solution()
        merged_intervals = obj.mergeIntervals(nums)
