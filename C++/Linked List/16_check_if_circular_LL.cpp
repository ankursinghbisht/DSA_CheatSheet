/*
Idea:
Iterating LL, & if any pointer points to head again, LL is circular
*/

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }

};


bool isCircular(struct Node* head);

/* Driver program to test above function*/
int main()
{
    int T, i, n, l, k;

    cin >> T;

    while (T--) {

        cin >> n >> k;
        Node* head = NULL, * tail = NULL;
        int x;
        cin >> x;
        head = new Node(x);
        tail = head;
        for (int i = 0;i < n - 1;i++)
        {
            cin >> x;
            tail->next = new Node(x);
            tail = tail->next;
        }
        if (k == 1 && n >= 1)
            tail->next = head;


        printf("%d\n", isCircular(head));
    }
    return 0;
}


// } Driver Code Ends


/* Should return true if linked list is circular, else false */
bool isCircular(Node* head)
{
    Node* temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        if (temp == head)
            return true;
    }
    return false;
}
