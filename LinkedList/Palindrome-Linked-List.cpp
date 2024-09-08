// Leetcode : 234. Palindrome Linked List

#include <bits/stdc++.h>
#include <vector>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        vector<int> ans;
        ListNode *temp = head;

        while (temp != nullptr)
        {
            ans.push_back(temp->val);
            temp = temp->next;
        }
        int l = 0, r = ans.size() - 1;
        while (l < r)
        {
            if (ans[l] != ans[r])
                return false;
            r--;
            l++;
        }
        return true;
    }
};

// Explaination

// Dont get confused by the the use of ios_base::sync_with_stdio(false); cin.tie(nullptr);. It is used to speed up the input output process.

// The idea is to check if the linked list is a palindrome. We can do this by storing the values of the nodes in a vector and then checking if the vector is a palindrome.

// We create a vector to store the values of the nodes.

// We iterate through the linked list and store the values of the nodes in the vector.

// We use two pointers l and r to check if the vector is a palindrome.

// We iterate through the vector and check if the values at the left and right pointers are equal.

// If they are not equal, then we return false.

// If they are equal, then we increment the left pointer and decrement the right pointer.

// We repeat the above steps until the left pointer is less than the right pointer.

// If the left pointer is less than the right pointer, then we return true.