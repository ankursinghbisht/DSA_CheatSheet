/*
Idea:
iterating through the array of LLs, merging 2 LLs at a time & updating the head nodes associated in array. returning the last head as answer.
*/

//{ Driver Code Starts
// C++ program to merge k sorted arrays of size n each
#include <bits/stdc++.h>
using namespace std;

// A Linked List node
struct Node
{
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }

};

/* Function to print nodes in a given linked list */
void printList(Node* node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    cout << endl;
}

// } Driver Code Ends

*/

class Solution {
public:
    //Function to merge K sorted linked list.
    Node* mergeKLists(Node* arr[], int K)
    {
        if (K == 1)
            return arr[0];

        for (int i = 1; i < K; i++)
        {
            //iterating 2 LL at a time, and merging 
            Node* ord = new Node(-1);
            Node* tail = ord;

            Node* left = arr[i - 1];
            Node* right = arr[i];

            while (left && right) // copying till one of the LL is empty
            {
                if (left->data < right->data) // if left element is smaller
                {
                    tail->next = left;
                    tail = left;
                    left = left->next;
                }
                else // if right element is smaller
                {
                    tail->next = right;
                    tail = right;
                    right = right->next;
                }
            }
            while (left) // empyting left LL
            {
                tail->next = left;
                tail = left;
                left = left->next;
            }
            while (right) // emptying right LL
            {
                tail->next = right;
                tail = right;
                right = right->next;
            }
            arr[i] = ord->next; // updating the merged pointers for merging with next LL
        }
        return arr[K - 1];
    }
};



//{ Driver Code Starts.
// Driver program to test above functions
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        struct Node* arr[N];
        for (int j = 0;j < N;j++)
        {
            int n;
            cin >> n;

            int x;
            cin >> x;
            arr[j] = new Node(x);
            Node* curr = arr[j];
            n--;

            for (int i = 0;i < n;i++)
            {
                cin >> x;
                Node* temp = new Node(x);
                curr->next = temp;
                curr = temp;
            }
        }
        Solution obj;
        Node* res = obj.mergeKLists(arr, N);
        printList(res);

    }

    return 0;
}

// } Driver Code Ends