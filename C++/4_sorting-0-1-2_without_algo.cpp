#include<bits/stdc++.h>
using namespace std;


class Solution
{
public:
    void sort012(int a[], int n)
    {
        //counting all the 0's , 1's and 2's
        int count0 = 0, count1 = 0, count2 = 0;

        for (int i = 0;i < n;++i)
            if (a[i] == 0)
                ++count0;
            else if (a[i] == 1)
                ++count1;
            else
                ++count2;

        //updating the array with total 0's , 1's and 2's
        for (int i = 0;i < n;++i)
            if (count0 > 0)
            {
                a[i] = 0;
                --count0;
            }
            else if (count1 > 0)
            {
                a[i] == 1;
                --count1;
            }
            else
                a[i] = 2;
    }

};


int main()
{
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0;i < n;i++) {
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for (int i = 0;i < n;i++) {
            cout << a[i] << " ";
        }

        cout << endl;


    }
    return 0;
}
