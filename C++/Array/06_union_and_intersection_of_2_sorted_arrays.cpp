#include <bits/stdc++.h>
using namespace std;

/*
Idea:
Union: if element is smaller, print and go to next index, if both elements are same, print only one, and go to
next element of both array. At the end, go through both array's remaining elements( if any ).
Intersection: if element is smaller, go to next index, if both elements are same, print only one, and go to
next element of both array.
*/
void findUnion(int* a, int* b, int m, int n)
{
    int i = 0, j = 0;
    while (i < m && j < n)
    {
        //checking if elements are equal or smaller to change indices
        if (a[i] < b[j])
            cout << a[i++] << " ";
        else if (a[i] > b[j])
            cout << b[j++] << " ";
        else
        {
            //printing only 1 element, when both elements are same
            cout << a[i++] << " ";
            ++j;
        }
    }
    //printing remaining elements
    while (i < m)
        cout << a[i++] << " ";
    while (j < n)
        cout << b[j++] << " ";
    cout << "\n";
}

void findIntersection(int* a, int* b, int m, int n)
{
    int i = 0, j = 0;
    while (i < m && j < n)
    {
        //checking if elements are equal or smaller to change indices
        if (a[i] < b[j])
            ++i;
        else if (a[i] > b[j])
            ++j;
        else
        {
            //printing only 1 element, when both elements are same
            cout << a[i++] << " ";
            ++j;
        }
    }
    cout << "\n";
}

int main()
{
    int arr1[] = { 1, 2, 4, 5, 6 };
    int arr2[] = { 2, 3, 5, 7 };

    int m = sizeof(arr1) / sizeof(arr1[0]);
    int n = sizeof(arr2) / sizeof(arr2[0]);

    findIntersection(arr1, arr2, m, n);
    findUnion(arr1, arr2, m, n);

    return 0;
}