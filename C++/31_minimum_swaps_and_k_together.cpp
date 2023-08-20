
/*
Idea: (using sliding windows technique)
Calculating total variables smaller than k, to get window length.
starting from index 0, calculate how many elements are greater than k in particular windows
-slide window at each iteration & checking if unwanted elements are least, (that will be the answer)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minSwap(int arr[], int n, int k)
    {
        int i, count = 0; //total elements smaller than k 
        int j, bad = 0; // it stores total numbers greater than k
        for (i = 0;i < n;++i)
            if (arr[i] <= k)
                ++count;

        for (i = 0;i < count;++i)
            if (arr[i] > k)
                ++bad;

        i = count;
        j = 0;
        int ans = bad;

        while (i < n)
        {
            //iterating in array using 2 pointers, if pointer pointing behind has value greater than k,
            // decrease the 'bad' variable, as total unwanted elements will decrease by 1, if we shift window
            if (arr[i++] > k)
                ++bad;

            //increasing 'bad' variable if pointer ahead has greater value than k,
            // as total unwanted elements will increase if we shift the windows
            if (arr[j++] > k)
                --bad;

            ans = min(ans, bad);
        }
        return ans;


    }
};


int main() {

    int t, n, k;
    cin >> t;
    while (t--)
    {
        cin >> n;
        int arr[n];
        for (int i = 0;i < n;i++)
            cin >> arr[i];
        cin >> k;
        Solution ob;
        cout << ob.minSwap(arr, n, k) << "\n";
    }
    return 0;
}
