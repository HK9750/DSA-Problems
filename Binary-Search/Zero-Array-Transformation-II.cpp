// Leetcode 3356. Zero Array Transformation II

class Solution
{
public:
    int n;
    int Q;

    bool checkWithDifferenceArrayTeq(vector<int> &nums, vector<vector<int>> &queries, int k)
    {
        vector<int> diff(n, 0);

        // O(Q)
        for (int i = 0; i <= k; i++)
        {
            int l = queries[i][0];
            int r = queries[i][1];
            int x = queries[i][2];

            diff[l] += x;
            if (r + 1 < n)
                diff[r + 1] -= x;
        }

        int cumSum = 0;
        // O(n)
        for (int i = 0; i < n; i++)
        {
            cumSum += diff[i];

            diff[i] = cumSum;

            if (nums[i] - diff[i] > 0)
            { // nums[i] 0 nahi ban paya
                return false;
            }
        }

        return true;
    }

    int minZeroArray(vector<int> &nums, vector<vector<int>> &queries)
    {
        n = nums.size();
        Q = queries.size();

        auto lambda = [](int x)
        {
            return x == 0;
        };

        if (all_of(begin(nums), end(nums), lambda))
        {
            return 0; // no query required because all are already zero
        }

        int l = 0;
        int r = Q - 1;
        int k = -1;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;

            if (checkWithDifferenceArrayTeq(nums, queries, mid) == true)
            {
                k = mid + 1; // possible answer
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }

        return k;
    }
};

// Explaination:

// We are given an array of integers and a list of queries. Each query is of the form [l, r, x]. We need to find the minimum number of queries required to make the array zero. We can use binary search to solve this problem.
// We will use binary search to find the minimum number of queries required to make the array zero.
// We will check if the array can be made zero using the first k queries. We will use the difference array to check if the array can be made zero using the first k queries.
// We will return the minimum number of queries required to make the array zero.
// The time complexity of this approach is O(Q * n) where n is the size of the array and Q is the number of queries. The space complexity of this approach is O(n) where n is the size of the array.