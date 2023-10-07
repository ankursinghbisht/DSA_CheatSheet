/*
Idea:
using hashing to keep track of elements already encountered ( by using unordered_set)
*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

void print(Node* root)
{
    Node* temp = root;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}


// } Driver Code Ends



class Solution
{
public:
    //Function to remove duplicates from unsorted linked list.
    Node* removeDuplicates(Node* head)
    {
        unordered_set <int> hash_table; //keeping track of encountered elements
        Node* temp = head, * next_next;
        hash_table.insert(head->data);
        while (temp->next != NULL)
        {
            if (hash_table.find(temp->next->data) != hash_table.end())
            { // if element is already encountered-removing the element from list
                next_next = temp->next->next;
                free(temp->next);
                temp->next = next_next;
            }
            else
            {
                //keep pushing the element into hashtable
                hash_table.insert(temp->next->data);
                temp = temp->next;
            }
        }
        return head;
    }
};


//{ Driver Code Starts.

int main() {
    // your code goes here
    int T;
    cin >> T;

    while (T--)
    {
        int K;
        cin >> K;
        struct Node* head = NULL;
        struct Node* temp = head;

        for (int i = 0;i < K;i++) {
            int data;
            cin >> data;
            if (head == NULL)
                head = temp = new Node(data);
            else
            {
                temp->next = new Node(data);
                temp = temp->next;
            }
        }

        Solution ob;
        Node* result = ob.removeDuplicates(head);
        print(result);
        cout << endl;

    }
    return 0;
}
// } Driver Code Ends