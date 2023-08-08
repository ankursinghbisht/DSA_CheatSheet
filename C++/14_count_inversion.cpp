/*
Idea:
Use Merge sort with modification that every time an unsorted pair is found,
increment count by one and return count at the end.
*/
#include <bits/stdc++.h>
using namespace std;


class Solution
{
public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long count(long long arr[], long long low, long long mid, long long high)
    {
        long long i = low, j = mid + 1, k = 0, inversion_count = 0;
        long long temp[high - low + 1];

        //sorting the values of actual array in temporary array
        while (i <= mid && j <= high)
        {
            if (arr[i] <= arr[j])
            {
                temp[k++] = arr[i++];
            }
            else
            {
                //if element in 1st array is bigger than 2nd, then rest of element will also be greater
                inversion_count += (mid - i + 1);
                temp[k++] = arr[j++];
            }
        }

        //setting up remaining elements
        while (i <= mid)
            temp[k++] = arr[i++];
        while (j <= high)
            temp[k++] = arr[j++];


        //copying temporary element's in actual array
        i = 0;
        k = low;
        while (k <= high)
        {
            arr[k++] = temp[i++];
        }

        return inversion_count;
    }

    long long mergeSort(long long arr[], long long low, long long high)
    {

        long long mid = low + (high - low) / 2;
        long long int ans = 0;
        if (low < high)
        {
            //calling itself till array has 0 elements

            ans += mergeSort(arr, low, mid);
            ans += mergeSort(arr, mid + 1, high);

            //calling count function to count number of inversions
            ans += count(arr, low, mid, high);
        }
        return ans;
    }

    long long int inversionCount(long long arr[], long long N)
    {
        //calling the actual function to count inversions
        long long int ans = mergeSort(arr, 0, N - 1);
        return ans;
    }

};



int main()
{

    long long T;
    cin >> T;

    while (T--) {
        long long N;
        cin >> N;

        long long A[N];
        for (long long i = 0;i < N;i++) {
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A, N) << endl;
    }
    return 0;
}
