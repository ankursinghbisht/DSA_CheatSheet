/*
Idea:
Going from right to left, and adding respective value,
if previous element is greater than current, subtract( special case)
*/


#include <bits/stdc++.h>
using namespace std;



class Solution
{
public:
    int romanToDecimal(string& s)
    {
        unordered_map<char, int> romanDict = { {'I', 1},{'V', 5},{'X', 10},{'L', 50},{'C', 100},{'D', 500},{'M', 1000} };

        int result = 0;
        int prevValue = 0; // To keep track of the previous Roman numeral value

        for (int i = s.length() - 1; i >= 0; i--)  // Start from the right and move left
        {
            char symbol = s[i];
            int currentValue = romanDict[symbol];

            if (currentValue < prevValue)
                // If the current value is less than the previous value, subtract it
                result -= currentValue;
            else
                result += currentValue;
            prevValue = currentValue;
        }

        return result;
    }

};



int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.romanToDecimal(s) << endl;
    }
}
