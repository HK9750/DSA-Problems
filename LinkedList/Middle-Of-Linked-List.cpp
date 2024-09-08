// Leetcode : 876. Middle of the Linked List

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    ListNode *middleNode(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};

// Explaination

// The idea is to find the middle node of the linked list.

// We create two pointers slow and fast and set them to the head of the linked list.

// We iterate through the linked list and move the slow pointer one step at a time and the fast pointer two steps at a time.

// When the fast pointer reaches the end of the linked list, the slow pointer will be at the middle of the linked list.

// We return the slow pointer.
