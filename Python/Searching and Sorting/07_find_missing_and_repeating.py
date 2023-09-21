"""
Idea:
While traversing, use the absolute value of every element as an index and make the value at this index negative to mark it visited.
If something is already marked negative then this is the repeating element.
To find the missing, traverse the array again and look for a positive value.
"""


class Solution:
    def findTwoElement(self, arr, n):
        ans = [0, 0]

        # finding repeating element, if any element through indexing is already negative, index is repeating element
        for i in range(n):
            if arr[abs(arr[i]) - 1] < 0:
                ans[0] = abs(arr[i])
            else:
                arr[abs(arr[i]) - 1] *= -1

        # finding missing element, any positive index element means , index is missing element
        for i in range(n):
            if arr[i] > 0:
                ans[1] = i + 1
                break
        return ans


if __name__ == '__main__':

    tc = int(input())
    while tc > 0:
        n = int(input())
        arr = list(map(int, input().strip().split()))
        ob = Solution()
        ans = ob.findTwoElement(arr, n)
        print(str(ans[0]) + " " + str(ans[1]))
        tc = tc - 1
