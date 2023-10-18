/*
Idea:
using 2 pointers ,one from start and other from 'n' distance from start,
moving both at same speed, once front pointer reached end, back pointer will be at "nth node from end"
*/

//{ Driver Code Starts
//Initial Template for C++
// C program to find n'th Node in linked list
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
#include <bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


/* Function to get the nth node from the last of a linked list*/
int getNthFromLast(struct Node* head, int n);



/* Driver program to test above function*/



//Function to find the data of nth node from the end of a linked list.
class Solution {
public:
    int getNthFromLast(Node* head, int n)
    {
        // Your code here
        Node* p1 = head, * p2 = head;

        for (int i = 0;i < n - 1;i++) // setting up front pointer to n-th distance from front
            if (p2->next)
                p2 = p2->next;
            else
                return -1;

        while (p2->next)
        {
            p2 = p2->next;
            p1 = p1->next;
        }

        return p1->data;
    }
};



//{ Driver Code Starts.

int main()
{
    int T, i, n, l, k;

    cin >> T;

    while (T--) {
        struct Node* head = NULL, * tail = NULL;

        cin >> n >> k;
        int firstdata;
        cin >> firstdata;
        head = new Node(firstdata);
        tail = head;
        for (i = 1;i < n;i++)
        {
            cin >> l;
            tail->next = new Node(l);
            tail = tail->next;
        }
        Solution obj;
        cout << obj.getNthFromLast(head, k) << endl;
    }
    return 0;
}
// } Driver Code Ends