// Leetcode 100. Same Tree

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (p == nullptr && q == nullptr)
            return 1;
        if (p == nullptr || q == nullptr || p->val != q->val)
            return 0;
        return isSameTree(p->right, q->right) && isSameTree(p->left, q->left);
    }
};

// Explaination:

// We will check if two binary trees are the same using a recursive approach.

// If both the roots are null, we will return true.

// If one of the roots is null or the values of the roots are not equal, we will return false.

// We will recursively check if the left subtrees of the two trees are the same.

// We will recursively check if the right subtrees of the two trees are the same.

// We will return true if the two trees are the same.

// Time Complexity: O(N), where N is the number of nodes in the tree. The time complexity is O(N) because we are visiting each node once. The space complexity is O(N) due to the recursive calls on the stack.