// Leetcode 160. Intersection of Two Linked Lists

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    int getLength(ListNode *head)
    {
        ListNode *temp = head;
        int size = 0;
        while (temp != nullptr)
        {
            temp = temp->next;
            size++;
        }
        return size;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        int lenA = getLength(headA);
        int lenB = getLength(headB);

        while (lenA > lenB)
        {
            headA = headA->next;
            lenA--;
        }

        while (lenB > lenA)
        {
            headB = headB->next;
            lenB--;
        }

        while (headA != headB)
        {
            headA = headA->next;
            headB = headB->next;
        }

        return headA;
    }
};

// Time Complexity: O(n)

// Space Complexity: O(1)

// Explaination

// First we will calculate the length of the two linked list.

// Then we will move the head of the longer linked list to the same position as the shorter linked list.

// Then we will move the two pointers of the linked list until they meet at the intersection point.

// Finally we will return the intersection point.
