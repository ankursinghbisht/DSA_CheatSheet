"""
Idea:
Iterating from 1 to 'n' , with each iteration making a new string by using current string elements.

"""


class Solution:
    def countAndSay(self, n: int) -> str:
        if n == 1:
            return "1"

        s = "1"
        for i in range(2, n + 1):
            # with each iteration, counting & saying the elements
            temp = ""
            count = 1
            prev = int(s[0])  # Convert char to int

            for j in range(1, len(s)):
                if prev == int(s[j]):
                    count += 1
                else:
                    temp += str(count)
                    temp += str(prev)
                    count = 1  # Reset count

                prev = int(s[j])

            temp += str(count)  # Append last count
            temp += str(prev)  # Append last prev
            s = temp

        return s


if __name__ == "__main__":
    ob = Solution()
    print(ob.countAndSay(4))
