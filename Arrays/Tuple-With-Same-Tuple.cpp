// Leetcode 1726. Tuple with Same Product

class Solution
{
public:
    int tupleSameProduct(std::vector<int> &nums)
    {
        unordered_map<int, int> productCount;
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int product = nums[i] * nums[j];
                productCount[product]++;
            }
        }

        int result = 0;
        for (const auto &entry : productCount)
        {
            int count = entry.second;
            if (count > 1)
            {
                result += count * (count - 1) * 4;
            }
        }

        return result;
    }
};

// Explaination:

// We can use a hash map to store the product of each pair of numbers in the input array nums. The key of the hash map is the product of the pair, and the value is the number of pairs that have the same product.
// After we have stored all the products in the hash map, we can iterate through the hash map and calculate the number of tuples that have the same product. If there are k pairs that have the same product, then there are k * (k - 1) * 4 tuples that have the same product.
// Finally, we return the total number of tuples that have the same product.
