"""
Idea:
Iterating through array, keeping count of number of elements passed
- As MEDIAN, is middle elements of the resultant array, stopping once we reached the middle point
- Adding next lowest elements to the answer & returning.
"""


def findMidSum(ar1, ar2, n):
    sum = i = j = 0
    # finding the indices of arrays, which include elements which are median
    for count in range(1, n):
        if ar1[i] <= ar2[j]:
            i += 1
        else:
            j += 1

    # appending the smaller number to answer
    if ar1[i] < ar2[j]:
        sum += ar1[i]
        i += 1
    else:
        sum += ar2[j]
        j += 1
    # checking if element was last in array, if so, appending first element of last array
    if i == n:
        sum += ar2[0]
    elif j == n:
        sum += ar1[0]
    else:
        # else adding lower value from both the array indices.
        sum += min(ar1[i], ar2[j])

    return sum


if __name__ == "__main__":
    tc = int(input())
    while tc > 0:
        n = int(input())
        ar1 = list(map(int, input().strip().split()))
        ar2 = list(map(int, input().strip().split()))
        ans = findMidSum(ar1, ar2, n)
        print(ans)
        tc = tc - 1
