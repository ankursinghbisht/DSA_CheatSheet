/*
Idea:
reversing the LL, performing addition element wise & reversing again & returning
*/

//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin >> val;

    Node* head = new Node(val);
    Node* tail = head;

    for (int i = 0; i < size - 1; i++)
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
    cout << endl;
}


// } Driver Code Ends


class Solution
{
public:
    Node* reverse(Node* head)
    {
        Node* prev = NULL;
        Node* current = head;
        Node* next;

        while (current != NULL)
        {
            next = current->next;     // storing next node
            current->next = prev;     // linking current node to previous
            prev = current;           // updating prev
            current = next;           // updating current
        }

        return prev;
    }
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        if (!first)
            return second;
        if (!second)
            return first;

        // Reverse both input lists
        Node* reversedFirst = reverse(first);
        Node* reversedSecond = reverse(second);

        Node* result = new Node(0);
        Node* current = result;

        int carry = 0;
        int sum;

        while (reversedFirst != nullptr || reversedSecond != nullptr || carry)
            //Iterate through the reversed input lists and handle carry
        {
            int value1 = reversedFirst ? reversedFirst->data : 0;
            int value2 = reversedSecond ? reversedSecond->data : 0;

            sum = value1 + value2 + carry;
            carry = sum / 10;

            Node* newNode = new Node(sum % 10);
            current->next = newNode;
            current = newNode;

            if (reversedFirst)
                reversedFirst = reversedFirst->next;
            if (reversedSecond)
                reversedSecond = reversedSecond->next;
        }

        // Reverse the result and return it
        return reverse(result->next);
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;

        cin >> n;
        Node* first = buildList(n);

        cin >> m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first, second);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends