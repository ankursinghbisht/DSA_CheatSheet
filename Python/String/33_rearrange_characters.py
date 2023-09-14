"""
Idea:
put the highest frequency characters first & using priority queue to put all elements in order of their frequency
Inserting element & removing it from priority queue, temporarily. appending next highest frequency element, appending the removed element.
"""
import heapq


class Solution:
    def rearrangeString(self, S):
        # Creating a dictionary to count the occurrences of each character in the string
        count = {}
        for c in S:
            count[c] = 0

        # Counting the occurrences of each character in the string
        for c in S:
            count[c] += 1

        # Creating a heap and storing the characters with their negative counts in the heap
        heap = []
        for (key, value) in count.items():
            heap.append([-value, key])

        # Converting the list into a min-heap
        heapq.heapify(heap)

        # Initializing a variable to keep track of the previous character and its count
        prev = [0, '#']

        # Initializing an empty string to store the rearranged string
        ans = ""

        # Repeatedly extracting the character with the highest count from the heap and appending it to the result string
        while len(heap) != 0:
            key2 = heapq.heappop(heap)
            ans += key2[1]

            # If the count of the previous character is still negative, push it back into the heap
            if -prev[0] > 0:
                heapq.heappush(heap, prev)
            key2[0] += 1
            prev = key2

        # Checking if the rearranged string has the same length as the input string
        if len(ans) == len(S):
            return ans
        else:
            return "-1"


if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        str1 = input()
        solObj = Solution()
        str2 = solObj.rearrangeString(str1)
        if str2 == '-1':
            print(0)
        elif sorted(str1) != sorted(str2):
            print(0)
        else:
            for i in range(len(str2) - 1):
                if str2[i] == str2[i + 1]:
                    print(0)
                    break
            else:
                print(1)

