"""
Idea:
Hashing all unique characters of string, and using sliding windows technique to find the substring which
fits hash value of unique characters string. returning the length of shortest substring

"""




class Solution:
    def findSubString(self, s):
        # Get the length of the input string
        len1 = len(s)

        # Initialize an empty string to store unique characters
        pattern = ""

        # Create a set to store unique characters from the input string
        char_set = set()

        # Iterate through the input string to find unique characters
        for char in s:
            char_set.add(char)

        # Build the pattern string from unique characters
        for char in char_set:
            pattern += char

        # Get the length of the pattern
        len2 = len(pattern)

        # If the length of the input string is less than the pattern length, no valid window exists
        if len1 < len2:
            return 0

        # Initialize arrays to store character counts for the pattern and the current window
        hash_pattern = [0] * 256
        hash_string = [0] * 256

        # Count the occurrences of characters in the pattern
        for char in pattern:
            hash_pattern[ord(char)] += 1

        # Initialize variables for the sliding window algorithm
        start = 0
        start_index = -1
        ans = float('inf')
        count = 0

        # Iterate through the input string
        for i in range(len1):
            char = s[i]
            hash_string[ord(char)] += 1

            # If the character is part of the pattern and the count is less than or equal to the pattern count
            if hash_pattern[ord(char)] != 0 and hash_string[ord(char)] <= hash_pattern[ord(char)]:
                count += 1

            # If all characters in the pattern are found in the window
            if count == len2:
                # Shrink the window by moving the start index
                while hash_string[ord(s[start])] > hash_pattern[ord(s[start])]:
                    hash_string[ord(s[start])] -= 1
                    start += 1

                # Calculate the length of the current window
                len_window = i - start + 1

                # Update the minimum window length if necessary
                if ans > len_window:
                    ans = len_window
                    start_index = start

        # If no valid window is found, return 0; otherwise, return the minimum window length
        if start_index == -1:
            return 0

        return ans


def main():
    T = int(input())

    while T > 0:
        str = input()
        ob = Solution()
        print(ob.findSubString(str))

        T -= 1


if __name__ == "__main__":
    main()

# } Driver Code Ends