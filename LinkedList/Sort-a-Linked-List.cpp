// Leetcode : 148. Sort List

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *mergeListSorted(ListNode *l1, ListNode *l2)
    {
        if (l1 == nullptr && l2 == nullptr)
            return NULL;
        if (l1 == nullptr)
            return l2;
        if (l2 == nullptr)
            return l1;

        ListNode *dummy = new ListNode(-1);
        ListNode *temp = dummy;

        while (l1 != nullptr && l2 != nullptr)
        {
            if (l1->val < l2->val)
            {
                temp->next = l1;
                l1 = l1->next;
            }
            else
            {
                temp->next = l2;
                l2 = l2->next;
            }
            temp = temp->next;
        }

        temp->next = (l1 != nullptr) ? l1 : l2;
        return dummy->next;
    };

    ListNode *sortList(ListNode *head)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        if (head == NULL || head->next == NULL)
            return head;

        ListNode *temp = NULL;
        ListNode *slow = head;
        ListNode *fast = head;

        while (fast != nullptr && fast->next != nullptr)
        {
            temp = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        temp->next = nullptr;

        ListNode *l1 = sortList(head);
        ListNode *l2 = sortList(slow);

        return mergeListSorted(l1, l2);
    }
};

// Time Complexity: O(nlogn)

// Space Complexity: O(1)

// Explaination

// We will sort the Linked List using merge sort. We will divide the linked list into two parts and then merge them in sorted order.

// First we Calculate the middle of the linked list using slow and fast pointer.

// Then we will divide the linked list into two parts using the middle node.

// Then we will sort the two linked list using recursion.

// Then we will merge the two sorted linked list using mergeListSorted function.