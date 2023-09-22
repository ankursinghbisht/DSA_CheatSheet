/*
Idea:
start comparing from the leftmost element and find the difference between the current array element and x.
Let this difference be ‘diff’.
From the given property of the array, we always know that x must be at least ‘diff/k’ away,
so instead of searching one by one, we jump ‘diff/k’.
*/
#include<bits/stdc++.h>
using namespace std;

int search(int arr[], int n, int x, int k);


int main()
{
    int t, n, k, x;
    cin >> t;
    while (t--)
    {

        cin >> n >> k;
        int arr[n];
        for (int i = 0;i < n;i++)
            cin >> arr[i];
        cin >> x;
        cout << search(arr, n, x, k) << endl;

    }
    return 0;
}


// x is the element to be searched in arr[0..n-1]
// such that all elements differ by at-most k.
int search(int arr[], int n, int x, int k)
{
    int i = 0;
    while (i < n)
    {
        if (arr[i] == x)
            return i;

        // jumping diff/k instead of 1, if it's greater 
        i = i + max(1, abs(arr[i] - x) / k);
    }

    return -1;
}