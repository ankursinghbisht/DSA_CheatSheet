"""
Idea:
(while using map)
Iterating through each element, (assuming it being 1st element of 3sum)
-using loop after that element till array's end.
-checking if any element with value (k-arr[i]) is present in the map, if any, adds total count to answer
-adding the current element in map

(while using sorting)
-sorting the array
-iterating through the array, (assuming it being 1st element of 3sum)
-using another loop from i+1 to n-1
-checking if 2 pointers sum to ans
"""


def find3Numbers_usingMap(arr, n, X):
    for i in range(n):
        nums = {}
        sum = X - arr[i]
        for j in range(i + 1, n):
            # iterating through each value, and checking if elements in dictionary adds to X
            if (sum - arr[j]) in nums:
                return True
            else:
                # if value is not present in dictionary, insert one, else add one to it's count
                nums[arr[j]] = 1
    return False


def find3Numbers_usingSort(arr, n, X):
    arr.sort()

    for i in range(n):
        front = i + 1
        back = n - 1
        while front < back:
            if arr[front] + arr[back] == X - arr[i]:
                # if triplet found, return
                return True
            elif arr[front] + arr[back] > X - arr[i]:
                # if sum>ans, move pointer to front
                back -= 1
            else:
                # If sum<ans, move pointer to the back
                front += 1

    return False


if __name__ == '__main__':
    a = [1, 2, 4, 3, 6]
    find3Numbers_usingSort(a, 5, 10)
# } Driver Code Ends
