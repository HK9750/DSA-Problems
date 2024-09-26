// Leetcode 15. 3Sum

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        int n = nums.size();
        set<vector<int>> set;
        sort(nums.begin(), nums.end());
        int target = 0;

        for (int i = 0; i < n; i++)
        {
            int k = i + 1;
            int l = n - 1;
            while (k < l)
            {
                int sum = nums[i] + nums[k] + nums[l];
                if (sum == target)
                {
                    set.insert({nums[i], nums[k], nums[l]});
                    k++;
                    l--;
                }
                else if (sum > target)
                    l--;
                else
                    k++;
            }
        }
        vector<vector<int>> ans;
        for (auto &s : set)
        {
            ans.push_back(s);
        }
        return ans;
    }
};

// Explanation

// We can use the two-pointer approach to solve this problem. We can first sort the input array. We can then iterate over the array and for each element, we can use two pointers, k and l, to find the other two elements that sum up to the target. We can then add the triplet to a set to avoid duplicates. Finally, we can convert the set to a vector and return the result.