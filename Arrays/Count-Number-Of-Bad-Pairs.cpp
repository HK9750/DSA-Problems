// Leetcode 2364. Count Number of Bad Pairs

class Solution
{
public:
    long long countBadPairs(vector<int> &nums)
    {
        long long n = nums.size();
        long long totalPairs = (n * (n - 1)) / 2;

        unordered_map<int, long long> freq;
        long long goodPairs = 0;

        for (int i = 0; i < n; i++)
        {
            int key = nums[i] - i;
            goodPairs += freq[key];
            freq[key]++;
        }

        return totalPairs - goodPairs;
    }
};

// Explaination:

// Let's say we have an array of size n. We need to find the number of bad pairs in the array. A bad pair is defined as a pair of indices (i, j) such that i < j and nums[i] > nums[j].
// We can find the number of good pairs in the array and then subtract it from the total number of pairs to get the number of bad pairs.
// A good pair is defined as a pair of indices (i, j) such that i < j and nums[i] <= nums[j].
// To find the number of good pairs, we can iterate over the array and for each element nums[i], we can find the number of elements to the left of it that are less than or equal to nums[i]. This can be done by maintaining a frequency map of the difference between the element and its index.
// Let's say the difference between the element and its index is key = nums[i] - i. We can find the number of elements to the left of nums[i] that are less than or equal to nums[i] by looking up the frequency of key in the map.
// We can then increment the frequency of key in the map to account for the current element.
// The total number of good pairs in the array is the sum of the number of good pairs for each element.
// The total number of pairs in the array is n * (n - 1) / 2, where n is the size of the array.
// The number of bad pairs in the array is the total number of pairs minus the number of good pairs.
// We can return the number of bad pairs as the result.
// The time complexity of this approach is O(n), where n is the size of the array, as we iterate over the array only once. The space complexity is also O(n) due to the frequency map.