/*
Idea:
-Deletion:
deleting the node, while keeping the connections same & special case for head node .
-Reversing:
Reversing each node, and updating each connection.
*/

//{ Driver Code Starts
// C program to delete a given key from
// linked list.
#include<bits/stdc++.h>
using namespace std;

/* structure for a node */
struct Node
{
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

Node* pre = NULL;

/* Function to delete a given node from the list */
//void deleteNode(struct Node *head, int key);
void deleteNode(Node** head, int data);
void reverse(Node** head);

/* Function to reverse the linked list */
//static void reverse(struct Node** head_ref);

/* Function to insert a node at the beginning of
a Circular linked list */

void push(struct Node** head_ref, int data)
{
    // Create a new node and make head as next
    // of it.

    struct Node* curr = new Node(data);

    curr->next = curr;

    if (*head_ref == NULL)
    {
        *head_ref = curr;
        curr->next = *head_ref;
        pre = *head_ref;

    }
    else
    {
        curr->next = *head_ref;
        pre->next = curr;
        pre = pre->next;


    }
}

/* Function to print nodes in a given
circular linked list */
void printList(struct Node* head)
{
    struct Node* temp = head;
    if (head != NULL)
    {
        do
        {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != head);
    }
    else
        cout << "empty" << endl;

    printf("\n");
}
/* Driver program to test above functions */
int main()
{

    /* Initialize lists as empty */
    int t, a, delnode;
    cin >> t;
    while (t--)
    {
        pre = NULL;
        Node* head = NULL;

        int n;
        cin >> n;
        while (n--)
        {
            cin >> a;
            push(&head, a);
        }
        /* Created linked list will be 2->5->7->8->10 */
        cin >> delnode;

        deleteNode(&head, delnode);

        reverse(&head);

        printList(head);
    }
    return 0;
}

// } Driver Code Ends



// Function to reverse a circular linked list
void reverse(Node** head)
{
    // If the list has only one node, return
    if ((*head)->next == *head)
        return;

    // Creating temporary nodes for swapping
    struct Node* p = new Node(-1);
    struct Node* q = new Node(-1);
    struct Node* init = new Node(-1);

    // Initializing the nodes
    p = NULL;
    q = NULL;
    init = *head;

    // Reversing the linked list
    while (q != init)
    {
        q = (*head)->next;
        ((*head)->next) = p;
        p = *head;
        *head = q;
    }

    // Updating the head and connecting the last node to the first node
    *head = p;
    q->next = p;
}

// Function to delete a node from the circular linked list
void deleteNode(Node** head, int data)
{
    // If the list has only one node, return
    if ((*head)->next == *head)
        return;

    // Creating a temporary node
    struct Node* temp = new Node(-1);

    // Deleting the head node
    if (data == (*head)->data)
    {
        temp = *head;
        while (temp->next != *head)
        {
            temp = temp->next;
        }
        *head = (*head)->next;
        temp->next = *head;
    }
    // Deleting a node other than the head node
    else
    {
        temp = *head;
        while (temp->next->data != data)
        {
            temp = temp->next;
        }
        temp->next = temp->next->next;
    }
}