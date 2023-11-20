/*
Idea:
indexing each train , and sorting based on its departure time, if same, sort on indices given.
using vector to keep track of each platform, checking if current train can stay at designated station.
*/


//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Matrix
{
public:
    template <class T>
    static void input(vector<vector<T>>& A, int n, int m)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                scanf("%d ", &A[i][j]);
            }
        }
    }

    template <class T>
    static void print(vector<vector<T>>& A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            for (int j = 0; j < A[i].size(); j++)
            {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};


// } Driver Code Ends
class Solution {

    // Comparator function to sort trains based on departure times and indices given to it
    static bool comp(std::vector<int> a, std::vector<int> b)
    {
        if (a[1] == b[1])
            return a[3] <= b[3];
        return a[1] < b[1];
    }

    int maxStop(int n, int m, std::vector<std::vector<int>>& trains)
    {
        // Add the index of each train to the vector
        for (int i = 0; i < m; ++i)
            trains[i].push_back(i);

        // Sort trains based on  departure times and indices given to it
        std::sort(trains.begin(), trains.end(), comp);

        // Initialize an array to store the latest departure time for each station
        std::vector<int> times(n + 1, -1);

        // Initialize the count of stopped trains
        int ans = 0;

        // Iterate through sorted trains and stop them if possible
        for (auto iter : trains)
            if (iter[0] >= times[iter[2]])
            {
                times[iter[2]] = iter[1];
                ++ans;
            }


        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);


        int m;
        scanf("%d", &m);


        vector<vector<int>> trains(m, vector<int>(3));
        Matrix::input(trains, m, 3);

        Solution obj;
        int res = obj.maxStop(n, m, trains);

        cout << res << endl;

    }
}

// } Driver Code Ends