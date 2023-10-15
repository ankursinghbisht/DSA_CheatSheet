/*
Idea:
finding the node which will new head, now detaching the old links,
 and attaching first part to the last of second part of doubly LL. and updating links and head.
*/

#include<bits/stdc++.h> 
using namespace std;

class Node
{
public:
    char data;
    Node* next;
    Node* pre;
    Node(int data)
    {
        this->data = data;
        pre = NULL;
        next = NULL;
    }
};

void insertAtHead(Node*& head, int data)
{
    Node* n = new Node(data);
    if (head == NULL)
    {
        head = n;
        return;
    }
    n->next = head;
    head->pre = n;
    head = n;
    return;
}
void insertAtTail(Node*& head, int data)
{
    if (head == NULL)
    {
        insertAtHead(head, data);
        return;
    }
    Node* temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    Node* n = new Node(data);
    temp->next = n;
    n->pre = temp;
    return;
}
void display(Node* head)
{
    while (head != NULL)
    {
        cout << head->data << "-->";
        head = head->next;
    }
    cout << "NULL\n";
}

void rotateByN(Node*& head, int pos)
{
    if (pos == 0)
        return;

    Node* ptr = head, * prev = NULL, * newHead = NULL;
    while (pos--) //finding breakpoint of the LL
        ptr = ptr->next;

    newHead = ptr;
    prev = ptr->pre;
    prev->next = NULL;

    while (ptr->next) // last node of original LL
        ptr = ptr->next;

    ptr->next = head; //updating links & head value.
    head->pre = ptr;
    head = newHead;


}

int main()
{
    Node* head = NULL;
    insertAtTail(head, 'a');
    insertAtTail(head, 'b');
    insertAtTail(head, 'c');
    insertAtTail(head, 'd');
    insertAtTail(head, 'e');

    int n = 2;
    cout << "\nBefore Rotation : \n";
    display(head);
    rotateByN(head, n);
    cout << "\nAfter Rotation : \n";
    display(head);
    cout << "\n\n";

    return 0;
}
