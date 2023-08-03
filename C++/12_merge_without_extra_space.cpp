/*
Idea:
Separating elements which will be in first or second array in final answer,
then sorting individual elements.

Steps:
-setting up indices as last element of 1st array and first element of 2nd array
-traversing & swapping elements, if 1st array has larger elements
-sorting arrays
*/

#include<bits/stdc++.h>
using namespace std;

void merge(int arr1[], int arr2[], int n, int m)
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

        merge(arr1, arr2, n, m);
        for (int i = 0;i < n;i++)
            printf("%d ", arr1[i]);
        for (int i = 0;i < m;i++)
            printf("%d ", arr2[i]);
        printf("\n");
    }
    return 0;
}