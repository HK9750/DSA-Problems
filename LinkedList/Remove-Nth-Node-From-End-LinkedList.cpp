// Leetcode 19. Remove Nth Node From End of List

struct ListNode
{

    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    int getLength(ListNode *head)
    {
        ListNode *temp = head;
        int size = 0;
        while (temp != nullptr)
        {
            temp = temp->next;
            size++;
        }
        return size;
    }
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        int len = getLength(head);
        int del = len - n;
        if (del == 0)
        {
            return head->next;
        }
        ListNode *temp = head;
        ListNode *prev = nullptr;
        int i = 0;

        while (del > i)
        {
            prev = temp;
            temp = temp->next;
            i++;
        }

        prev->next = temp->next;
        delete temp;
        return head;
    }
};

// Explaination

// First we will calculate the length of the linked list.

// Then we will calculate the position of the node to be deleted i.e del - n;

// If the node to be deleted is the first node then we will return the next node.

// Then we create two pointers temp and prev.

// Then we will iterate through the linked list until we reach the node to be deleted.

// Then we will delete the node and return the head of the linked list.
