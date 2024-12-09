// Leetcode 3152. Special Array II

// Using Prefix Sum Technique

class Solution
{
public:
    vector<bool> isArraySpecial(vector<int> &nums,
                                vector<vector<int>> &queries)
    {
        int m = queries.size();
        int n = nums.size();
        vector<bool> ans(m);
        vector<int> sum(n);
        sum[0] = 0;

        for (int i = 1; i < n; i++)
        {
            sum[i] = sum[i - 1];
            if (nums[i - 1] % 2 == nums[i] % 2)
                sum[i]++;
        }

        for (int i = 0; i < m; i++)
        {
            int from = queries[i][0];
            int to = queries[i][1];
            bool flag = (sum[from] == sum[to]);
            ans[i] = flag;
        }

        return ans;
    }
};

// Explaination:

// We use the sum array to store the violating indices. We iterate over the nums array and store the sum of the violating indices in the sum array. We then iterate over the queries array and check if the sum of violating indices is the same for the given range. If it is the same, we store true in the ans array, else we store false. Finally, we return the ans array.
// Time Complexity: O(n + m)

// Using brute force

class Solution
{
public:
    vector<bool> isArraySpecial(vector<int> &nums, vector<vector<int>> &queries)
    {
        int m = queries.size();
        int n = nums.size();
        vector<bool> ans(m);

        for (int i = 0; i < m; i++)
        {
            int from = queries[i][0];
            int to = queries[i][1];
            bool flag = true;

            for (int j = from; j <= to; j++)
            {
                if (j > from && nums[j] % 2 == nums[j - 1] % 2)
                {
                    flag = false;
                    break;
                }
            }

            ans[i] = flag;
        }

        return ans;
    }
};

// Applying Binary Search on the brute force solution and also adding vector<int> vi to store the violating indices

class Solution
{
public:
    bool bSearch(vector<int> &vi, int sp, int ep)
    {
        int l = 0;
        int r = vi.size() - 1;

        while (l <= r)
        {
            int mid = l + (r - l) / 2;

            if (vi[mid] < sp)
            {
                l = mid + 1;
            }
            else if (vi[mid] > ep)
            {
                r = mid - 1;
            }
            else
            {
                return true;
            }
        }

        return false;
    }

    vector<bool> isArraySpecial(vector<int> &nums, vector<vector<int>> &queries)
    {
        int m = queries.size();
        int n = nums.size();

        for (int i = 1; i < n; i++)
        {
            if (nums[i] % 2 == nums[i - 1] % 2)
            {
                vi.push_back(i);
            }
        }

        vector<bool> result(m, false);

        for (int i = 0; i < m; i++)
        {
            int start = queries[i][0];
            int end = queries[i][1];

            bool hasViolatingIndexInRange = bSearch(vi, start + 1, end);

            if (hasViolatingIndexInRange == false)
            {
                result[i] = true;
            }
        }

        return result;
    }
};

// Explaination:

// We iterate over the nums array and store the violating indices in the vi array. We then iterate over the queries array and check if the range has any violating indices. If it does not have any violating indices, we store true in the result array, else we store false. Finally, we return the result array.
