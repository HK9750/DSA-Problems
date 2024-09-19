// Leetcode 103: Binary Tree Zigzag Level Order Traversal
#include <bits/stdc++.h>
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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> result;
        if (root == nullptr)
            return result;
        queue<TreeNode *> q;
        q.push(root);
        bool flag = true;

        while (!q.empty())
        {
            int size = q.size();
            vector<int> v(size);

            for (int i = 0; i < size; i++)
            {
                TreeNode *node = q.front();
                q.pop();
                int to_push = flag ? i : size - i - 1;
                v[to_push] = node->val;

                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            flag = !flag;
            result.push_back(v);
        }
        return result;
    }
};

// Explaination:

// We will use a queue to store the nodes of the tree. We will also use a flag to keep track of the direction of the traversal. If the flag is true, we will traverse the nodes from left to right, otherwise from right to left.

// We will start by pushing the root node into the queue. We will then iterate over the queue until it is empty. For each level, we will create a vector to store the nodes of that level. We will iterate over the nodes of the current level and add them to the vector based on the value of the flag. If the flag is true, we will add the nodes from left to right, otherwise from right to left.