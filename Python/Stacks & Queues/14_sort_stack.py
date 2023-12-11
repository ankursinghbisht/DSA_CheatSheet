"""
Idea:
Recursing while popping top elements and storing in function call stack &
Inserting elements at top if all below elements are smaller
[recursing till stack is empty or is smaller than target(elements are stored in function call stack).
inserting element and pushing rest elements]
"""


class Solution:
    def Sorted(self, s):
        # Base case: if stack is not empty
        if s:
            # Remove the top element and recursively sort the remaining stack
            x = s.pop()
            self.Sorted(s)

            # Insert the removed element back into the stack in a sorted manner
            self.sorted_insert(s, x)

    # Function to insert the element x in a sorted manner into the stack s
    def sorted_insert(self, s, x):
        # If stack is empty or the element is greater than the top element, push it
        if not s or x > s[-1]:
            s.append(x)
            return

        # Remove the top element and recursively insert the element in the remaining stack
        temp = s.pop()
        self.sorted_insert(s, x)

        # Push back the removed element to its original position in the stack
        s.append(temp)


#{
 # Driver Code Starts

if __name__=='__main__':
    t = int(input())
    for i in range(t):
        n = int(input())
        arr = list(map(int, input().strip().split()))
        ob = Solution()
        ob.Sorted(arr)
        for e in range(len(arr)):
            print(arr.pop(), end=" ")
        print()


# } Driver Code Ends