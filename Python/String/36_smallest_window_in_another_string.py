"""Idea:
The idea is to use the two pointer approach on the hash array of pattern string
and then find the minimum window by eliminating characters from the start of the window.
"""

import sys

NO_OF_CHARS = 256


# Define the number of characters in the character set (256 ASCII characters)

class Solution:
    def smallestWindow(self, str, pat):
        len1 = len(str)
        len2 = len(pat)

        # Check if the length of the input string is less than the length of the pattern
        if len1 < len2:
            return "-1"

        # Initialize arrays to store character frequencies in the pattern and the current window
        hash_pat = [0] * NO_OF_CHARS
        hash_str = [0] * NO_OF_CHARS

        # Calculate the frequency of each character in the pattern
        for c in pat:
            hash_pat[ord(c)] += 1

        start = 0  # Initialize the start of the window
        start_index = -1  # Initialize the starting index of the minimum window
        min_len = sys.maxsize  # Initialize the minimum window length to a large value
        count = 0  # Initialize a counter for characters matched

        for j in range(len1):
            hash_str[ord(str[j])] += 1

            # If the current character in the window is in the pattern, increment the count
            if hash_str[ord(str[j])] <= hash_pat[ord(str[j])]:
                count += 1

            # If all characters in the pattern are matched in the window
            if count == len2:
                # Shrink the window by removing unnecessary characters from the beginning
                while hash_str[ord(str[start])] > hash_pat[ord(str[start])] or hash_pat[ord(str[start])] == 0:
                    hash_str[ord(str[start])] -= 1
                    start += 1

                len_window = j - start + 1

                # Update the minimum window length and starting index if a smaller window is found
                if min_len > len_window:
                    min_len = len_window
                    start_index = start

        if start_index == -1:
            return "-1"

        return str[start_index: start_index + min_len]


if __name__ == '__main__':
    t = int(input())
    for i in range(t):
        s = str(input())
        p = str(input())
        ob = Solution()
        print(ob.smallestWindow(s, p))
