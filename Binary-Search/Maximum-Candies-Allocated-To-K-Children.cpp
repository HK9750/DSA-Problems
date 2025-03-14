// Leetcode 2226. Maximum Candies Allocated to K Children

class Solution
{
public:
    bool check(vector<int> &nums, long long k, int mid)
    {
        int n = nums.size();
        long long int ans = 0;

        for (int i = 0; i < n; i++)
        {
            ans += (nums[i] / mid);
        }

        return ans >= k;
    }

    int maximumCandies(vector<int> &nums, long long k)
    {
        int n = nums.size();

        int r = *max_element(begin(nums), end(nums));

        int l = 0;

        while (l < r)
        {
            int mid = (l + r + 1) / 2;

            if (check(nums, k, mid))
            {
                l = mid;
            }
            else
            {
                r = mid - 1;
            }
        }

        return l;
    }
};

// Explaination:

// We are given an array of integers. We need to find the maximum number of candies that can be allocated to k children. We can use binary search to solve this problem.
// First we will find the maximum element in the array. We will use this maximum element as the upper bound of the binary search.
// We will use binary search to find the maximum number of candies that can be allocated to k children
// We will check if the number of candies that can be allocated to k children is greater than or equal to k. If it is greater than or equal to k, we will update the lower bound of the binary search. Otherwise, we will update the upper bound of the binary search.
// We will return the lower bound of the binary search as the answer.