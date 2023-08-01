/*
Idea:
iterating through each index, storing the last possible index to jump to .
& counting jumps every time we run out of steps.
-No need to store which index we need to jump from, as we just need count.
*/

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int minJumps(int arr[], int n)
    {
        //checking if array has only 0/1 element, to return 0 as we are already in  end position
        if (n <= 1)
            return 0;

        //checking if element is 0, as we can't reach end element
        if (arr[0] == 0)
            return -1;

        int maxReach = arr[0]; //maxreach= highest index element achieveable from current index 
        int  steps = arr[0]; // steps= stores number of steps that can be taken from current index
        int  jumps = 1; // no. of jumps taken so far


        for (int i = 1;i < n;++i)
        {
            // if we reached end of array, return no. of jumps 
            if (i == n - 1)
                return jumps;

            // setting var to max index element we can reach from current index
            maxReach = max(maxReach, i + arr[i]);

            steps--; // reducing steps count after each iterated element

            if (steps == 0)
            {
                // if no more steps can be taken, we need to take a jump
                jumps++;


                steps = maxReach - i; //setting up steps as maximum distance allowed to travel

                if (i >= maxReach) // if we crossed max possible index, returning 
                    return -1;
            }
        }
        // if we weren't able to reach last index, returning -1
        return -1;


    }
};


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, i, j;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution obj;
        cout << obj.minJumps(arr, n) << endl;
    }
    return 0;
}