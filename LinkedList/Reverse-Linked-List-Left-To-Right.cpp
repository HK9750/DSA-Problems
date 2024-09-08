// Leetcode : 92. Reverse Linked List II

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    ListNode *reverseBetween(ListNode *head, int m, int n)
    {
        if (head == nullptr)
        {
            return head;
        }

        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *prev = dummy;

        for (int i = 0; i < m - 1; i++)
        {
            prev = prev->next;
        }

        ListNode *current = prev->next;
        ListNode *next = nullptr;

        for (int i = 0; i < n - m; i++)
        {
            next = current->next;
            current->next = next->next;
            next->next = prev->next;
            prev->next = next;
        }

        return dummy->next;
    }
};

// Explaination

// The idea is to reverse the nodes between the given positions m and n.

// We create a dummy node and set its next pointer to the head of the linked list.

// We create a pointer prev and set it to the dummy node.

// We iterate through the linked list and move the prev pointer m-1 steps.

// We create two pointers current and next and set them to the next pointer of the prev pointer.

// We reverse the nodes between the given positions m and n.

// We return the head of the linked list.