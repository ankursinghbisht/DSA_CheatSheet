#include<bits/stdc++.h>
using namespace std;



/*
Solution idea:
using methods of quick sort, and placing pivot point to it's location
& checking if it is k-th smallest element, else search in it's direction
*/




int kthSmallestElement(int* arr, int l, int r, int k)
{

    int pivot = arr[l], i = l + 1, j = r;
    int num1, num2, temp;
    while (i <= j)
    {

        if (arr[i] > pivot && arr[j] < pivot)
        {
            //swapping once we find element which is on opposite side of pivot element , once array is sorted
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }

        // getting to the element which is on opposite side of pivot element , once array is sorted
        while (arr[i] < pivot)
            ++i;
        while (arr[j] > pivot)
            --j;
    }

    //sorted all elements which need to come before pivot point,
    // now swapping values of pivot point and value at index j
    temp = arr[j];
    arr[j] = pivot;
    arr[l] = temp;


    // shifting the search to the direction of k-th element
    if (j < k - 1)
        return kthSmallestElement(arr, j + 1, r, k);
    if (j > k - 1)
        return kthSmallestElement(arr, l, j - 1, k);

    // if we found element on k-th position, return
    return arr[k - 1];
}


int main()
{
    int test_case;
    cin >> test_case;
    while (test_case--)
    {
        int number_of_elements;
        cin >> number_of_elements;
        int a[number_of_elements];

        for (int i = 0;i < number_of_elements;i++)
            cin >> a[i];

        int k;
        cin >> k;
        cout << kthSmallestElement(a, 0, number_of_elements - 1, k) << endl;
    }
    return 0;
}