// Leetcode 61. Rotate List

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (!head)
            return nullptr;
        ListNode *p = head;
        int len = 1;
        while (p->next)
        {
            p = p->next;
            len++;
        }
        p->next = head;
        k = len - (k % len);
        while (k--)
        {
            p = p->next;
        }
        ListNode *ans = p->next;
        p->next = nullptr;
        return ans;
    }
};

// Explanation:

// 1. We first calculate the length of the linked list by traversing it.
// 2. We connect the last node to the first node to form a circular linked list.
// 3. We calculate the new head position by moving len - (k % len) steps from the head.
// 4. We update the next pointer of the node at position len - (k % len) to nullptr to break the circular linked list.
// 5. We return the new head position.