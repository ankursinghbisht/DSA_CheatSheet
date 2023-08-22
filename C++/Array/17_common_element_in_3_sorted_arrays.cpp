/*
Idea:
-moving index of each array only if the element is smallest.
-storing the last inserted element in answer list, to check if any repetition is happening,
as it's sorted , we  only need to store last element
*/



#include <bits/stdc++.h>
using namespace std;




class Solution
{
public:
    vector <int> commonElements(int A[], int B[], int C[], int n1, int n2, int n3)
    {
        int i = 0, j = 0, k = 0;
        //setting up indices
        vector <int> res;
        int last = INT_MIN;// setting up variable to store last element stored in answer list
        while (i < n1 and j < n2 and k < n3)
        {
            if (A[i] == B[j] and A[i] == C[k])
            {
                //checking if element is common in all 3
                if (A[i] != last)
                {
                    // checking if element isn't already inserted
                    res.push_back(A[i]);
                    last = A[i];
                }
                i++;
                j++;
                k++;
            }
            //moving index of minimum value list
            else if (min({ A[i], B[j], C[k] }) == A[i]) i++;
            else if (min({ A[i], B[j], C[k] }) == B[j]) j++;
            else k++;
        }
        return res;
    }

};

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3;
        cin >> n1 >> n2 >> n3;
        int A[n1];
        int B[n2];
        int C[n3];

        for (int i = 0; i < n1; i++) cin >> A[i];
        for (int i = 0; i < n2; i++) cin >> B[i];
        for (int i = 0; i < n3; i++) cin >> C[i];

        Solution ob;

        vector <int> res = ob.commonElements(A, B, C, n1, n2, n3);
        if (res.size() == 0)
            cout << -1;
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
    }
}