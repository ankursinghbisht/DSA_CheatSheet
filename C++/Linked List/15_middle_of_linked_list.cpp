/*
Idea:
Using 2 pointer technique:
front to be moved twice at one iteration & behind to be moved once.
once front reaches end, return value of behind, if null return -1
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

class Solution {
public:
    /* Should return data of middle node. If linked list is empty, then  -1*/
    int getMiddle(Node* head)
    {
        Node* temp = head;
        Node* mid = head;

        if (head == NULL)
            return -1;

        while (mid != NULL && mid->next != NULL)
        {
            mid = mid->next->next;
            // this pointer moves 2 nodes ahead everytime loop is run

            temp = temp->next;
            // this pointer moves 1 node ahead everytime loop is run
        }

        // since temp was moving with half speed, it is there at halfway point
        return temp->data;
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
        cout << ob.getMiddle(head) << endl;
    }
    return 0;
}

// } Driver Code Ends