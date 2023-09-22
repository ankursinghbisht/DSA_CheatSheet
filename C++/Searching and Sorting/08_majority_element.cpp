/*
Idea: (using Boyer-Moore voting algorithm)
This algorithm works on the fact that if an element occurs more than N/2 times,
it means that the remaining elements other than this would definitely be less than N/2.

-Steps:
iterating each element, and a var 'count' . if count==0, keeping tally of the var at current index
if element is not same as element , reduce the count by 1.
and at last we check if element found has frequency more than half of size of array.
*/


#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
    int majorityElement(int a[], int size)
    {
        int count = 0, el;
        for (int i = 0;i < size;++i) //keeping count of element 'el'
        {
            if (count == 0)
            {
                count++;
                el = a[i]; //setting up the element to be traced
            }
            else if (a[i] == el) // if element is same as 'el' , increase the count
                count++;
            else
                count--; //  else decreased the count var
        }

        count = 0;
        for (int i = 0;i < size;++i)
            if (a[i] == el)
                count++;

        if (count > size / 2) //  checking if element 'el' has frequency more than size/2
            return el;
        return -1;
    }
};


int main() {

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        int arr[n];

        for (int i = 0;i < n;i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.majorityElement(arr, n) << endl;
    }

    return 0;
}