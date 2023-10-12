/*
Idea:
using 2 pointer approach, one from start and one from end,
 checking if both makes the target value, else updating the pointers
*/

//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node* next, * prev;
    Node(int val) : data(val), next(NULL), prev(NULL)
    {
    }
};


// } Driver Code Ends
//User function Template for C++


class Solution
{
public:
    vector<pair<int, int>> findPairsWithGivenSum(Node* head, int target)
    {
        vector<pair<int, int>> ans;

        Node* front = head, * back = head;
        while (back->next)
            back = back->next;

        while (front != back && front != back->next)
        {
            if (front->data + back->data == target)
            {
                ans.push_back({ front->data ,back->data });
                front = front->next;
                back = back->prev;
            }
            else if (front->data + back->data < target) // if sum < target, incrementing the front pointer
                front = front->next;
            else  // if sum <> target, decrementing the back pointer
                back = back->prev;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, target;
        cin >> target >> n;
        int a;
        cin >> a;
        Node* head = new Node(a);
        Node* tail = head;
        for (int i = 0; i < n - 1; i++)
        {
            cin >> a;
            tail->next = new Node(a);
            tail->next->prev = tail;
            tail = tail->next;
        }
        Solution ob;
        auto ans = ob.findPairsWithGivenSum(head, target);
        if (ans.size() == 0)
            cout << "-1";
        else
        {
            for (int i = 0; i < ans.size(); i++)
            {
                cout << "(" << ans[i].first << "," << ans[i].second << ")"
                    << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends