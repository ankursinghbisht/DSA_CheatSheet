"""
Idea:
There are n+1 positive elements & only 1 element is repeated.
Starting from index 0, going to element at value of that index and marking that element negative.
We'll get one positive element ( as one element is repeating)
"""

def find_Duplicate_Element(arr):
    return arr[0]


if __name__ == '__main__':
    array=[ 3,1,3,4,2]
    ans=find_Duplicate_Element(array)
    print(ans)
