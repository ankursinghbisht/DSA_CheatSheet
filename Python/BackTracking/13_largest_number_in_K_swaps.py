"""
Idea:
using recursion for each index , finding max value element to replace it with till limit is reached
"""


# User function Template for python3

class Solution:

    # Function to compare two strings and updating res which stores the string with larger number.
    def match(self, num, res):

        for i in range(len(num)):
            if res[i] > num[i]:
                return

            # if num[i] is greater, we update res as num or store the larger value in res.
            if res[i] < num[i]:

                for i in range(len(num)):
                    res[i] = num[i]
                return

    # Function to set highest possible digits at given index.
    def setDigit(self, num, index, res, k):

        # base case
        if k == 0 or index == len(num) - 1:
            self.match(num, res)
            return

        maxDigit = 0

        # finding maximum digit for placing at given index.
        for i in range(index, len(num)):
            maxDigit = max(maxDigit, num[i])

        # swapping isn't needed in this case.
        if num[index] == maxDigit:
            self.setDigit(num, index + 1, res, k)
            return

        for i in range(index + 1, len(num)):

            # if max digit is found at current index.
            if num[i] == maxDigit:
                # swapping to get the maximum digit at required index.
                num[index], num[i] = num[i], num[index]

                # calling recursive function to set the next digit
                self.setDigit(num, index + 1, res, k - 1);

                # backtracking
                num[index], num[i] = num[i], num[index]

    # Function to find the largest number after k swaps.
    def findMaximumNum(self, s, k):

        num = [int(x) for x in s]
        res = [int(x) for x in s]

        self.setDigit(num, 0, res, k)
        # returning the result.
        return ''.join(str(x) for x in res)


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    for _ in range(int(input())):
        k = int(input())
        s = input()
        ob = Solution()
        print(ob.findMaximumNum(s, k))

# } Driver Code Ends
