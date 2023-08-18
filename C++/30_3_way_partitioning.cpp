/*
Idea:
We traverse the given array of elements from left.
We keep track of two pointers, first to store next position of smaller element(smaller than range) from beginning,
and second to store next position of greater element from end.
while traversing the array use these two pointers to place elements according to their range.
*/
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


class Solution {
public:
    void threeWayPartition(vector<int>& array, int a, int b)
    {
        int n = array.size();
        //Using two pointers which help in finding the index with which
        //the elements need to be swapped if they are not in correct position. 
        int start = 0, end = n - 1;

        for (int i = 0; i <= end;)
        {
            //If current element is smaller than lower range, we swap 
            //it with value on next available smallest position. 
            if (array[i] < a)
                swap(array[i++], array[start++]);

            //If current element is greater than higher range, we swap 
            //it with value on next available greatest position. 
            else if (array[i] > b)
                swap(array[i], array[end--]);

            //Else we just move ahead in the array.
            else
                i++;
        }
    }
};


int main() {
    vector<int> arr = { 3,1,5,9,12,4,6,8,7 };

    Solution obj;
    obj.threeWayPartition(arr, 5, 8);
    for (auto i : arr)
        cout << i << " ";
    return 0;
}
