/*
Idea:
Any number with factorial with 'n' following zeroes must have 'n' 5 in it
To solve:
finding element with 'n' 5 in it's factorial

Steps:
Declaring low & high as 0 & 5* 'n' as,the maximum value whose factorial contain n trailing zeroes is 5*n.
doing binary serach between it, and finding minimum val with 'n' 0s.
*/

#include <bits/stdc++.h>
using namespace std;


class Solution
{
public:

    //Return true if number's factorial contains at least n trailing zero else false.
    bool check(int p, int n)
    {
        int temp = p, count = 0, f = 5;
        while (f <= temp) // counts no. of factorial 5 present in factorial of 'p'
        {
            count += temp / f;
            f *= 5;
        }
        return (count >= n);
    }

    // Return smallest number whose factorial contains at least n trailing zeroes
    int findNum(int n)
    {
        if (n == 1)
            return 5;
        int low = 0, high = 5 * n, mid; //the maximum value whose factorial contain n trailing zeroes is 5*n.
        while (low < high)
        {
            mid = (high + low) >> 1; //finding mid of high & low
            if (check(mid, n)) // if mid has factorial with atleast n trailing 0s, finding smaller number with same
                high = mid;
            else
                low = mid + 1;
        }
        return low;
    }

};

//{ Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.findNum(n) << endl;
    }
    return 0;
}
// } Driver Code Ends