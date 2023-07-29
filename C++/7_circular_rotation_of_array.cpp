#include<bits/stdc++.h>
using namespace std;

/*
Selecting last element, shifting rest of elements to one space to left, and replacing first element of array
*/
void leftRotate(int* arr, int n)
{
    int last_element = arr[n - 1];

    //shifting each element
    for (int i = n - 1;i > 0;--i)
        arr[i] = arr[i - 1];

    arr[0] = last_element;
}

int main()
{
    int arr[] = { 9, 8, 7, 6, 4, 2, 1, 3 };
    int size = sizeof(arr) / sizeof(arr[0]);
    leftRotate(arr, size);
    for (int i = 0; i < size; i++)
        cout << arr[i] << ' ';
    cout << "\n";
    return 0;
}