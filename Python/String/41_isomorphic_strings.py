"""
Idea:
keeping track of all chars who are mapped, and mapping new ones
Meanwhile checking if mapping is done correctly, else return false
"""


class Solution:
    # Function to check if two strings are isomorphic.
    def areIsomorphic(self, str1: str, str2: str) -> bool:
        m, n = len(str1), len(str2)

        if m != n:
            return False

        # Using a dictionary to store the mapping of characters from str1 to str2.
        char_map = {}
        # Using a set to keep track of visited characters in str2.
        marked = set()

        for i in range(n):
            # If the current character of str1 is seen for the first time in the map.
            if str1[i] not in char_map:
                # If the current character of str2 has already been mapped, one-to-one mapping is not possible.
                if str2[i] in marked:
                    return False

                # Marking the current character of str2 as visited.
                marked.add(str2[i])

                # Storing the mapping of current characters.
                char_map[str1[i]] = str2[i]
            # If this character has appeared before in str1, check if it maps to the same character in str2.
            elif char_map[str1[i]] != str2[i]:
                return False

        return True


if __name__ == '__main__':
    t = int(input())
    for i in range(t):
        s = str(input())
        p = str(input())
        ob = Solution()
        if ob.areIsomorphic(s, p):
            print(1)
        else:
            print(0)
