"""
Using LPS(Longest Prefix Suffix) array in KMP (Knuth Morris Pratt) algorithm
(used to find string inside a string)

Idea:
reversing and appending the string to itself, the last element of array will give number of elements already in palindromic order
return the rest of the element count.
"""


class Solution:
    def minChar(self, s):
        modified_str = s + '$' + s[::-1]

        # Calculate the KMP prefix table
        n = len(modified_str)
        prefix_table = [0] * n
        j = 0  # Length of the previous longest prefix suffix

        for i in range(1, n):
            while j > 0 and modified_str[i] != modified_str[j]:  # no match found; use the LPS value to backtrack j
                j = prefix_table[j - 1]

            if modified_str[i] == modified_str[j]:  # Match found, increment both pointers
                j += 1

            prefix_table[i] = j

        return len(s) - prefix_table[-1]


if __name__ == "__main__":
    for _ in range(int(input())):
        s = input()
        obj = Solution()
        ans = obj.minChar(s)
        print(ans)

