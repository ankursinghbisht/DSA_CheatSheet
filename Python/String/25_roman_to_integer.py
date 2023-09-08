"""
Idea:
Going from right to left, and adding respective value,
if previous element is greater than current, subtract( special case)
"""


class Solution:
    def romanToDecimal(self, s):
        roman_dict = {'I': 1, 'V': 5, 'X': 10, 'L': 50, 'C': 100, 'D': 500, 'M': 1000}
        result = 0
        prev_value = 0  # To keep track of the previous Roman numeral value

        for symbol in reversed(s):  # Start from the right and move left
            current_value = roman_dict[symbol]

            # If the current value is less than the previous value, subtract it
            if current_value < prev_value:
                result -= current_value
            else:
                result += current_value

            prev_value = current_value  # Update the previous value

        return result


if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        ob = Solution()
        S = input()
        print(ob.romanToDecimal(S))
