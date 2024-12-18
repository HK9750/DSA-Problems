// Leetcode 1475. Final Prices With a Special Discount in a Shop

class Solution
{
public:
    vector<int> finalPrices(vector<int> &prices)
    {
        int n = prices.size();

        for (int i = 0; i < n; i++)
        {
            int j = i + 1;
            while (j < n && prices[j] > prices[i])
                j++;
            if (j >= n)
                continue;
            if (prices[j] <= prices[i])
                prices[i] = prices[i] - prices[j];
        }

        return prices;
    }
};

// Time Complexity: O(n^2)
// Explanation:
// - For each element in the array, we are iterating through the rest of the array to find the next smaller element.