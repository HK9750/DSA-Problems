// Leetcode : 141. Linked List Cycle

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        ListNode *slow = head, *fast = head;
        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
                return true;
        }
        return false;
    }
};

// Explaination

// Floyd's Cycle Detection Algorithm

// Floyd's Cycle Detection Algorithm is a pointer algorithm that uses only two pointers, which move through the sequence at different speeds. It is also called the "tortoise and the hare algorithm".

// The algorithm is based on the idea that in a cyclic list, the slow pointer and the fast pointer will eventually meet at the same node. The fast pointer moves twice as fast as the slow pointer, so if there is a cycle, the fast pointer will eventually catch up to the slow pointer.If there is no cycle, the fast pointer will reach the end of the list and fast->next will be NULL and the loop will terminate.