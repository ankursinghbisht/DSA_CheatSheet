"""
Idea: (using Boyer-Moore voting algorithm)
This algorithm works on the fact that if an element occurs more than N/2 times,
it means that the remaining elements other than this would definitely be less than N/2.

-Steps:
iterating each element, and a var 'count' . if count==0, keeping tally of the var at current index
if element is not same as element , reduce the count by 1.
and at last we check if element found has frequency more than half of size of array.

"""


class Solution:
    def majorityElement(self, A, N):
        global el
        count = 0

        for i in range(N):  # keeping count of element 'el'
            if count == 0:
                count += 1  # setting up the element to be traced
                el = A[i]
            elif A[i] != el:  # if element is same as 'el' , increase the count
                count -= 1
            else:
                count += 1  # else decreased the count var

        count = 0
        for i in range(N):
            if el == A[i]:
                count += 1

        if count > N / 2:  # checking if element 'el' has frequency more than size/2
            return el
        return -1


def main():
    T = int(input())
    while (T > 0):
        N = int(input())

        A = [int(x) for x in input().strip().split()]

        obj = Solution()
        print(obj.majorityElement(A, N))

        T -= 1


if __name__ == "__main__":
    main()
# } Driver Code Ends
