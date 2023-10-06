/*
Idea:
Use  Floyd’s Cycle detection algorithm to detect if a loop is present in linked list
Once detected, finding length of the loop, and setting 2 pointers at head & other to k nodes after head
Incrementing both with same pace till both equal, ( we found the start of loop)
*/

//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void loopHere(Node* head, Node* tail, int position)
{
    if (position == 0) return;

    Node* walk = head;
    for (int i = 1; i < position; i++)
        walk = walk->next;
    tail->next = walk;
}


// } Driver Code Ends

class Solution {
public:
    // Function to find the first node if the linked list has a loop.
    int findFirstNode(Node* head) {
        Node* front = head->next;
        Node* back = head;
        while (front != back) {
            if (front == nullptr || front->next == nullptr) {
                return -1; // Finding if there's a loop in the linked list
            }
            front = front->next->next;
            back = back->next;
        }

        Node* ptr1 = back->next;
        Node* ptr2 = back;
        int length = 1;

        // Finding the count of elements in the loop
        while (ptr1 != ptr2) {
            length++;
            ptr1 = ptr1->next;
        }

        ptr1 = ptr2 = head;
        for (int i = 0; i < length; ++i) {
            ptr2 = ptr2->next; // Setting up 2 pointers (one at head & other to k nodes after head)
        }

        while (ptr1 != ptr2) {
            // Move both pointers at the same pace; they will meet at the loop starting node
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }

        return ptr1->data;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, num;
        cin >> n;

        Node* head, * tail;
        cin >> num;
        head = tail = new Node(num);

        for (int i = 0; i < n - 1; i++)
        {
            cin >> num;
            tail->next = new Node(num);
            tail = tail->next;
        }

        int pos;
        cin >> pos;
        loopHere(head, tail, pos);

        Solution ob;
        int ans = ob.findFirstNode(head);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends