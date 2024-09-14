// Leetcode 82. Remove Duplicates from Sorted List II

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

        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *prev = dummy;
        ListNode *current = head;

        while (current != nullptr)
        {
            while (current->next != nullptr && current->val == current->next->val)
            {
                current = current->next;
            }

            if (prev->next == current)
            {
                prev = prev->next;
            }
            else
            {
                prev->next = current->next;
            }

            current = current->next;
        }

        return dummy->next;
    }
};

// Explaination

// The idea is to remove the duplicates from the sorted linked list.

// First we check that if the head is null (empty Linked List) then we return the head.

// We create a dummy node and set its next pointer to the head of the linked list.

// We create two pointers prev and current and set them to the dummy node and head of the linked list respectively.

// We iterate through the linked list and check if the current value is equal to the next value.

// If the current value is equal to the next value then we move the current pointer to the next node.

// If the current value is not equal to the next value then we check if the next pointer of the prev node is equal to the current node.

// If the next pointer of the prev node is equal to the current node then we move the prev pointer to the next node.

// If the next pointer of the prev node is not equal to the current node then we set the next pointer of the prev node to the next pointer of the current node.

// We move the current pointer to the next node.

// We return the next pointer of the dummy node.