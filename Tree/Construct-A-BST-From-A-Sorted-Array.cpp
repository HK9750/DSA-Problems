// Leetcode 108. Convert Sorted Array to Binary Search Tree

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        return MakeBst(nums, 0, nums.size() - 1);
    }
    TreeNode *MakeBst(vector<int> &nums, int s, int e)
    {
        if (s > e)
            return nullptr;

        int mid = e - (e - s) / 2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->right = MakeBst(nums, mid + 1, e);
        root->left = MakeBst(nums, s, mid - 1);

        return root;
    }
};

// Explaination

// Base case: If the start index is greater than the end index then we will return nullptr.

// We will find the mid index of the array.

// We will create a new node with the value of the mid index.

// We will recursively call the function for the left and right subtree.

// We will return the root node.
