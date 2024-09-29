// leetcode 167. Two Sum II - Input array is sorted

class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        int i = 0;
        int j = numbers.size() - 1;

        while (i < j)
        {
            int temp = numbers[i] + numbers[j];
            if (temp > target)
            {
                j--;
            }
            else if (temp < target)
            {
                i++;
            }
            else
            {
                return {i + 1, j + 1};
            }
        }
        return {};
    }
};

// Explaination
// The idea is to use two pointers to find the two numbers that sum up to the target.
// Initialize two pointers, i and j, to the start and end of the array, respectively.
// While the left pointer is less than the right pointer, calculate the sum of the two numbers at the pointers.
// If the sum is greater than the target, move the right pointer to the left.
// If the sum is less than the target, move the left pointer to the right.
// If the sum is equal to the target, return the indices of the two numbers.
// If no such pair is found, return an empty vector.

// Solution 2

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> mp;

        for (int i = 0; i < nums.size(); i++)
        {
            int temp = target - nums[i];
            if (mp.find(temp) != mp.end())
            {
                return {mp[temp], i + 1};
            }
            mp[nums[i]] = i + 1;
        }

        return {};
    }
};

// Explaination
// The idea is to use a hash map to store the index of each element in the array.
// For each element in the array, calculate the second element required to get the target sum.
// If the second element is present in the hash map, return the index of the second element and the current index.
// If the second element is not present in the hash map, store the current element in the hash map.
// If no such pair is found, return an empty vector.
