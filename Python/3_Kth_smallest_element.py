"""
Solution idea:
using methods of quick sort, and placing pivot point to its location
& checking if it is k-th smallest element, else search in its direction
"""


class Solution:
    def kthSmallest(self, array, l, r, k):

        pivot = array[l]  # choosing element whose position we need to find
        i = l + 1
        j = r
        while i <= j:
            if array[i] > pivot > array[j]:
                # swapping once we find element which is on opposite side of pivot element , once array is sorted
                array[i], array[j] = array[j], array[i]

            # getting to the element which is on opposite side of pivot element , once array is sorted
            while i < len(array) and array[i] < pivot:
                i += 1
            while j >= 0 and array[j] > pivot:
                j -= 1

        # sorted all elements which need to come before pivot point,
        # now swapping values of pivot point and value at index j

        array[l], array[j] = array[j], array[l]

        # shifting the search to the direction of k-th element
        if j < k - 1:
            return self.kthSmallest(array, j + 1, r, k)
        if j > k - 1:
            return self.kthSmallest(array, l, j - 1, k)

        # if we found element on k-th position, return
        return array[j]


if __name__ == '__main__':
    t = int(input())
    for tcs in range(t):
        n = int(input())
        arr = list(map(int, input().strip().split()))
        k = int(input())
        ob = Solution()
        print(ob.kthSmallest(arr, 0, n - 1, k))
