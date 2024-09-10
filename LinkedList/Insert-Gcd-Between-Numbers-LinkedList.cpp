// Leetcode 2807. Insert Gcd Between Numbers in Linked List

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    int gcd(int a, int b)
    {
        while (b != 0)
        {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    ListNode *insertGreatestCommonDivisors(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode *temp1 = head;
        ListNode *temp2 = head->next;
        while (temp2 != nullptr)
        {
            int num = gcd(temp1->val, temp2->val);
            ListNode *newNode = new ListNode(num);
            temp1->next = newNode;
            newNode->next = temp2;
            temp1 = temp2;
            temp2 = temp2->next;
        }
        return head;
    }
};

// Time Complexity: O(n)

// Space Complexity: O(1)

// Explaination

// We will iterate through the linked list and calculate the gcd of the current node and the next node.

// First we take the first two elements of the linked list and calculate the gcd of the two elements.

// Then we will insert the gcd between the two elements.

// Then we will move the temp1 and temp2 to the next two elements and repeat the process.

// We will repeat the process until we reach the end of the linked list.

// Finally we will return the head of the linked list.
