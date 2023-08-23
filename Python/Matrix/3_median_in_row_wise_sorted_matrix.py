"""
Idea: ( using binary search algorithm )
there will be n/2 elements smaller than median, finding the element with this attribute.

Steps:
-finding min & max value from the matrix
- assuming the median to be average of those values,
 finding elements in matrix which are smaller than assumption
-if elements are less than expected-increase min value to average, else max value to average.
"""


class Solution:
    def median(self, matrix, R, C):
        minVal = float('inf')
        maxVal = float('-inf')
        for i in range(R):
            # finding min & max value of the matrix by comparing first and last element of each row of matrix
            maxVal = max(maxVal, matrix[i][C - 1])
            minVal = min(minVal, matrix[i][0])

        less_than_median = (R * C + 1) // 2

        while minVal < maxVal:
            count = 0
            mid = minVal + (maxVal - minVal) // 2

            for i in range(R):
                # finding element smaller than mid value
                count += len([x for x in matrix[i] if x <= mid])

            # if count<target, shifting the min value, else shifting the max value.
            if count < less_than_median:
                minVal = mid + 1
            else:
                maxVal = mid
        return minVal


if __name__ == '__main__':
    ob = Solution()
    t = int(input())
    for _ in range(t):
        r, c = map(int, input().strip().split())
        matrix = [[0 for j in range(c)] for i in range(r)]
        for i in range(r):
            t = [int(el) for el in input().split()]
            for j in range(c):
                matrix[i][j] = t[j]
        ans = ob.median(matrix, r, c)
        print(ans)
