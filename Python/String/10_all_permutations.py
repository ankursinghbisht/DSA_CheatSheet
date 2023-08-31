"""
Idea:
using backtracking , find all possible permutations of string
"""


class Solution:
    def all_permutation(self, input_str, low, high, st):

        # base case
        if low > high:
            st.add(input_str)
            return

        for i in range(low, high + 1):
            # at each iteration, swapping two characters , and calling the function again

            input_str_list = list(input_str)
            input_str_list[low], input_str_list[i] = input_str_list[i], input_str_list[low]
            new_input = ''.join(input_str_list)

            self.all_permutation(new_input, low + 1, high, st)

            input_str_list[low], input_str_list[i] = input_str_list[i], input_str_list[low]  # backtrack

    def find_permutation(self, S):
        st = set()  # using set for any duplicates
        ans = []
        self.all_permutation(S, 0, len(S) - 1, st)

        for item in st:
            ans.append(item)

        return ans


if __name__ == '__main__':
    t = int(input())
    for i in range(t):
        S = input()
        ob = Solution()
        ans = ob.find_permutation(S)
        ans.sort()
        for i in ans:
            print(i, end=" ")
        print()
