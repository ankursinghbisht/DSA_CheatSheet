/*
Idea:
Using dummy variable to keep track of the head after being sorted.
& reversing the linked list for each group.
*/

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


struct node
{
    int data;
    struct node* next;

    node(int x) {
        data = x;
        next = NULL;
    }

};

/* Function to print linked list */
void printList(struct node* node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}


class Solution
{
public:
    struct node* reverse(struct node* head, int k)
    {
        if (!head || k == 1)
            return head;
        node* dummy = new node();
        dummy->data = -1;
        dummy->next = head;

        int length = 0;
        node* prev = dummy, * next = dummy, * now = dummy;
        while (now != NULL)
        {
            now = now->next; // finding length of the linked list
            length++;
        }

        while (next)
        {
            now = prev->next;
            next = now->next; // setting up vars for each group

            int tempLen = length > k ? k : length - 1; // finding the group length is of target length of 
            for (int i = 1;i < tempLen;++i)
            {
                now->next = next->next;
                next->next = prev->next;
                prev->next = next;
                next = now->next;
                // reversing the group 
            }
            prev = now;
            length -= k;
        }
        return dummy->next; // returning the head
    }
};


//{ Driver Code Starts.

/* Drier program to test above function*/
int main(void)
{
    int t;
    cin >> t;

    while (t--)
    {
        struct node* head = NULL;
        struct node* temp = NULL;
        int n;
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            int value;
            cin >> value;
            if (i == 0)
            {
                head = new node(value);
                temp = head;
            }
            else
            {
                temp->next = new node(value);
                temp = temp->next;
            }
        }

        int k;
        cin >> k;

        Solution ob;
        head = ob.reverse(head, k);
        printList(head);
    }

    return(0);
}


// } Driver Code Ends