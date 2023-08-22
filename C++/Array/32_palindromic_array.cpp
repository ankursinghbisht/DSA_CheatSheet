/*
Idea: Iterating through each element & finding if it's palindrome or not.
*/

#include<iostream>
#include<string.h>
using namespace std;



class Solution {
public:
    int PalinArray(int a[], int n)
    {
        int temp, num;
        for (int i = 0;i < n;++i)
        {
            temp = 0;
            num = a[i];
            while (num > 0)
            {
                temp = temp * 10 + num % 10;
                num /= 10;
            }
            if (temp != a[i])
                return false;
        }
        return true;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution obj;
        cout << obj.PalinArray(a, n) << endl;
    }
}