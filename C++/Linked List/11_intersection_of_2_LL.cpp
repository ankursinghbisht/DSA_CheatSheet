/*
Idea:
Iterating the both LL in parallel, moving pointer of the LL with smaller value, & appending common values in 3rd LL
*/

//{ Driver Code Starts
//

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

Node* inputList(int size)
{
    Node* head, * tail;
    int val;

    cin >> val;
    head = tail = new Node(val);

    while (--size)
    {
        cin >> val;
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}

void printList(Node* n)
{
    while (n)
    {
        cout << n->data << " ";
        n = n->next;
    }
}

Node* findIntersection(Node* head1, Node* head2);

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;

        Node* head1 = inputList(n);
        Node* head2 = inputList(m);

        Node* result = findIntersection(head1, head2);

        printList(result);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends



Node* findIntersection(Node* head1, Node* head2)
{
    Node* ans = new Node(-1), * ptr = ans;
    Node* t1 = head1, * t2 = head2;
    while (t1 != NULL && t2 != NULL)
    {
        if (t1->data == t2->data)
        { //if nodes match:
            Node* tp = new Node(t1->data);
            ptr->next = tp;
            ptr = ptr->next;
            t1 = t1->next;
            t2 = t2->next;
        }
        else if (t1->data < t2->data) // nodes don't match moving to next node in list with smaller node
            t1 = t1->next;
        else // nodes don't match moving to next node in list with smaller node 
            t2 = t2->next;
    }
    return ans->next;
}