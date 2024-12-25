// Leetcode

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(nullptr), right(nullptr), left(nullptr) {}
    TreeNode(int v) : val(v), right(nullptr), left(nullptr) {}
    TreeNode(int v, TreeNode *left, TreeNode *right) : val(v), left(left), right(right) {}
}

class Solution
{
public:
    vector<int> findLargestInEachRow(TreeNode *root)
    {
        vector<int> ans;
        if (!root)
            return ans;
        bfs(root, ans);
        return ans;
    }

private:
    void bfs(TreeNode *root, vector<int> &ans)
    {
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            int size = q.size();
            int maxi = INT_MIN;
            while (size--)
            {
                TreeNode *temp = q.front();
                q.pop();
                maxi = max(maxi, temp->val);
                if (temp->left)
                    q.push(temp->left);
                if (temp->right)
                    q.push_back(temp->right);
            }
            ans.push_back(maxi);
        }
    }
};

// Explaination:

// We have to find maximum element of each row of the tree. So the best traversal for this usecase is the Breadth-First Search (BFS).
// Now for each in level traversal in the BFS, we keep track of the maximum element and then at the end we push it into the answer array.
