/*
Idea:
using 2 arrays holding sum of elements till the pointers
-at intersection (no. at indices being equal) , changing sum of both arrays to the max
-if any array ends, adding rest of elements till both ends.
returning max value
*/

#include<bits/stdc++.h>
using namespace std;



class Solution
{
public:
    int max_path_sum(int A[], int B[], int l1, int l2)
    {
        int sum1 = 0, sum2 = 0, i = 0, j = 0;
        while (i < l1 && j < l2)
        {
            if (A[i] == B[j])
            {
                sum1 = sum2 = max(sum1, sum2) + A[i];
                ++i;
                ++j;
            }
            else if (A[i] < B[j])
                sum1 += A[i++];
            else
                sum2 += B[j++];
        }

        while (i < l1)
            sum1 += A[i++];
        while (j < l2)
            sum2 += B[j++];
        return max(sum1, sum2);


    }
};


int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int N, M;
        cin >> N >> M;
        fflush(stdin);
        int a[N], b[M];
        for (int i = 0;i < N;i++)
            cin >> a[i];
        for (int i = 0;i < M;i++)
            cin >> b[i];
        Solution obj;
        int result = obj.max_path_sum(a, b, N, M);
        cout << result << endl;
    }
}