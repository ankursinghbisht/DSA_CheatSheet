"""
Idea:
Union: if element is smaller, print and go to next index, if both elements are same, print only one, and go to
next element of both array. At the end, go through both array's remaining elements( if any ).
Intersection: if element is smaller, go to next index, if both elements are same, print only one, and go to
next element of both array.
"""


def findUnion(arr1, arr2, len1, len2):
    i = j = 0
    ans = []
    while i < len1 and j < len2:
        # checking if elements are equal or smaller to change indices
        if arr1[i] < arr2[j]:
            ans.append(arr1[i])
            i += 1
        elif arr1[i] > arr2[j]:
            ans.append(arr2[j])
            j += 1
        else:
            # appending only 1 element, when both elements are same
            ans.append(arr1[i])
            i += 1
            j += 1

    # appending remaining elements
    while i < len1:
        ans.append(arr1[i])
        i += 1
    while j < len2:
        ans.append(arr2[j])
        j += 1
    print(ans)


def findIntersection(arr1, arr2, len1, len2):
    i = j = 0
    ans = []
    while i < len1 and j < len2:
        # checking if elements are equal or smaller to change indices
        if arr1[i] < arr2[j]:
            i += 1
        elif arr1[i] > arr2[j]:
            j += 1
        else:
            # appending only 1 element, when both elements are same
            ans.append(arr1[i])
            i += 1
            j += 1

    print(ans)


if __name__ == '__main__':
    arr1 = [1, 2, 4, 5, 6]
    arr2 = [2, 3, 5, 7]
    findUnion(arr1, arr2, len(arr1), len(arr2))
    findIntersection(arr1, arr2, len(arr1), len(arr2))
