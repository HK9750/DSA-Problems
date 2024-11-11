// Leetcode 3097. Shortest Subarray with Sum at Least K II

class Solution
{
public:
    int minimumSubarrayLength(vector<int> &nums, int k)
    {
        vector<int> count(32, 0);
        int start = 0, end = 0, minLength = INT_MAX;

        while (end < nums.size())
        {
            updateBits(count, nums[end], 1);
            while (start <= end && getVal(count) >= k)
            {
                minLength = min(minLength, end - start + 1);
                updateBits(count, nums[start], -1);
                start++;
            }
            end++;
        }

        return minLength == INT_MAX ? -1 : minLength;
    }

private:
    void updateBits(vector<int> &count, int num, int val)
    {
        for (int i = 0; i < 32; i++)
        {
            if ((num >> i) & 1)
            {
                count[i] += val;
            }
        }
    }

    int getVal(const vector<int> &count)
    {
        int ans = 0;
        for (int i = 0; i < 32; i++)
        {
            if (count[i] > 0)
            {
                ans |= (1 << i);
            }
        }
        return ans;
    }
};

// Explaination:
// We will maintain a count array of size 32, which will store the count of each bit in the current window.
// We will keep on updating the count array as we move the window.
// We will keep on updating the start of the window until the sum of the bits in the window is greater than or equal to k.
// We will keep on updating the minLength as we move the window.
// Finally, we will return the minLength.
