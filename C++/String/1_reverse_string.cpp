
#include<bits/stdc++.h>
using namespace std;



string reverseWord(string str) {

    string a = "";
    for (int i = str.length() - 1, j = 0;i > j;--i, ++j)
    {
        str[i] += str[j];
        str[j] = str[i] - str[j];
        str[i] -= str[j];
    }

    return str;
}

int main() {

    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.reverseWord(s) << endl;
    }
    return 0;

}
