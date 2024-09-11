// Leetcode 1721. Swapping Nodes in a Linked List

struct ListNode *
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
    vector<ListNode *> solve(ListNode *head, int k)
    {
        vector<ListNode *> ans;
        ListNode *temp = head;
        int n = 0;

        while (temp != nullptr)
        {
            ans.push_back(temp);
            temp = temp->next;
        }
        return ans;
    }

public:
    ListNode *swapNodes(ListNode *head, int k)
    {
        vector<ListNode *> nums = solve(head, k);
        int n = nums.size();

        swap(nums[k - 1]->val, nums[n - k]->val);
        return head;
    }
};

// Explaination

// First we will create a vector of the linked list.

// Then we will swap the kth element from the start and kth element from the end.

// Time Complexity: O(N)