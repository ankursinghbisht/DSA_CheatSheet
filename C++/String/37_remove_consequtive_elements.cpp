/*
Idea:
appending only one unique character of a type, and recursively calling the function with remaining characters
*/


#include <bits/stdc++.h> 
using namespace std;



class Solution {
public:
    string removeConsecutiveCharacter(string S)
    {
        if (S.empty())
            return "";

        char firstChar = S[0];
        int index = 1;

        while (index < S.size() && S[index] == firstChar)
            index++; // getting to the last index of appearance of character in 1st place of string


        return firstChar + removeConsecutiveCharacter(S.substr(index));
    }
};



int main()
{
    int t = 1;
    //cin >> t;
    while (t--)
    {
        string s = "aabba";
        //cin >> s;
        Solution ob;
        cout << ob.removeConsecutiveCharacter(s) << endl;
    }
}


