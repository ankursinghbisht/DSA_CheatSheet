/*
Idea:
sorting the array, iterating the array with 2 indices i=0 & j=1.
take two index variables i and j, and initialize them as 0 and 1 respectively.
Now run a linear loop. If arr[j] – arr[i] is smaller than n, we need to look for greater arr[j], so increment j.
If arr[j] – arr[i] is greater than n,
we need to look for greater arr[i], so increment i.
*/

#include<bits/stdc++.h>

using namespace std;


bool findPair(int arr[], int size, int n);

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int l, n;
        cin >> l >> n;
        int arr[l];
        for (int i = 0;i < l;i++)
            cin >> arr[i];
        if (findPair(arr, l, n))
            cout << 1 << endl;
        else cout << "-1" << endl;
    }


    return 0;
}

bool findPair(int arr[], int size, int n)
{
    sort(arr, arr + size);

    int i = 0, j = 1;
    while (i < size && j < size)
        if (i != j && abs(arr[j] - arr[i]) == n) // if elements are matched, returning true
            return true;
        else if (arr[j] - arr[i] < n) // if difference is less than 'n' , increasing the front pointer
            ++j;
        else
            ++i;  // else increasing the back pointer

    return false;

}