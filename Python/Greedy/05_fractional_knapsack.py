"""
Idea:
sorting the array in decreasing order of ratio of value and weight,
adding the value till weight left is 0, and keeping portion of an element if needed.
"""


# User function Template for python3

class Item:
    def __init__(self, val, w):
        self.value = val
        self.weight = w


class Solution:

    # Function to get the maximum total value in the knapsack.
    def fractionalknapsack(self, W, Items, n):

        # taking variable for current weight in knapsack.
        curr_weight = 0
        curr_value = 0

        # sorting items on basis of value/weight ratio.
        Items = sorted(Items, key=lambda x: (x.value / x.weight), reverse=True)

        # iterating over all the items.
        for i in range(n):

            # if currweight + item's weight is less than or equal to W,
            # then we add the item's value to final value.
            if curr_weight + Items[i].weight <= W:
                curr_weight += Items[i].weight
                curr_value += Items[i].value

            # else we take the fraction of the that item's value based on the remaining weight in knapsack.
            else:
                accomodate = W - curr_weight
                value_added = Items[i].value * (accomodate / Items[i].weight)
                curr_value += value_added
                break

                # returning final value.
        return curr_value


# code here


# {
# Driver Code Starts
# Initial Template for Python 3
import atexit
import io
import sys

if __name__ == '__main__':
    test_cases = int(input())
    for cases in range(test_cases):
        n, W = map(int, input().strip().split())
        info = list(map(int, input().strip().split()))
        arr = [Item(0, 0) for i in range(n)]
        for i in range(n):
            arr[i].value = info[2 * i]
            arr[i].weight = info[2 * i + 1]

        ob = Solution()
        print("%.2f" % ob.fractionalknapsack(W, arr, n))

# } Driver Code Ends
