/*
Idea:
store frequency of each elements for a1 & a2, if any element has more frequency in a2, than a1,
or any new element is found - return false
*/
#include <bits/stdc++.h>
using namespace std;

string isSubset(int a1[], int a2[], int n, int m)
{
    map <int, int>m1, m2;
    //Iterating in both arrays, and storing frequency of each element
    for (int i = 0;i < n;++i)
        m1[a1[i]]++;
    for (int i = 0;i < m;++i)
        m2[a2[i]]++;

    for (auto it : m2)
    {
        auto temp = m1.find(it.first);
        //checking if element is present in first map & it's frequency is under first occurence
        if (temp == m1.end() or it.second > temp->second)
            return "No";
    }
    return "Yes";
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;
        int a1[n], a2[m];

        for (int i = 0; i < n; i++) {
            cin >> a1[i];
        }
        for (int i = 0; i < m; i++) {
            cin >> a2[i];
        }

        cout << isSubset(a1, a2, n, m) << endl;
    }
    return 0;
}
