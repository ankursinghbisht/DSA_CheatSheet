/*
Idea:
keeping 2 pointers , each for odd and even numbers, and appending odd after even ones and returning
*/

//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
void printList(Node* node)
{
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}


// } Driver Code Ends
//User function template for C++

class Solution {
public:
    Node* divide(int N, Node* head)
    {
        // code here
        Node* odd = new Node(-1), * even = new Node(-1), * ptrODD = odd, * ptrEVEN = even, * temp = head;
        while (temp)
        {
            if (temp->data & 1)//if node is odd
            {
                ptrODD->next = temp;
                ptrODD = ptrODD->next;
            }
            else //if node is even
            {
                ptrEVEN->next = temp;
                ptrEVEN = ptrEVEN->next;
            }
            temp = temp->next;
        }
        //set the last node of the odd list to NULL
        ptrODD->next = NULL;

        // Combine the even and odd lists and return the head of the even list
        ptrEVEN->next = odd->next;
        return even->next;

    }
};

//{ Driver Code Starts.

int main() {
    //code
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        int data;
        cin >> data;
        struct Node* head = new Node(data);
        struct Node* tail = head;
        for (int i = 0; i < N - 1; ++i)
        {
            cin >> data;
            tail->next = new Node(data);
            tail = tail->next;
        }

        Solution ob;
        Node* ans = ob.divide(N, head);
        printList(ans);
    }
    return 0;
}

// } Driver Code Ends