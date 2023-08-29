/*
Idea:
using 2 instances of a string and concatenating them,
checking if other string is in the concatenated string.

*/
#include <bits/stdc++.h>
using namespace std;

bool areRotations(string str1, string str2)
{
    string sumString = str1 + str1;
    if (str1.size() != str2.size())
        return 0;
    return sumString.find(str2) != string::npos;
}

int main()
{
    string str1 = "AACD", str2 = "ACDA";

    // Function call
    if (areRotations(str1, str2))
        printf("Strings are rotations of each other");
    else
        printf("Strings are not rotations of each other");
    return 0;
}
