/*
Idea:
Use  Floyd’s Cycle detection algorithm to detect if a loop is present in linked list
Once detected, finding length of the loop, and setting 2 pointers at head & other to k nodes after head
Incrementing both with same pace till both equal, ( we found the start of loop) & now finding last node & edit it
*/

//{ Driver Code Starts
// driver code

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

void loopHere(Node* head, Node* tail, int position)
{
    if (position == 0) return;

    Node* walk = head;
    for (int i = 1; i < position; i++)
        walk = walk->next;
    tail->next = walk;
}

bool isLoop(Node* head)
{
    if (!head) return false;

    Node* fast = head->next;
    Node* slow = head;

    while (fast != slow)
    {
        if (!fast || !fast->next) return false;
        fast = fast->next->next;
        slow = slow->next;
    }

    return true;
}

int length(Node* head)
{
    int ret = 0;
    while (head)
    {
        ret++;
        head = head->next;
    }
    return ret;
}

bool notOriginal(Node* head, unordered_map<Node*, int>& myMap) {

    while (head) {
        if (myMap.find(head) == myMap.end()) return true;
        if (myMap[head] != (head->data)) return true;

        head = head->next;
    }
}




class Solution
{
public:
    //Function to remove a loop in the linked list.
    void ifLoop(Node* node_in_loop, Node* head)
    {
        Node* ptr1 = node_in_loop->next, ptr2 = node_in_loop;
        int length = 1;

        //finding count of elements in loop 
        while (ptr1 != ptr2)
        {
            length++;
            ptr1 = ptr1->next;
        }

        ptr1 = head;
        for (int i = 0;i < length;++i)
            ptr2 = ptr2->next; // setting up 2 pointers (one at head & other to k nodes after head)

        while (ptr1 != ptr2)
        { //Move both pointers at the same pace, they will meet at loop starting node
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }

        while (ptr1 != ptr2->next)
        { // getting pointer to last node
            ptr2 = ptr2->next;
        }
        ptr2->next = NULL;
    }

    //function to check if there's loop in linked list
    void removeLoop(Node* head)
    {
        Node* front = head->next, * back = head;
        while (front != back)
        {
            if (front == NULL || front->next == NULL)
                return;
            front = front->next->next;
            back = back->next;
        }
        ifLoop(back, head);
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        unordered_map<Node*, int>myMap;

        int n, num;
        cin >> n;

        Node* head, * tail;
        cin >> num;
        head = tail = new Node(num);

        myMap[head] = num;

        for (int i = 0; i < n - 1; i++)
        {
            cin >> num;
            tail->next = new Node(num);
            tail = tail->next;
            myMap[tail] = num;
        }

        int pos;
        cin >> pos;
        loopHere(head, tail, pos);

        Solution ob;
        ob.removeLoop(head);

        if (isLoop(head) || length(head) != n || notOriginal(head, myMap))
            cout << "0\n";
        else
            cout << "1\n";
    }
    return 0;
}

// } Driver Code Ends
