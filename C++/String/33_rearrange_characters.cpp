/*
Idea:
put the highest frequency characters first & using priority queue to put all elements in order of their frequency
Inserting element & removing it from priority queue, temporarily. appending next highest frequency element, appending the removed element.
*/


#include<bits/stdc++.h>
using namespace std;
const int MAX_CHAR = 26;


class Solution
{
public:
    struct Key
    {
        int freq;
        char ch;

        // Function for priority_queue to store Key  according to freq
        bool operator<(const Key& k) const
        {
            return freq < k.freq;
        }
    };
    string rearrangeString(string str)
    {
        int n = str.size();

        int count[MAX_CHAR] = { 0 };
        for (int i = 0;i < n;++i)
            count[str[i] - 'a']++;

        priority_queue<Key> pq;

        //Insert all characters with their frequencies into a priority_queue
        for (char c = 'a';c <= 'z';++c)
        {
            int val = c - 'a';
            if (count[val])
                pq.push(Key{ count[val],c });
        }
        string ans = "";
        Key prev{ -1,'#' }; // work as the previous visited element

        while (!pq.empty())
        {
            Key k = pq.top();
            pq.pop();
            str = str + k.ch; // appending top value of priority queue

            if (prev.freq > 0)
                // IF frequency of previous character is less  than zero that means it is useless, 
                // so no need to insert in priority queue again
                pq.push(prev);

            k.freq--;
            prev = k;
        }

        // if resultant length is not equal to original, return false
        if (n != ans.size())
            return "-1";
        else
            return ans;
    }

};


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        Solution ob;
        string str1 = ob.rearrangeString(str);
        int flag = 1;
        int c[26] = { 0 };
        for (int i = 0; i < str.length(); i++)
            c[str[i] - 'a'] += 1;
        int f = 0;
        int x = (str.length() + 1) / 2;
        for (int i = 0; i < 26; i++)
        {
            if (c[i] > x)
                f = 1;
        }
        if (f)
        {
            if (str1 == "-1")
                cout << 0 << endl;
            else
                cout << 1 << endl;
        }
        else
        {
            int a[26] = { 0 };
            int b[26] = { 0 };
            for (int i = 0; i < str.length(); i++)
                a[str[i] - 'a'] += 1;
            for (int i = 0; i < str1.length(); i++)
                b[str1[i] - 'a'] += 1;

            for (int i = 0; i < 26; i++)
                if (a[i] != b[i])
                    flag = 0;

            for (int i = 0;i < str1.length();i++)
            {
                if (i > 0)
                    if (str1[i - 1] == str1[i])
                        flag = 0;
            }
            if (flag == 1)
                cout << "1\n";
            else
                cout << "0\n";
        }
    }
    return 0;
}
