#include<bits/stdc++.h>
using namespace std;


/*
Methodology :
similar to quick sort, but here pivot point's value is set as 0.
swapping all elements greater than 0 to negative elements, till both pointers cross, i.e. array is solved
*/

void negativeToLeft(int* arr, int len)
{
    //array pointer is passed, that's why there is no return function
    int i = 0, j = len - 1;
    while (i < j)
    {
        if (arr[i] >= 0 && arr[j] < 0)
        {
            // swapping as we found positive element on left, and negative on right
            arr[i] += arr[j];
            arr[j] = arr[i] - arr[j];
            arr[i] = arr[i] - arr[j];
        }

        while (arr[i] < 0 && i < len)
            //checking if element on left side are negative, and moving on to next one
            ++i;
        while (arr[j] >= 0 && j >= 0)
            //checking if element on right side are positive, and moving on to previous one
            --j;
    }
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

        negativeToLeft(a, number_of_elements);
        for (int i = 0;i < number_of_elements;i++)
            cout << a[i] << " ";
    }
    return 0;
}