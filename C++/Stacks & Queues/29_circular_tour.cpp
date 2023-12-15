/*
Idea:
keeping track of sum of difference between petrol & distance. if sum<0 , reset to 0 and set answer to that index
& check if total sum>0
*/

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};


// } Driver Code Ends
/*
The structure of petrolPump is
struct petrolPump
{
    int petrol;
    int distance;
};*/

/*You are required to complete this method*/
class Solution {
public:

    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[], int n)
    {
        // Initialize variables to keep track of temporary and total petrol surplus,
        // the difference between petrol and distance, and the answer (starting point).
        int temp = 0, sum = 0, ans = 0;

        // Iterate through the petrol pumps.
        for (int i = 0; i < n; ++i)
        {
            // Calculate the surplus petrol at the current petrol pump.
            int diff = (p[i].petrol - p[i].distance);

            // Update temporary and total surplus petrol.
            temp += diff;
            sum += diff;

            // If the total surplus becomes negative, reset it to zero
            // and update the potential starting point.
            if (sum < 0)
            {
                sum = 0;
                ans = i + 1;
            }
        }

        // If the total surplus is negative overall, there is no valid starting point.
        if (temp < 0)
            return -1;

        // Return the index of the valid starting point.
        return ans;
    }
};



//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        petrolPump p[n];
        for (int i = 0;i < n;i++)
            cin >> p[i].petrol >> p[i].distance;
        Solution obj;
        cout << obj.tour(p, n) << endl;
    }
}

// } Driver Code Ends