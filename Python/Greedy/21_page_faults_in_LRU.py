"""
Idea:
using list/vector to simulate cache. iterating the array and counting total page faults with inserting new pages.
"""


# User function Template for python3

class Solution:
    def pageFaults(self, N, C, pages):
        page_fault_count = 0  # Counter for page faults
        cache = []  # List to simulate the cache

        for i in range(N):
            # Check if the page is present in the cache
            page_index = next((index for index, page in enumerate(cache) if page == pages[i]), None)

            # Page fault
            if page_index is None:
                page_fault_count += 1

                # If the cache is full, remove the page at the front
                if len(cache) == C:
                    cache.pop(0)

                # Add the new page to the end of the cache
                cache.append(pages[i])
            else:
                # If the page is present, move it to the end of the cache
                cache.pop(page_index)
                cache.append(pages[i])

        return page_fault_count  # Return the total number of page faults


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        N = int(input())
        pages = input().split()
        for itr in range(N):
            pages[itr] = int(pages[itr])
        C = int(input())

        ob = Solution()
        print(ob.pageFaults(N, C, pages))

# } Driver Code Ends
