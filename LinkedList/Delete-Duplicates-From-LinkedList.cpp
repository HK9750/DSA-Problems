// Leetcode : 83. Remove Duplicates from Sorted List
#include <bits/stdc++.h>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
    ~ListNode()
    {
        delete next;
    }
};

class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        if (head == nullptr)
            return head;

        ListNode *current = head;

        while (current != nullptr && current->next != nullptr)
        {
            if (current->val == current->next->val)
            {
                ListNode *temp = current->next;
                current->next = current->next->next;
                delete temp;
            }
            else
            {
                current = current->next;
            }
        }
        return head;
    }
};

// Explaination

// The idea is to remove the duplicates from the sorted linked list.

// First we check that if the head is null (empty Linked List) then we return the head.

// We create a pointer current and set it to the head of the linked list.

// We iterate through the linked list and check if the current value is equal to the next value.

// If the current value is equal to the next value then we delete the next node and set the next pointer of the current node to the next next node.

// If the current value is not equal to the next value then we move the current pointer to the next node.

// We return the head of the linked list.