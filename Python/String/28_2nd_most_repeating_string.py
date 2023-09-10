"""
Idea:
using dictionary store frequencies of all strings
keeping track of highest & 2nd highest frequency value and string value .
"""


class Solution:
    def secFrequent(self, arr, n):
        freq = {}
        for i in range(n):
            # inserting in dictionary
            if arr[i] in freq:
                freq[arr[i]] += 1
            else:
                freq[arr[i]] = 1

        max1 = max2 = float("-inf")
        string1 = string2 = ""

        for key, value in freq.items():
            # finding max & 2nd max frequency strings
            if value > max1:
                string2 = string1
                max2 = max1

                max1 = value
                string1 = key

            elif value > max2 and key != string1:
                max2 = value
                string2 = key
        return string2


if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        n = int(input().strip())
        arr = input().strip().split(" ")
        ob = Solution()
        ans = ob.secFrequent(arr, n)
        print(ans)
