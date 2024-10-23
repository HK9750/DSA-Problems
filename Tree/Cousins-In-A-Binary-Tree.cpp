// Leetcode 2641. Cousins in Binary Tree II

// BFS_SOLUTION
class Solution
{
public:
    TreeNode *replaceValueInTree(TreeNode *root)
    {
        if (!root)
            return nullptr;

        queue<TreeNode *> q;
        q.push(root);

        root->val = 0;

        while (!q.empty())
        {
            int levelSum = 0;
            int cnt = q.size();

            vector<TreeNode *> currentLevel;
            for (int i = 0; i < cnt; i++)
            {
                TreeNode *node = q.front();
                q.pop();

                if (node->left)
                {
                    levelSum += node->left->val;
                    q.push(node->left);
                }
                if (node->right)
                {
                    levelSum += node->right->val;
                    q.push(node->right);
                }

                currentLevel.push_back(node);
            }

            for (TreeNode *node : currentLevel)
            {
                int siblingsSum = 0;
                if (node->left)
                    siblingsSum += node->left->val;
                if (node->right)
                    siblingsSum += node->right->val;

                if (node->left)
                {
                    node->left->val = levelSum - siblingsSum;
                }
                if (node->right)
                {
                    node->right->val = levelSum - siblingsSum;
                }
            }
        }

        return root;
    }
};

// DFS_SOLUTION

class Solution
{
public:
    void traverse(TreeNode *root, int i, vector<int> &arr)
    {
        if (!root)
            return;

        if (arr.size() > i)
            arr[i] += root->val;
        else
            arr.push_back(root->val);

        traverse(root->left, i + 1, arr);
        traverse(root->right, i + 1, arr);
    }
    void traverse2(TreeNode *root, int i, vector<int> &arr)
    {
        if (!root)
            return;

        int temp = 0;
        if (arr.size() > i)
            temp += arr[i];

        if (root->left)
            temp -= root->left->val;
        if (root->right)
            temp -= root->right->val;

        if (root->left)
            root->left->val = temp;
        if (root->right)
            root->right->val = temp;

        traverse2(root->left, i + 1, arr);
        traverse2(root->right, i + 1, arr);
    }
    TreeNode *replaceValueInTree(TreeNode *root)
    {
        vector<int> arr;

        traverse(root, 0, arr);
        root->val = 0;

        traverse2(root, 1, arr);
        return root;
    }
};
