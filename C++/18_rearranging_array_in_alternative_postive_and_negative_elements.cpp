
/*

Rule- "not using any extra space"

Idea:

->for naive method:
(preserving the order of elements)
-checking if any element is out of order, and finding the next element to replace it with
& then right rotating array withing those 2 elements, to preserve the order

->efficient method:
(not preserving order of elements)
-shifting all negative elements to right & positive to left, and swapping every other positive element to negative


-> ( if extra space is allowed):
-using extra vector/array, using 2 pointers, one for storing positive& other for negative,
-iterating through original vector/array, placing positive using one point for positive and other for negative
*/
#include <bits/stdc++.h>
using namespace std;

void right_rotate(int arr[], int low, int high)
{
    int temp = arr[high];

    for (int i = high;i > low;--i)
        arr[i] = arr[i - 1];

    arr[low] = temp;
}

void rearrange_naive(int arr[], int n)
{
    int out_of_place = -1; //index to save which element is out of place

    for (int i = 0;i < n;++i)
    {
        if (i & 1)//index is odd(1,3,5), element should be positive
        {
            if (arr[i] < 0)
            {
                out_of_place = i;
                for (int k = i + 1;k < n;++k)
                    if (arr[k] >= 0)
                    {
                        //index found from where element need to swapped
                        right_rotate(arr, out_of_place, k);
                        break;
                    }
            }
        }
        else//index is even (0,2,4), element should be negative
        {
            if (arr[i] >= 0)
            {
                out_of_place = i;
                for (int k = i + 1;k < n;++k)
                    if (arr[k] < 0)
                    {
                        //index found from where element need to swapped
                        right_rotate(arr, out_of_place, k);
                        break;
                    }
            }
        }
    }
}
void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

void rearrange(int arr[], int n)
{
    int i = 0, j = n - 1, temp;

    //swapping all positive elements to left and negative to right
    while (i < j)
    {
        while (arr[i] >= 0 && i < n)
            ++i;
        while (arr[j] < 0 && j >= 0)
            --j;

        if (i < n && j >= 0 && i < j)
            swap(arr[i], arr[j]);
    }

    i = 0;
    j = n - 1;

    while (i < j)
    {
        if (!j & 1)
            //to check if last element is in right place, 
            --j;

        // as every other element will be in wrong place, we just need to swap them
        swap(arr[i], arr[j]);
        i += 2;
        j -= 2;
    }

}

void rearrange_with_space(int arr[], int n)
{
    int temp[n] = { 0 }; //declaring extra space to store elements
    int positive_index = 0, negative_index = 1; //using 2 pointers to store +ve and -ve elements

    for (int i = 0;i < n;++i)
    {
        //checking if element is positive or negative & storing with respective pointers
        if (arr[i] < 0)
        {
            temp[negative_index] = arr[i];
            negative_index += 2;
        }
        else
        {
            temp[positive_index] = arr[i];
            positive_index += 2;
        }
    }
    //replacing original array
    for (int i = 0;i < n;++i)
        arr[i] = temp[i];
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int arr[] = { 2, 3, -4, -1, 6, -9 };

    int n = sizeof(arr) / sizeof(arr[0]);

    rearrange(arr, n);
    //rearrange_with_space(arr, n);
    cout << "Rearranged array is \n";
    printArray(arr, n);

    return 0;
}
