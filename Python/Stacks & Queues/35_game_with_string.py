"""
Idea:
storing frequencies of each character, inserting in priority queue and updating frequencies and returning answer
"""

# User function Template for python3

import heapq


class Solution:
    def minValue(self, s, k):
        ans = 0

        # Dictionary to store the frequency of each character in the string.
        vc = {chr(i): 0 for i in range(ord('a'), ord('z') + 1)}

        # Count the frequency of each character in the string.
        for char in s:
            vc[char] += 1

        # Priority queue to store the negative frequencies in ascending order.
        q = [-freq for freq in vc.values() if freq > 0]
        heapq.heapify(q)

        # Perform k operations on the priority queue.
        while k > 0:
            # Get the top element from the priority queue.
            temp = -heapq.heappop(q)
            # Decrement its value and push it back to the priority queue.
            temp -= 1
            heapq.heappush(q, -temp)
            k -= 1

        # Calculate the minimum value after k operations.
        while q:
            # Get the top element from the priority queue.
            temp = -heapq.heappop(q)
            # Add the square of its value to the final answer.
            ans += temp * temp

        # Return the final answer.
        return ans


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        s = input()
        k = int(input())

        ob = Solution()
        print(ob.minValue(s, k))
# } Driver Code Ends