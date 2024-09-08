// Leetcode : 25. Reverse Nodes in k-Group
// A Leetcode Hard :(

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode *cursor = head;

        for (int i = 0; i < k; i++)
        {
            if (cursor == nullptr)
            {
                return head;
            }
            cursor = cursor->next;
        }

        ListNode *prev = nullptr;
        ListNode *current = head;
        ListNode *next = nullptr;

        for (int i = 0; i < k; i++)
        {
            nxt = current->next;
            current->next = prev;
            prev = current;
            current = nxt;
        }

        head->next = reverseKGroup(current, k);
        return prev;
    }
};

// Explaination

// The idea is to reverse the nodes in k groups.

// We create a cursor pointer and set it to the head of the linked list.

// We iterate through the linked list and move the cursor pointer k steps.

// If the cursor pointer reaches the end of the linked list, then we return the head of the linked list.

// We create three pointers prev=nullptr, current = head, and next=nullptr.

// As we are using recursion, so the concept is that solve one case then recursion will solve the remaining.

// We reverse the k nodes of the linked list.

// We set the next pointer of the head of the linked list to the result of the next recursion call.

// We return the prev pointer.

// We repeat the above steps until we reach the end of the linked list.
