//  Leetcode : 725. Split Linked List in Parts
// My solution beats 100% of the submissions in terms of runtime.

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    vector<ListNode *> splitListToParts(ListNode *head, int k)
    {
        ListNode *temp = head;
        int size = 0;

        while (temp)
        {
            temp = temp->next;
            size++;
        }

        int splitSize = size / k;
        int rem = size % k;

        temp = head;
        vector<ListNode *> ans(k, nullptr);

        for (int i = 0; i < k; ++i)
        {
            ListNode *partHead = temp;
            int currentPartSize = splitSize + (rem > 0);
            if (rem > 0)
            {
                rem--;
            }

            while (currentPartSize-- > 1 && temp != nullptr)
            {
                temp = temp->next;
            }

            if (temp)
            {
                ListNode *nxt = temp->next;
                temp->next = nullptr;
                temp = nxt;
            }
            ans[i] = partHead;
        }
        return ans;
    }
};

// Explaination

// The idea is to split the linked list into k parts. We can do this by first calculating the size of the linked list and then calculating the size of each part and the remaining nodes.

// We iterate through the linked list to calculate the size of the linked list.

// We calculate the size of each part by dividing the size of the linked list by k.

// We calculate the remaining nodes by taking the modulus of the size of the linked list by k.

// We iterate through the linked list and split the linked list into k parts.

// We iterate through k parts and set the next pointer of the last node of each part to nullptr.

// We return the k parts.

// Time Complexity: O(N)