/*
Idea:
counting all 0,1,2 , and updating values of LL.
*/

//{ Driver Code Starts
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

struct Node* start = NULL;


// } Driver Code Ends

class Solution
{
public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node* head)
    {
        int count0 = 0, count1 = 0, count2 = 0;
        Node* ptr = head;

        //counting all 0's, 1's & 2's.
        while (ptr)
        {
            if (ptr->data == 0)
                ++count0;
            else if (ptr->data == 1)
                ++count1;
            else
                ++count2;
            ptr = ptr->next;
        }

        ptr = head;

        //updating the values of nodes
        while (count0--)
        {
            ptr->data = 0;
            ptr = ptr->next;
        }
        while (count1--)
        {
            ptr->data = 1;
            ptr = ptr->next;
        }
        while (count2--)
        {
            ptr->data = 2;
            ptr = ptr->next;
        }
        return head;
    }
};


//{ Driver Code Starts.

// Function to sort a linked list of 0s, 1s and 2s
void printList(struct Node* Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
void insert(int n1) {
    int n, value, i;
    // scanf("%d",&n);
    n = n1;
    struct Node* temp;
    for (i = 0; i < n; i++) {
        scanf("%d", &value);

        if (i == 0) {
            start = new Node(value);
            temp = start;
            continue;
        }
        else {
            temp->next = new Node(value);
            temp = temp->next;
            temp->next = NULL;
        }
    }
}

int main() {

    int n;

    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        insert(n);
        Solution ob;
        struct Node* newHead = ob.segregate(start);
        printList(newHead);
    }

    return 0;
}
// } Driver Code Ends