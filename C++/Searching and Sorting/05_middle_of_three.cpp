/*
Idea: (for minimum no. of comparisons)
using min & max functions to find the rest element
*/


#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int middle(int a, int b, int c)
    {
        int smallest = min(min(a, b), c);
        int largest = max(max(a, b), c);
        int middle = a + b + c - smallest - largest;
        return middle;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int A, B, C;
        cin >> A >> B >> C;
        Solution ob;
        cout << ob.middle(A, B, C) << "\n";
    }
    return 0;
}