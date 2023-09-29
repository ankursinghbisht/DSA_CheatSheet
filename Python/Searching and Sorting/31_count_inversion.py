"""
Idea:
Use Merge sort with modification that every time an unsorted pair is found,
increment count by one and return count at the end.
"""


class Solution:
    # User function Template for python3

    # arr[]: Input Array
    # N : Size of the Array arr[]
    # Function to count inversions in the array.
    def inversionCount(self, arr):
        if len(arr) > 1:
            # Finding the mid of the array
            mid = len(arr) // 2

            # Dividing the array elements
            L = arr[:mid]
            R = arr[mid:]

            # Sorting the first half
            inversions_left = self.inversionCount(L)

            # Sorting the second half
            inversions_right = self.inversionCount(R)

            i = j = k = 0
            inversions = inversions_left + inversions_right

            # Copy data to temp arrays L[] and R[]
            while i < len(L) and j < len(R):
                if L[i] <= R[j]:
                    arr[k] = L[i]
                    i += 1
                else:
                    arr[k] = R[j]
                    j += 1
                    inversions += len(L) - i
                    # Counting inversions when R[j] is smaller than elements in L
                    # as if element in 1st array is bigger than 2nd, then rest of element will also be greater
                k += 1

            # Checking if any element was left
            while i < len(L):
                arr[k] = L[i]
                i += 1
                k += 1

            while j < len(R):
                arr[k] = R[j]
                j += 1
                k += 1

            return inversions

        return 0


if __name__ == '__main__':
    t = int(input())
    for tt in range(t):
        a = list(map(int, input().strip().split()))
        obj = Solution()
        print(obj.inversionCount(a))
