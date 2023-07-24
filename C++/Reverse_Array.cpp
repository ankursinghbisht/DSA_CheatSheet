#include<bits/stdc++.h>
using namespace std;




string reverseWord(string str)
{
    //reversing string, taking one character from first & last , and swapping till all are swapped
    int len = str.length();
    for (int i = 0;i < floor(len / 2);++i)
    {
        //swapping
        str[i] = str[i] + str[len - i - 1];
        str[len - i - 1] = str[i] - str[len - i - 1];
        str[i] = str[i] - str[len - i - 1];
    }
    return str;
}

void reverse_Through_Recurrsion(string& s, int low, int high)
{
    //reversing through recursion, passing string as reference & swapping one pair and calling function recursively
    if (high <= low)
        //stop call
        return;

    //swapping
    s[low] = s[low] + s[high];
    s[high] = s[low] - s[high];
    s[low] = s[low] - s[high];

    //recursively calling function with indices being pushed closer
    reverse_Through_Recurrsion(s, low + 1, high - 1);
}

void printString(string s)
{
    //printing string
    for (int i = 0;i < s.length();++i)
        cout << s[i] << " ";
    cout << "\n";
}



int main()
{
    string s = "abcd";
    len = s.length();

    //s=reverseWord(s);
    reverse_Through_Recurrsion(s, 0, length);
    printString(s);

    return 0;

}
