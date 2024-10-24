// Leetcode 951. Flip Equivalent Binary Trees

class Solution
{
public:
    bool flipEquiv(TreeNode *root1, TreeNode *root2)
    {
        if (root1 == nullptr && root2 == nullptr)
            return true;
        if (root1 == nullptr || root2 == nullptr)
            return false;
        if (root1->val != root2->val)
            return false;

        return (flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right)) ||
               (flipEquiv(root1->left, root2->right) && flipEquiv(root1->right, root2->left));
    }
};

// Explaination:

// If root1 and root2 are both null, then they are flip equivalent. If only one of them is null, then they are not flip equivalent. If the values of root1 and root2 are different, then they are not flip equivalent.
// If the values of root1 and root2 are the same, we need to check whether the left child of root1 is flip equivalent to the left child of root2 and whether the right child of root1 is flip equivalent to the right child of root2, or whether the left child of root1 is flip equivalent to the right child of root2 and whether the right child of root1 is flip equivalent to the left child of root2. If any of these conditions is true, then root1 and root2 are flip equivalent. Otherwise, they are not flip equivalent.