// leetcode 2554. Maximum Number of Integers That Can Be Chosen from the Range I

class Solution
{
public:
    int maxCount(vector<int> &banned, int n, int maxSum)
    {
        unordered_set<int> bannedSet(banned.begin(), banned.end());
        int count = 0, sum = 0;

        for (int i = 1; i <= n; ++i)
        {
            if (bannedSet.count(i) == 0 && sum + i <= maxSum)
            {
                sum += i;
                ++count;
            }
            else if (sum + i > maxSum)
            {
                break;
            }
        }

        return count;
    }
};

// Explanation:

// We can use a set to store the banned integers.
// Then we can iterate from 1 to n and check if the current integer is not in the banned set and the sum of the current integer and the sum is less than or equal to maxSum.
// If the condition is true, we can add the current integer to the sum and increment the count.
// If the sum of the current integer and the sum is greater than maxSum, we can break the loop.
// Finally, we can return the count.
