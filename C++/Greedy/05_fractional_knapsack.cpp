/*
Idea:
sorting the array in decreasing order of ratio of value and weight,
adding the value till weight left is 0, and keeping portion of an element if needed.
*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item {
    int value;
    int weight;
};


// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    //comparison function to sort items according to value/weight ratio.
    static bool cmp(Item a, Item b)
    {
        double r1 = (double)a.value / a.weight;
        double r2 = (double)b.value / b.weight;
        return r1 > r2;
    }

public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {

        //sorting items on basis of value/weight ratio.
        sort(arr, arr + n, cmp);

        //taking variable for current weight in knapsack.
        int curWeight = 0;
        double finalvalue = 0.0;

        //iterating over all the items.
        for (int i = 0; i < n; i++)
        {
            //if currweight + item's weight is less than or equal to W, then we add the item's value to final value.
            if (curWeight + arr[i].weight <= W)
            {
                curWeight += arr[i].weight;
                finalvalue += arr[i].value;
            }
            //else we take the fraction of the that item's value based on the remaining weight in knapsack.
            else
            {
                int remain = W - curWeight;
                finalvalue += arr[i].value * ((double)remain / arr[i].weight);
                break;
            }
        }
        //returning final value.
        return finalvalue;
    }

};


//{ Driver Code Starts.
int main()
{
    int t;
    //taking testcases
    cin >> t;
    cout << setprecision(2) << fixed;
    while (t--) {
        //size of array and weight
        int n, W;
        cin >> n >> W;

        Item arr[n];
        //value and weight of each item
        for (int i = 0;i < n;i++) {
            cin >> arr[i].value >> arr[i].weight;
        }

        //function call
        Solution ob;
        cout << ob.fractionalKnapsack(W, arr, n) << endl;
    }
    return 0;
}
// } Driver Code Ends