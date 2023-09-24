"""
Idea: (Using idea of having prefix sum array)
Using dictionary to keep track of the cumulative sum of elements encountered so far and their frequencies.
incrementing  a count var - whenever the current cumulative sum matches a previous sum encountered,
effectively counting subarrays that sum to zero.
"""


class Solution:
    def findSubArrays(self, arr, n):
        mp = {}
        sum, count = 0, 0
        for i in range(n):
            sum += arr[i]
            if sum == 0:
                count += 1

            # If the current cumulative sum has been seen before, it means there is a subarray
            # from a previous point to the current point that sums to 0.
            if sum in mp:
                count += mp[sum]
                mp[sum] += 1
            else:
                mp[sum] = 1
        return count


if __name__ == '__main__':
    t = int(input())
    for tc in range(t):
        N = int(input())
        A = [int(x) for x in input().strip().split(' ')]
        ob = Solution()
        print(ob.findSubArrays(A, N))
