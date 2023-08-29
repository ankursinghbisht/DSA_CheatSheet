"""
Idea:
using 2 instances of a string and concatenating them,
checking if other string is in the concatenated string.

"""


def areRotations(string1, string2):
    sumString = string1 + string1
    if string2 in sumString:
        return True
    return False


# Driver code
if __name__ == "__main__":
    string1 = "AABCD"
    string2 = "BACDA"

    # Function call
    if areRotations(string1, string2):
        print("Strings are rotations of each other")
    else:
        print("Strings are not rotations of each other")

# This code is contributed by Bhavya Jain
