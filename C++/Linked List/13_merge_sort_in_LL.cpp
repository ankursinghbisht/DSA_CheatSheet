/*
Idea:
Recursively splitting the Linked List in halves, and performing LL merge in sorted LL. till whole LL is sorted.
*/

//{ Driver Code Starts
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
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


// } Driver Code Ends

class Solution {
public:
    // Merge two sorted linked lists and return the merged list.
    Node* sortedMerge(Node* head1, Node* head2) {
        Node* merged = nullptr;
        Node* current = nullptr;
        Node* t1 = head1;
        Node* t2 = head2;

        // Determine the head of the merged list.
        if (t1->data < t2->data) {
            merged = head1;
            t1 = t1->next;
        }
        else {
            merged = head2;
            t2 = t2->next;
        }
        current = merged;

        // Merge the two lists.
        while (t1 != nullptr && t2 != nullptr) {
            if (t1->data < t2->data) {
                current->next = t1;
                t1 = t1->next;
            }
            else {
                current->next = t2;
                t2 = t2->next;
            }
            current = current->next;
        }

        // Append any remaining nodes from both lists.
        if (t1) {
            current->next = t1;
        }
        else if (t2) {
            current->next = t2;
        }

        return merged;
    }

    // Split the linked list into two halves and return them as a pair.
    pair<Node*, Node*> splitLinkedList(Node* head) {
        if (!head || !head->next) {
            return { head, nullptr };
        }

        Node* slow = head;
        Node* fast = head;
        Node* prev = nullptr;

        // Find the middle of the list using slow and fast pointers.
        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        // Disconnect the first half from the second half.
        if (prev) {
            prev->next = nullptr;
        }

        return { head, slow };
    }

    // Sort the given linked list using Merge Sort.
    Node* mergeSort(Node* head) {
        if (!head || !head->next) {
            return head;
        }

        // Split the list into two halves.
        pair<Node*, Node*> halves = splitLinkedList(head);

        // Recursively sort and merge the two halves.
        return sortedMerge(mergeSort(halves.first), mergeSort(halves.second));
    }
};


//{ Driver Code Starts.

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    long test;
    cin >> test;
    while (test--) {
        struct Node* a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            push(&a, tmp);
        }
        Solution obj;
        a = obj.mergeSort(a);
        printList(a);
    }
    return 0;
}
// } Driver Code Ends