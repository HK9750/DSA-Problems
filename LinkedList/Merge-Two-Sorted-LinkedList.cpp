// Leetcode : 21. Merge Two Sorted Lists

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        if (list1 == nullptr && list2 == nullptr)
            return nullptr;
        if (list1 == nullptr)
            return list2;
        if (list2 == nullptr)
            return list1;

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
};

// Explaination

// The idea is to merge two sorted linked lists into a single sorted linked list. We can do this by iterating through both the linked lists and comparing the values of the nodes.

// First we check if both the linked lists are empty, if they are then we return nullptr.

// We check if either of the linked lists is empty, if it is then we return the other linked list.

// We create a dummy node and a temp node which will point to the dummy node because we will be changing the next pointers of the nodes.

// We iterate through both the linked lists and compare the values of the nodes.

// If the value of the node in the first linked list is less than the value of the node in the second linked list, then we point the next pointer of the temp node to the node in the first linked list and move the pointer of the first linked list to the next node.

// If the value of the node in the first linked list is greater than or equal to the value of the node in the second linked list, then we point the next pointer of the temp node to the node in the second linked list and move the pointer of the second linked list to the next node.

// We move the temp pointer to the next node.

// We repeat the above steps until we reach the end of either of the linked lists.

// We point the next pointer of the temp node to the remaining linked list.

// We return the next pointer of the dummy node because we dont want the first node -1.