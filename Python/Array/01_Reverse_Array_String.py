"""
-Reason for not using swapping in strings-strings are immutable in python, not allowing item assignment

-Mutable objects passed in the function are passed as reference, & non-mutable are passed as value

-Mutable objects: contents inside can be changed. (list, dictionary,sets)
-Immutable objects: contents once declared can't be changed, can only redeclare.(string, integer)
"""


def reverse_String(text):
    # started with empty string, traversing original string in reverse order & appended each character
    return_Val = ""
    for i in range(len(text) - 1, -1, -1):  # i goes from length of string -> 0
        return_Val += text[i]
    return return_Val


def recursion_Reverse_String(text, index):
    # recursively calling the same function with its pointer, if it goes beyond scope, return
    if index < 0:
        return ''
    return text[index] + recursion_Reverse_String(text, index - 1)  # append the character and return


def reverse_Array(array):
    # going from first to middle element one by one, and swapping respective term from last of array
    length = len(array)
    for i in range(length // 2):
        array[i], array[length - 1 - i] = array[length - 1 - i], array[i]  # swapping elements
    return array


def recursion_Reverse_Array(array, low, high):
    # using 2 pointers, once both pass each other, we've reversed the array
    if low > high:
        return
    array[low], array[high] = array[high], array[low]  # swapping elements
    return array


if __name__ == "__main__":
    word = 'abcd'
    print(recursion_Reverse_String(word, len(word) - 1))
    print(reverse_String(word))

    A = [1, 2, 3, 4]
    print(reverse_Array(A))
    print(recursion_Reverse_Array(A, 0, len(A) - 1))
