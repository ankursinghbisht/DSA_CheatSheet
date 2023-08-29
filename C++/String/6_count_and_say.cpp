// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string countAndSay(int n)
    {
        if (n == 1)
            return "1";

        string s = "1";
        for (int i = 2; i <= n; ++i)
        {
            string temp = "";
            int count = 1, prev = s[0] - '0'; // Convert char to int

            for (int j = 1; j < s.size(); ++j)
            {
                if (prev == s[j] - '0') // Convert char to int
                    count++;
                else
                {
                    temp += to_string(count);
                    temp += to_string(prev);
                    count = 1; // Reset count
                }

                prev = s[j] - '0';
            }
            temp += to_string(count); // Append last count
            temp += to_string(prev);  // Append last prev
            s = temp;
        }
        return s;
    }
};



int main() {
    // Write C++ code here
    Solution ob;
    cout << ob.countAndSay(2);
}