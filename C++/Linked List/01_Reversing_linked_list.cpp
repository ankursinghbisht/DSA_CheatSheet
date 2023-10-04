/*
Idea:
Iterating each element, and using temporary pointers, reversing the pointer direction
& returning the last element ( as head)
*/


//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

/* Link list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};


class Solution
{
public:
    //Function to reverse a linked list.
    struct Node* reverseList(struct Node* head)
    {
        // code here
        // return head of reversed list
        Node* now = head, * prev = NULL, * next;
        while (now != NULL)
        {
            next = now->next;
            now->next = prev;

            prev = now;
            now = next;
        }
        return prev;
    }

};



//{ Driver Code Starts.

void printList(struct Node* head)
{
    struct Node* temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

/* Driver program to test above function*/
int main()
{
    int T, n, l, firstdata;
    cin >> T;

    while (T--)
    {
        struct Node* head = NULL, * tail = NULL;

        cin >> n;

        if (n != 0)
        {
            cin >> firstdata;
            head = new Node(firstdata);
            tail = head;
        }

        for (int i = 1; i < n; i++)
        {
            cin >> l;
            tail->next = new Node(l);
            tail = tail->next;
        }

        Solution ob;
        head = ob.reverseList(head);

        printList(head);
        cout << endl;
    }
    return 0;
}


// } Driver Code Ends