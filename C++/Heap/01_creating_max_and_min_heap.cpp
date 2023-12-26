/*

*/

#include<bits/stdc++.h>
using namespace std;

// C++ program for building Heap from Array

#include <bits/stdc++.h>

using namespace std;


// Function to build a Max-Heap from the given array
void insertHeap(vector<int>& arr, int elem)
{
    int i = 1;
    while (arr[i] != -1)
        ++i;
    arr[i] = elem;

    while (arr[i / 2] < arr[i] && i>0)
    {
        swap(arr[i / 2], arr[i]);
        i /= 2;
    }
    cout << "entered:" << elem << "\n";
}

// A utility function to print the array
// representation of Heap
void printHeap(vector<int> arr, int N)
{
    cout << "Array representation of Heap is:\n";

    for (int i = 1; i < N; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

// Driver Code
int main()
{
    int arr[] = { 1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17 };

    int N = sizeof(arr) / sizeof(arr[0]);

    vector<int> heap(N + 1, -1);
    for (int i = 0;i < N;++i)
        insertHeap(heap, arr[i]);

    printHeap(heap, N + 1);

    // Final Heap:
    //			 17
    //		 / \
	//		 15	 13
    //		 / \	 / \
	//	 9	 6 5 10
    //	 / \ / \
	//	 4 8 3 1

    return 0;
}
