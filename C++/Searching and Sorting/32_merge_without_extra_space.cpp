/*
Idea:
Separating elements which will be in first or second array in final answer,
then sorting individual elements.

Steps (while sorting after separating):
-setting up indices as last element of 1st array and first element of 2nd array
-traversing & swapping elements, if 1st array has larger elements
-sorting arrays

Steps (merging without sorting):
*/

#include<bits/stdc++.h>
using namespace std;


void merge_with_sorting(int arr1[], int arr2[], int n, int m)
{

    //setting up indices
    int i = n - 1, j = 0, temp;

    while (i > 0 && j < m)
    {
        //checkinf if any element in 1st array is bigger & swapping if any.
        if (arr1[i] >= arr2[j])
        {
            temp = arr1[i];
            arr1[i] = arr2[j];
            arr2[j] = temp;
        }
        ++j;
        --i;
    }
    sort(arr1, arr1 + n);
    sort(arr2, arr2 + m);

}

//helper function
void swap_if_greater(int arr1[], int arr2[], int index1, int index2)
{
    // function to check if element on first array is greater & swapping if any
    if (arr1[index1] > arr2[index2])
        swap(arr1[index1], arr2[index2]);

}

void merge_without_sorting(int arr1[], int arr2[], int n, int m)
{
    int len = n + m;
    int gap = len / 2 + len % 2;

    while (gap > 0)
    {
        int left = 0, right = left + gap;

        while (right < len)
        {

            if (left<n && right>n)
                //case 1: left element from arr1 & right from arr2
                swap_if_greater(arr1, arr2, left, right - n);
            else if (left > n && right > n)
                //case 2: both elements are from arr2
                swap_if_greater(arr2, arr2, left - n, right - n);
            else
                //case 3:both elements are from arr1
                swap_if_greater(arr1, arr1, left, right);
            ++left;
            ++right;
        }

        if (gap == 1)
            break;

        gap = gap / 2 + gap % 2; //updating gap value 
    }
}




int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, m;
        scanf("%d", &n);
        scanf("%d", &m);
        int* arr1;
        arr1 = (int*)malloc(n * sizeof(int));
        for (int i = 0;i < n;i++)
            scanf("%d", &arr1[i]);
        int* arr2;
        arr2 = (int*)malloc(m * sizeof(int));
        for (int i = 0;i < m;i++)
            scanf("%d", &arr2[i]);

        merge_without_sorting(arr1, arr2, n, m);
        for (int i = 0;i < n;i++)
            printf("%d ", arr1[i]);
        for (int i = 0;i < m;i++)
            printf("%d ", arr2[i]);
        printf("\n");
    }
    return 0;
}