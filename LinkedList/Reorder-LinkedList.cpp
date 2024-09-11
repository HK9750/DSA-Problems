// Leetcode : 143. Reorder List
// Using my own stack logic

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    stack<ListNode *> makeStack(ListNode *head)
    {
        stack<ListNode *> ans;
        ListNode *temp = head;
        while (temp != nullptr)
        {
            ans.push(temp);
            temp = temp->next;
        }
        return ans;
    }
    void reorderList(ListNode *head)
    {
        if (!head || !head->next)
            return;
        stack<ListNode *> nums = makeStack(head);
        ListNode *temp = head;
        int n = nums.size() / 2;

        while (n--)
        {
            ListNode *nxt = temp->next;
            ListNode *newNode = nums.top();
            nums.pop();
            temp->next = newNode;
            newNode->next = nxt;
            temp = nxt;
        }
        temp->next = nullptr;
    }
};

// Explaination

// First we will create a stack of the linked list.

// Then we will iterate through the linked list and pop the top element from the stack and insert it after the current node.

// We will repeat this process until we reach the middle of the linked list.

// Then we will set the next of the last node to NULL.

// Time Complexity: O(N)