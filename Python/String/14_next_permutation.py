"""
Idea: finding the first point from end, where two elements are in increasing order
once found, replace the latter element with next greater element and reversing the array
"""


class Solution:
    def nextPermutation(self, N, arr):
        i, j = N - 2, 0

        # Finding the first element (i) in decreasing order.
        while i >= 0:
            if arr[i] < arr[i + 1]:
                break
            i -= 1

        if i < 0:
            # If the array is in descending order, reverse it to get the next permutation.
            arr.reverse()
        else:
            # Finding the next greater element in the array after the pivot point (i).
            for j in range(N - 1, i, -1):
                if arr[j] > arr[i]:
                    break

            # Swap the elements at positions i and j.
            arr[i], arr[j] = arr[j], arr[i]

            # Reverse the rest of the array (elements after position i).
            arr[i + 1:] = arr[i + 1:][::-1]

        return arr


if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        N = int(input())
        arr = input().split()
        for i in range(N):
            arr[i] = int(arr[i])

        ob = Solution()
        ans = ob.nextPermutation(N, arr)
        for i in range(N):
            print(ans[i], end=" ")
        print()
