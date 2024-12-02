// Leetcode 2300. Successfull pairs of Spells and potions

class Solution
{
public:
    vector<int> successfulPairs(vector<int> &spells, vector<int> &potions,
                                long long success)
    {
        int n = spells.size();
        int m = potions.size();
        sort(begin(potions), end(potions));
        vector<int> res(n);

        for (int i = 0; i < n; i++)
        {
            long long prod = spells[i];
            int l = 0, r = m - 1, index = m;
            while (l <= r)
            {
                int mid = l + (r - l) / 2;
                if (prod * potions[mid] >= success)
                {
                    index = mid;
                    r = mid - 1;
                }
                else
                {
                    l = mid + 1;
                }
            }
            res[i] = m - index;
        }

        return res;
    }
};

// Explaination

// We will sort the potions array.
// We will iterate over the spells array and for each spell, we will calculate the product of the spell and the potion.
// We will then find the index of the first potion such that the product of the spell and the potion is greater than or equal to the success value.
// We will then calculate the number of successful pairs by subtracting the index from the length of the potions array.
// We will store the number of successful pairs for each spell in the result array and return it.
// The time complexity of this approach is O(nlogm), where n is the length of the spells array and m is the length of the potions array. The space complexity is O(1).
