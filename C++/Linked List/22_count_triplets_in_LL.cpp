/*
Idea:
using set to store all encountered elements till now, now using 2 loops,
 with each addressing one of 3 required values-searching if 3rd exist in set, if yes add 1 to answer
*/

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node
{
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }

};

void push(struct Node** head_ref, int new_data)
{

    struct Node* new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int countTriplets(struct Node* head, int x);

/* Driver program to test count function*/
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x, i, num;
        struct Node* head = NULL;
        cin >> n >> x;
        for (i = 0;i < n;i++)
        {
            cin >> num;
            push(&head, num);
        }

        /* Check the count function */
        cout << countTriplets(head, x) << endl;
    }
    return 0;
}
// } Driver Code Ends


//User function Template for C++

int countTriplets(struct Node* head, int x)
{
    Node* first = head;
    int count = 0;
    unordered_set<int> visited;
    while (first != NULL)
    {
        Node* second = first->next;
        while (second != NULL)
        {
            int com = x - (first->data + second->data);
            if (visited.find(com) != visited.end()) // if 3rd value exist in the set
                count++;
            second = second->next;
        }
        visited.insert(first->data);
        first = first->next;
    }

    return cnt;
}