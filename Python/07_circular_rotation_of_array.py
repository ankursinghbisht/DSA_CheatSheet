"""
Removing last element of array, and inserting it at start.
"""


def rotateArray(array):
    lastElement = array.pop()
    array.insert(0, lastElement)


if __name__ == "__main__":
    arr = [9, 8, 7, 6, 4, 2, 1, 3]
    rotateArray(arr)
    print(arr)
