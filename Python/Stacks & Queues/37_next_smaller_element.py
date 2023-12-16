"""
Idea: ( using stack )
store the indices of elements for which we have to find the next smaller element in a stack and
while traversing the array, if we find a greater element,
we will pair it with the elements from the stack till the top element of the stack is less than the current element.
"""


# User function Template for python3

class Solution:
    def help_classmate(self, arr, n):
        # Stack to keep track of indices of elements.
        st = []
        # Initialize the answer array with -1.
        ans = [-1] * n

        # Iterate through the array to find the next smaller element.
        for i in range(n):
            # Pop elements from the stack while the current element is smaller.
            while st and arr[st[-1]] > arr[i]:
                ans[st.pop()] = arr[i]

            # Push the current element's index onto the stack.
            st.append(i)

        # Return the answer array.
        return ans


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    for _ in range(int(input())):
        n = int(input())
        arr = [int(x) for x in input().split()]
        obj = Solution()
        result = obj.help_classmate(arr, n)
        for i in result:
            print(i, end=' ')
        print()

# } Driver Code Ends
