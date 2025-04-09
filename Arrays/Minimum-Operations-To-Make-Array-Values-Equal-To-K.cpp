// Leetcode 3375. Minimum Operations to Make All Array Elements Equal to K

class Solution
{
public:
    int minOperations(vector<int> &nums, int k)
    {
        int mini = *min_element(nums.begin(), nums.end());
        if (mini < k)
            return -1;

        unordered_set<int> s;

        for (auto &x : nums)
        {
            if (x > k)
                s.insert(x);
        }

        return s.size();
    }
};

// Explaination:

// 1. We first find the minimum element in the array. If it is less than k, we return -1 as it is not possible to make all elements equal to k.
// 2. We create an unordered set to store the elements that are greater than k. This is because we can only make operations on elements that are greater than k.
// 3. We iterate through the array and insert the elements that are greater than k into the set. The size of the set will give us the number of unique elements that are greater than k, which is the minimum number of operations required to make all elements equal to k.
// 4. Finally, we return the size of the set as the result.
// 5. The time complexity of this solution is O(n), where n is the size of the input array, as we are iterating through the array once to find the minimum element and once to insert elements into the set. The space complexity is O(n) in the worst case, where all elements are greater than k and are stored in the set.
// 6. This solution is efficient and works well for large input sizes, as it only requires a single pass through the array and uses a set to store unique elements.