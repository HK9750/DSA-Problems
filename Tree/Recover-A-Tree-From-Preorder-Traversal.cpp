// Leetcode 1028. Recover a Tree from PreOrder Traversal

class Solution
{
public:
    int n;

    TreeNode *solve(const string &traversal, int &i, int depth)
    {
        if (i >= n)
            return NULL;

        int j = i;
        while (j < n && traversal[j] == '-')
        {
            j++;
        }

        int dash = j - i;

        if (depth != dash)
        {
            return NULL;
        }

        i += dash;

        int value = 0;
        while (i < n && isdigit(traversal[i]))
        {
            value = value * 10 + (traversal[i] - '0');
            i++;
        }

        TreeNode *root = new TreeNode(value);

        root->left = solve(traversal, i, depth + 1);
        root->right = solve(traversal, i, depth + 1);

        return root;
    }

    TreeNode *recoverFromPreorder(string traversal)
    {
        n = traversal.length();
        int i = 0;
        return solve(traversal, i, 0);
    }
};

// Explaination:

// We call the solve function recursively to build the tree. The function takes the traversal string, the current index i, and the current depth as arguments. The function returns the root of the subtree rooted at the current node.
// The function first checks if the current index i is out of bounds. If it is, the function returns NULL.
// The function then finds the number of dashes at the current index i. This number is the depth of the current node. If the depth is not equal to the given depth, the function returns NULL.
// The function then increments the index i by the number of dashes.
// The function then reads the value of the current node from the traversal string. It reads the digits until a non-digit character is encountered.
// The function then creates a new TreeNode with the value of the current node.
// The function then recursively calls itself to build the left subtree of the current node with a depth one greater than the current depth.
// The function then recursively calls itself to build the right subtree of the current node with a depth one greater than the current depth.
// The function returns the root of the subtree rooted at the current node.
// The main function recoverFromPreorder initializes the index i to 0 and calls the solve function to build the tree.
// The main function returns the root of the tree.
