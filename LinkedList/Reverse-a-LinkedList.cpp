// Leetcode 206. Reverse Linked List

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    ListNode *reverse(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }

        ListNode *chotaHead = reverse(head->next);

        head->next->next = head;
        head->next = nullptr;

        return chotaHead;
    }

    ListNode *reverseList(ListNode *head)
    {
        return reverse(head);
    }
};

// Explaination

// The idea is to reverse the linked list by reversing the next pointers of the nodes. We can do this by recursively reversing the next pointers of the nodes.

// First we check that head is not null or head->next is not null, if it is then we return head.

// We call the reverse function recursively on the next node and store the returned value in chotaHead.
// We beleive that chotaHead has reversed the remaining linked list.
// Now we just have to reverse the single node head.
//  We can do that by head->next->next = head; head->next = nullptr;