"""
Idea:
sorting array in ascending order, and using 2 pointer, from each end.
adding the difference between each pair of pointer values, (in case of odd length: adding remaining element)
"""


# User function Template for python3


def max_sum(arr, n):
    # Sort the array in ascending order
    arr.sort()

    # Initialize variables
    i, j, ans = 0, len(arr) - 1, 0
    flag = True

    # Iterate through the array
    while i < j:
        if flag:
            # Add the absolute difference between the last and first elements
            ans += (arr[j] - arr[i])
            i += 1
        else:
            # Add the absolute difference between the last and first elements
            ans += (arr[j] - arr[i])
            j -= 1
        # Toggle the flag for the next iteration
        flag = not flag

    # If the array has an odd length, add the remaining element
    if i == j:
        ans += arr[i] - arr[0]

    # Return the maximum sum
    return ans


# {
# Driver Code Starts
# Initial Template for Python 3


t = int(input())
for _ in range(0, t):
    n = int(input())
    # x=list(map(int,input().split()))
    # n=x[0]
    # k=x[1]
    arr = list(map(int, input().split()))
    ans = maxSum(arr, n)
    print(ans)

# } Driver Code Ends
