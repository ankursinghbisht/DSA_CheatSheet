#include<bits/stdc++.h>
using namespace std;




pair<int, int> findMinMax(int* arr, int arr_size)
{
    pair <int, int> minMax;
    if (arr_size > 1)
    {
        // if length of array is more than 1
        if (arr[0] < arr[1])
        {
            minMax.first = arr[0];
            minMax.second = arr[1];
            //assigning lower value to first element of pair
        }
        else
        {
            minMax.first = arr[1];
            minMax.second = arr[0];
            //assigning lower value to first element of pair
        }
    }
    else
    {
        minMax.first = minMax.second = arr[0];
        return minMax;
    }

    //iterating through array and finding min & max
    for (int i = 2;i < arr_size - 1;++i)
    {
        if (arr[i] > minMax.second)
            // number is bigger than current max
            minMax.second = arr[i];
        else if (arr[i] < minMax.first)
            // number is smaller than current min
            minMax.first = arr[i];
    }

    return minMax;
}

int main()
{
    pair <int, int> minMax;
    int arr[] = { 1000, 11, 445, 1, 330, 3000 };
    int arr_size = 6;

    minMax = findMinMax(arr, arr_size);
    cout << minMax.first << " - " << minMax.second;
    return 0;
}
