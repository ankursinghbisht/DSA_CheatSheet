"""
Question: find elements occurring more than n/k times, n=length, and k-constant
Idea:
Counting occurrences of each element, and checking if any surpass the threshold

"""
from collections import Counter


def elementsAppearance_using_inbuilt_function(arr, n, k):
    """
    Using python outing inbuilt function
    """
    x = n // k

    # Counting frequency of every element using Counter
    mp = Counter(arr)

    # Traverse the map and print all the elements with occurrence more than n/k times
    for it in mp:
        if mp[it] > x:
            print(it)


def elementsAppearance(arr, n, k):
    frequency = {}
    ans = []
    for i in range(n):
        # Counting each element's occurrences
        if arr[i] in frequency:
            frequency[arr[i]] += 1
        else:
            frequency[arr[i]] = 1

    # if count reaches threshold , append in result
    for i in frequency:
        if frequency[i] > n / k:
            ans.append(i)

    return ans


if __name__ == '__main__':
    a = [1, 1, 2, 2, 3, 5, 4, 2, 2, 3, 1, 1, 1]
    length = len(a)
    key = 4
    ans = (elementsAppearance(a, length, key))
    print(ans)
