// Leetcode 23: Merge K Sorted Linked List

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(NULL) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *mergeKListsHelper(vector<ListNode *> &lists, int s, int e)
    {
        if (s == e)
            return lists[s];
        if (s + 1 == e)
            return mergeSorted(lists[s], lists[e]);

        int mid = s + (e - s) / 2;
        ListNode *left = mergeKListsHelper(lists, s, mid);
        ListNode *right = mergeKListsHelper(lists, mid + 1, e);
        return mergeSorted(left, right);
    }
    ListNode *mergeSorted(ListNode *list1, ListNode *list2)
    {

        ListNode *dummy = new ListNode(-1);
        ListNode *temp = dummy;

        while (list1 != nullptr && list2 != nullptr)
        {
            if (list1->val < list2->val)
            {
                temp->next = list1;
                list1 = list1->next;
            }
            else
            {
                temp->next = list2;
                list2 = list2->next;
            }
            temp = temp->next;
        }
        temp->next = (list1 != nullptr) ? list1 : list2;
        return dummy->next;
    }

    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        if (lists.empty())
            return nullptr;
        return mergeKListsHelper(lists, 0, lists.size() - 1);
    }
};

// Explanation:

// We will use the divide and conquer approach to solve this problem. We will divide the problem into smaller subproblems and then merge the results of the subproblems to get the final result.

// We will use the mergeSorted function to merge two sorted linked lists. We will merge the first half of the linked lists and the second half of the linked lists and then merge the two merged linked lists.

// We will keep on dividing the linked lists until we have only one linked list left. We will then return the merged linked list.
