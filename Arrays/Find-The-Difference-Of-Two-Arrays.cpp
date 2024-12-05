// Leetcode 2215. Find The Difference Of Two Arrays

class Solution
{
public:
    vector<vector<int>> findDifference(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> ans1;
        vector<int> ans2;

        unordered_map<int, int> mp1;
        unordered_map<int, int> mp2;

        for (int x : nums1)
            mp1[x]++;
        for (int x : nums2)
            mp2[x]++;

        for (auto &x : mp1)
        {
            if (mp2.find(x.first) == mp2.end())
                ans1.push_back(x.first);
        }

        for (auto &x : mp2)
        {
            if (mp1.find(x.first) == mp1.end())
                ans2.push_back(x.first);
        }

        return {ans1, ans2};
    }
};

// Explaination

// We are given two arrays nums1 and nums2. We have to find the difference of two arrays.
// We can use the unordered_map to store the frequency of each element in both arrays.
// We will iterate over the first array and store the frequency of each element in the map mp1.
// We will iterate over the second array and store the frequency of each element in the map mp2.
// We will iterate over the map mp1 and check if the element is not present in the map mp2, then we will push that element into the ans1 vector.
// We will iterate over the map mp2 and check if the element is not present in the map mp1, then we will push that element into the ans2 vector.
// Finally, we will return the ans1 and ans2 vectors.
// The time complexity of this approach is O(N) where N is the size of the array.