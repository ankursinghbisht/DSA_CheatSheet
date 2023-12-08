/*
Idea:
pushing all characters to stack and popping and inserting in string, will reverse it
*/

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
char* reverse(char* str, int len);
int main()
{
    long long int t;
    cin >> t;
    while (t--)
    {
        char str[10000];
        cin >> str;
        long long int len = strlen(str);
        char* ch = reverse(str, len);
        for (int i = 0;i < len;i++)
        {
            cout << ch[i];
        }
        cout << endl;
    }
    return 0;
}


// } Driver Code Ends


//return the address of the string
char* reverse(char* S, int len)
{
    stack<char>st;
    for (int i = 0;i < len;++i) //inserting in stack
        st.push(S[i]);

    int i = 0;
    while (!st.empty()) // popping from stack
    {
        char t = st.top();
        st.pop();
        S[i++] = t;
    }
    return S;
}