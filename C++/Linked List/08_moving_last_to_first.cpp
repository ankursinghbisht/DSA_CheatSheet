/*
Idea:
Finding last & 2nd last element of LL
making next of 2nd last NULL & next of last to the head & updating the head
*/

/* CPP Program to move last element
to front in a given linked list */

#include <bits/stdc++.h> 
using namespace std;

/* A linked list node */
class Node {
public:
    int data;
    Node* next;
};

/* We are using a double pointer
head_ref here because we change
head of the linked list inside
this function.*/
void moveToFront(Node** head_ref)
{
    if (*head_ref == NULL || (*head_ref)->next == NULL)
        return;
    Node* temp = *head_ref, * swapElement;
    while (temp->next->next != NULL) // finding last & 2nd last element of LL
    {
        temp = temp->next;
    }
    swapElement = temp->next; // updating next pointers of acquired pointers
    temp->next = NULL;

    swapElement->next = *head_ref;
    *head_ref = swapElement;// updated head pointer
}

/* UTILITY FUNCTIONS */
/* Function to add a node
at the beginning of Linked List */
void push(Node** head_ref, int new_data)
{
    /* allocate node */
    Node* new_node = new Node();

    /* put in the data */
    new_node->data = new_data;

    /* link the old list of the new node */
    new_node->next = (*head_ref);

    /* move the head to point to the new node */
    (*head_ref) = new_node;
}

/* Function to print nodes in a given linked list */
void printList(Node* node)
{
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
}

// Driver's code 
int main()
{
    Node* start = NULL;

    /* The constructed linked list is:
    1->2->3->4->5 */
    push(&start, 5);
    push(&start, 4);
    push(&start, 3);
    push(&start, 2);
    push(&start, 1);

    cout << "Linked list before moving last to front\n";
    printList(start);

    // Function call 
    moveToFront(&start);

    cout << "\nLinked list after removing last to front\n";
    printList(start);

    return 0;
}