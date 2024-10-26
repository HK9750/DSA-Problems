// Leetcode 2458. Height of Binary Tree After Subtree Removal Queries
// A leetcode hard and an interesting problem.

class Solution
{
public:
    int level[100001];
    int height[100001];
    int levelMxHt[100001];
    int levelSecMxHt[100001];

    int maxHeight(TreeNode *root, int l)
    {
        if (root == nullptr)
            return 0;

        level[root->val] = l;
        int left = maxHeight(root->left, l + 1);
        int right = maxHeight(root->right, l + 1);
        height[root->val] = max(left, right) + 1;

        if (levelMxHt[l] < height[root->val])
        {
            levelSecMxHt[l] = levelMxHt[l];
            levelMxHt[l] = height[root->val];
        }
        else if (levelSecMxHt[l] < height[root->val])
        {
            levelSecMxHt[l] = height[root->val];
        }

        return height[root->val];
    }

    vector<int> treeQueries(TreeNode *root, vector<int> &queries)
    {
        memset(level, 0, sizeof(level));
        memset(height, 0, sizeof(height));
        memset(levelMxHt, 0, sizeof(levelMxHt));
        memset(levelSecMxHt, 0, sizeof(levelSecMxHt));

        maxHeight(root, 0);
        vector<int> res;

        for (auto &x : queries)
        {
            int l = level[x];
            int h = (levelMxHt[l] == height[x]) ? levelSecMxHt[l] : levelMxHt[l];
            int ans = l + h - 1;
            res.push_back(ans);
        }

        return res;
    }
};

// Explaination:

// We will first calculate the height of the tree and store the height of each node in the height array.
// We will also store the maximum height of the nodes at each level in the levelMxHt array.
// We will also store the second maximum height of the nodes at each level in the levelSecMxHt array.
// For each query, we will find the level of the node and then find the maximum height of the nodes at that level.
// If the height of the node is equal to the maximum height of the nodes at that level, then we will take the second maximum height of the nodes at that level.
// Otherwise, we will take the maximum height of the nodes at that level.
// The answer will be the sum of the level and the maximum height of the nodes at that level minus 1.
// We will return the answer for each query in the result array.
