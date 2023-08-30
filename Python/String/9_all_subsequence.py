"""
Idea:
using choosing or not choosing , via recursion.
"""


class Solution:
    def printSubsequence(self, inputStr, outputStr=""):
        # Base Case, if the input is empty print the output string
        if not inputStr:
            print(outputStr, end=" ")
            return

        #  output is passed with including the Ist character of  Input string
        self.printSubsequence(inputStr[1:], outputStr + inputStr[0])
        # output is passed without  including the Ist character of Input string
        self.printSubsequence(inputStr[1:])


if __name__ == '__main__':
    T = int(input())
    for i in range(T):
        str = input()
        ob = Solution()
        ob.printSubsequence(str)
