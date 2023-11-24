/*
Idea:
sorting in descending order,  finding the sum of total array.
Then, from start, sum till difference between temporary sum and original sum is greater than temporary sum.
*/

//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    //Function to find the minimum number of elements in the first subset.
    int minSubset(vector<int>& Arr, int N) {
        long long sum = 0;

        //calculating the sum of all elements in the Arr vector.
        for (int i = 0;i < N;i++) {
            sum += Arr[i];
        }

        //sorting the Arr vector in descending order.
        sort(Arr.rbegin(), Arr.rend());
        long long res = 0;

        //iterating through the Arr vector to find the minimum number of elements in the first subset.
        for (int i = 0;i < N;i++) {
            res += Arr[i];
            sum -= Arr[i];

            //if the sum of elements in the first subset becomes greater than the sum of remaining elements,
            //return the index i+1 which represents the minimum number of elements in the first subset.
            if (res > sum) {
                return i + 1;
            }
        }
        //if no such index is found, return N which represents that all elements are in the first subset.
        return N;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> Arr(N);
        for (int i = 0;i < N;i++) {
            cin >> Arr[i];
        }
        Solution ob;
        cout << ob.minSubset(Arr, N) << endl;
    }
    return 0;
}
// } Driver Code Ends