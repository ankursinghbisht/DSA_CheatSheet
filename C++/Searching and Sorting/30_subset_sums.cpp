/*
Idea:
dividing the array in 2 parts, generating all subsets and their sum of both halves & appending it to the arrays
sorting the second half, and using binary search to find the corresponding element that sums within the range.
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    long long A, B;
    cin >> N >> A >> B;

    vector<long long> S(N);
    for (int i = 0; i < N; i++) {
        cin >> S[i];
    }

    int halfN = N / 2;
    int otherHalfN = N - halfN;

    // Generate all possible subsets for the first half of the array
    vector<long long> subsetSum1(1 << halfN);

    for (int mask = 0; mask < (1 << halfN); mask++)
    {
        for (int i = 0; i < halfN; i++) {
            if (mask & (1 << i)) {
                subsetSum1[mask] += S[i];
            }
        }
    }

    // Generate all possible subsets for the second half of the array
    vector<long long> subsetSum2(1 << otherHalfN);

    for (int mask = 0; mask < (1 << otherHalfN); mask++)
    {
        for (int i = 0; i < otherHalfN; i++) {
            if (mask & (1 << i)) {
                subsetSum2[mask] += S[halfN + i];
            }
        }
    }

    // Sort the second half of the subsets for binary search
    sort(subsetSum2.begin(), subsetSum2.end());

    long long count = 0;

    // Count the subsets with sums between A and B
    for (int i = 0; i < (1 << halfN); i++)
    {
        long long target1 = A - subsetSum1[i];
        long long target2 = B - subsetSum1[i];

        // Use binary search to find the range of possible sums in the second half
        auto low = lower_bound(subsetSum2.begin(), subsetSum2.end(), target1);
        auto high = upper_bound(subsetSum2.begin(), subsetSum2.end(), target2);

        count += (high - low);
    }

    cout << count << endl;

    return 0;
}
