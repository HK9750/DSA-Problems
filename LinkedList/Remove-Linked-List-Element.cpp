// Leetcode : 203. Remove Linked List Elements

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    ListNode *removeElements(ListNode *head, int val)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *prev = dummy;

        while (head)
        {
            if (head->val == val)
            {
                prev->next = -head->next;
                delete head;
            }
            else
            {
                prev = head;
            }
            head = prev->next;
        }
        return dummy->next;
    };
};

// Explaination

// Dont get confused by the the use of ios_base::sync_with_stdio(false); cin.tie(nullptr);. It is used to speed up the input output process.

// The idea is to remove all the nodes with the given value from the linked list.

// We create a dummy node and set its next pointer to the head of the linked list.

// We create a pointer prev and set it to the dummy node.

// We iterate through the linked list and check if the value of the head node is equal to the given value.

// If the value of the head node is equal to the given value, then we set the next pointer of the previous node to the next pointer of the head node.

// We delete the current node.

// If the value of the head node is not equal to the given value, then we set the previous node to the head node.

// We set the head node to the next node.

// We repeat the above steps until we reach the end of the linked list.