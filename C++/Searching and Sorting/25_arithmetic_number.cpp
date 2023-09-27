/*
Idea:
Checking all test cases:
-if both elements are equal
-if common diff is 0
-if target is smaller than initial , but common diff > 0
-if target is greater than initial , but common diff < 0
*/


#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int inSequence(int a, int b, int c)
    {
        // code here
        if (a == b) // if both numbers are equal
        {
            return 1;
        }
        if (c == 0)
        {// if Common Difference is 0, elements must be equal
            if (a == b)
                return 1;
            return 0;
        }
        if ((b - a) % c == 0) // if difference between target and initial element is divisible by CD.
        {
            //checking both test cases where target>initial and CD>0 & target<initial & CD<0
            if (a < b && c>0)
                return 1;
            if (a > b && c < 0)
                return 1;
        }
        return 0;
    }
};



int main() {
    int t;
    cin >> t;
    while (t--) {
        int A, B, C;
        cin >> A >> B >> C;

        Solution ob;
        cout << ob.inSequence(A, B, C) << endl;
    }
    return 0;
}