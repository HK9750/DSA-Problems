// Leetcdoe 2471. Minimum Number of Operations to Sort a Binary Tree by Level

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
    int ans = 0;
    void getSwaps(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return;
        vector<pair<int, int>> v;

        for (int i = 0; i < n; i++)
        {
            v.push_back({nums[i], i});
        }

        sort(v.begin(), v.end());

        for (int i = 0; i < n; i++)
        {
            if (v[i].second == i)
                continue;
            else
            {
                ans++;
                swap(v[i], v[v[i].second]);
                i--;
            }
        }
    }
    int minimumOperations(TreeNode *root)
    {
        if (!root)
            return 0;

        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            int size = q.size();
            vector<int> level;
            for (int i = 0; i < size; i++)
            {
                auto temp = q.front();
                q.pop();
                if (temp->left)
                {
                    q.push(temp->left);
                    level.push_back(temp->left->val);
                };
                if (temp->right)
                {
                    q.push(temp->right);
                    level.push_back(temp->right->val);
                };
            }
            getSwaps(level);
        }
        return ans;
    }
};

// Explanation

// If we are sorting by levels then we should do a BFS traversal of the tree. We will keep track of the level elements in a vector and then we will sort the vector and then we will count the number of swaps required to sort the vector. We will do this for all the levels and return the total number of swaps required.
// The only part to figure out was how to get the swaps required to sort the vector. We can do this by storing the index of the element in the vector and then sorting the vector and then comparing the index of the element with the index of the element in the sorted vector. If the indexes are not the same then we will swap the elements and increment the count of swaps. We will do this for all the elements in the vector and return the total number of swaps required.