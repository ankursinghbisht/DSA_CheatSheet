"""
Idea:
using dictionary to store frequency of all characters in 2 strings
-checking if 2nd string has all elements with same frequency & if any element is extra.
"""


def validShuffle(str1, str2, shuffle):
    len1 = len(str1)
    len2 = len(str2)
    len3 = len(shuffle)
    if len1 + len2 != len3:
        # checking if sum of lengths are equal
        return False
    frequency = {}  # declaring dictionary

    # appending frequencies of all characters
    for i in range(len1):
        if str1[i] not in frequency:
            frequency[str1[i]] = 1
        else:
            frequency[str1[i]] += 1
    for i in range(len2):
        if str2[i] not in frequency:
            frequency[str2[i]] = 1
        else:
            frequency[str2[i]] += 1

    for i in range(len3):
        # checking if element is present in dictionary or not
        if shuffle[i] not in frequency or frequency[shuffle[i]] == 0:
            return False
        else:
            frequency[shuffle[i]] -= 1

    return True


str1 = "BA"
str2 = "XY"
shuffle = "ABYY"

if validShuffle(str1, str2, shuffle):
    print("YES")
else:
    print("NO")
