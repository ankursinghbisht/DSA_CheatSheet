/*
Idea:
There are n+1 positive elements & only 1 element is repeated.
Starting from index 0, going to element at value of that index and marking that element negative.
We'll get one positive element ( as one element is repeating)
*/

#include<bits/stdc++.h>
using namespace std;


int  find_Duplicate_Element(int* arr, int n)
{
    //iterating each element
    for (int i = 0;i < n;++i)
    {

        int curr = abs(arr[i]) - 1; // finding which index element we have to modify
        if (arr[curr] < 0) // checking if any element is already negative, i.e. we've found repeating element
            return curr + 1;
        arr[curr] *= -1; // setting up elements as negative
    }
    return -1;
}


int main()
{
    int arr[] = { 3,1,3,4,2 }, n = 5;
    int ans = find_Duplicate_Element(arr, n);
    cout << ans << "\n";
    return 0;
}