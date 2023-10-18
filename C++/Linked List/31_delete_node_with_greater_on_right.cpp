/*
Idea:
reversing the LL & removing elements that are smaller than the max value till that element. & reversing the LL again and returning
*/



//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* next;

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
    Node* reverseList(struct Node* head)
    {
        // return head of reversed list
        Node* now = head, * prev = NULL, * next;
        while (now != NULL)
        {
            next = now->next;
            now->next = prev;

            prev = now;
            now = next;
        }
        return prev;
    }
    Node* compute(Node* head)
    {
        head = reverseList(head); // reversing the LL 
        Node* ptr = head, * temp;
        int maxVal = -1;

        while (ptr->next)// iterating the LL & removing elements smaller than max val.
        {
            maxVal = max(maxVal, ptr->data);
            if (maxVal > ptr->next->data)
            {
                temp = ptr->next;
                ptr->next = temp->next;
                delete temp;
            }
            else
                ptr = ptr->next;
        }
        return reverseList(head); // returning reverse of the LL
    }

};



//{ Driver Code Starts.

int main()
{
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
        Node* result = ob.compute(head);
        print(result);
        cout << endl;
    }
}

// } Driver Code Ends