// Leetcode 2948. Make Lexicographically Smallest Array by Swapping Elements

class Solution
{
public:
    vector<int> lexicographicallySmallestArray(vector<int> &nums, int limit)
    {
        int n = nums.size();
        vector<pair<int, int>> pairs;

        for (int i = 0; i < n; i++)
        {
            pairs.emplace_back(nums[i], i);
        }

        sort(pairs.begin(), pairs.end());

        vector<int> ans(n, 0);
        auto process = [&](vector<int> &xs, vector<int> &indices)
        {
            sort(indices.begin(), indices.end());
            for (int i = 0; i < xs.size(); i++)
            {
                ans[indices[i]] = xs[i];
            }
        };

        int prev = INT_MIN;
        vector<int> xs, indices;

        for (auto [x, index] : pairs)
        {
            if (prev != INT_MIN && x > prev + limit)
            {
                process(xs, indices);
                xs.clear();
                indices.clear();
            }
            xs.push_back(x);
            indices.push_back(index);
            prev = x;
        }

        process(xs, indices);
        return ans;
    }
};

// Explaination:

// 1. Create a vector of pairs, where each pair contains the value and the index of the value in the original array.
// 2. Sort the pairs based on the value.
// 3. Create a vector of integers, ans, of size n, where n is the size of the original array.
// 4. Create a lambda function, process, that takes two vectors of integers, xs and indices, and sorts the indices vector. Then, it assigns the values of xs to the corresponding indices in the ans vector.
// 5. Initialize prev to INT_MIN and create two vectors of integers, xs and indices.
// 6. Iterate through the pairs vector.
// 7. If prev is not INT_MIN and the current value is greater than prev + limit, call the process function with xs and indices as arguments, clear the xs and indices vectors, and update prev to the current value.
// 8. Add the current value and index to the xs and indices vectors, respectively, and update prev to the current value.
// 9. After the loop, call the process function with xs and indices as arguments to assign the remaining values to the ans vector.
// 10. Return the ans vector.
