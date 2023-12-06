"""
Idea:
( each digit is at 1st place only k/(n-1)! times) , placing each digit at a time and Recursively call the function to find the remaining digits

"""



class Solution:
    def solve(self, n, k, fact, nums):
        # Base case: if n = 0, we have no more digits to use
        if n == 0:
            return ""

        # Calculate the quotient c for k divided by the factorial of n-1
        c = k // fact[n - 1] + 1

        # Initialize an empty string to store the result
        result = ""

        # Iterate over the list of numbers
        for i in range(len(nums)):
            # Decrement c if the current number is 0
            c -= (nums[i] == 0)

            # If c becomes 0 and the current number is 0, we have found the next digit
            if c == 0 and nums[i] == 0:
                # Set the current number to 1 (indicating it has been used)
                nums[i] = 1

                # Add the index + 1 to the result
                result += str(i + 1)

                # Break out of the loop since we have found the digit
                break

        # Recursively call the function to find the remaining digits
        return result + self.solve(n - 1, k % fact[n - 1], fact, nums)

    def kthPermutation(self, n: int, k: int) -> str:
        # Initialize a list to store the factorials
        fact = [1] * (n + 1)

        # Calculate the factorials from 1 to n
        for i in range(1, n + 1):
            fact[i] = i * fact[i - 1]

        # Initialize a list to keep track of used numbers
        nums = [0] * n

        # Call the solve function to find the kth permutation
        s = self.solve(n, k - 1, fact, nums)

        # Return the resulting string
        return s


# {
# Driver Code Starts
if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        N, K = map(int, input().split())

        obj = Solution()
        res = obj.kthPermutation(N, K)

        print(res)

# } Driver Code Ends