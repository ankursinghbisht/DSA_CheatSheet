"""
Idea:
Creating a Huffman Tree from input characters. & traverse tree maintain an auxiliary array.
 While moving to the left child, write 0 to the array.

Creating the Huffman Tree:
-Create a leaf node for each unique character and build a min heap of all leaf nodes
(Min Heap is used as a priority queue. The value of frequency field is used to compare two nodes in min heap. Initially,
 the least frequent character is at root)

-Extract two nodes with the minimum frequency from the min heap.

-Create a new internal node with a frequency equal to the sum of the two nodes frequencies.
 Make the first extracted node as its left child and the other extracted node as its right child.
  Add this node to the min heap.

-Repeat previous 2 steps until the heap contains only one node.
 The remaining node is the root node and the tree is complete.
"""


import heapq


class Solution:
    # Node class for the Huffman tree
    class Node:
        def __init__(self, value=0, ch='\0', left=None, right=None):
            self.value = value
            self.ch = ch
            self.left = left
            self.right = right

    #  Comparison method to define how instances of the Node class should be compared
        def __lt__(self, other):
            return self.value < other.value

    # Recursive function for traversing the Huffman tree and generating codes
    def preorder(self, root, s, ans):
        if root is None:
            return
        if root.ch != '0':
            ans.append(s)
        self.preorder(root.left, s + '0', ans)
        self.preorder(root.right, s + '1', ans)

    # Function to generate Huffman codes
    def huffmanCodes(self, S, f, N):
        # Priority queue for creating the Huffman tree
        pq = []
        root = None

        # Create nodes for each character and frequency, and push them into the priority queue
        for i in range(N):
            n = self.Node(f[i], S[i])
            heapq.heappush(pq, n)

        # Build the Huffman tree by merging nodes in the priority queue
        while len(pq) > 1:
            l = heapq.heappop(pq)
            r = heapq.heappop(pq)
            rt = self.Node(l.value + r.value, '0', l, r)
            heapq.heappush(pq, rt)

        # The top of the priority queue is the root of the Huffman tree
        root = pq[0]

        # List to store the generated Huffman codes
        ans = []

        # Generate Huffman codes using the recursive preorder function
        self.preorder(root, "", ans)

        # Return the generated Huffman codes
        return ans


# {
# Driver Code Starts
# Initial Template for Python 3


if __name__ == '__main__':
    t = int(input())
    for i in range(t):
        S = input()
        N = len(S)
        f = [int(x) for x in input().split()]
        ob = Solution()
        ans = ob.huffmanCodes(S, f, N)
        for i in ans:
            print(i, end=" ")
        print()
# } Driver Code Ends
