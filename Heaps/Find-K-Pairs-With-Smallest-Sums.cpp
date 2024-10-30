// Leetcode 373. Find K Pairs with Smallest Sums

class Solution
{
public:
    vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k)
    {
        if (nums1.empty() || nums2.empty() || k == 0)
            return {};

        auto comp = [&](const pair<int, int> &a, const pair<int, int> &b)
        {
            return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second];
        };

        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> pq(comp);

        for (int i = 0; i < min((int)nums1.size(), k); ++i)
        {
            pq.emplace(i, 0);
        }

        vector<vector<int>> result;
        while (!pq.empty() && k-- > 0)
        {
            auto [i, j] = pq.top();
            pq.pop();
            result.push_back({nums1[i], nums2[j]});

            if (j + 1 < nums2.size())
            {
                pq.emplace(i, j + 1);
            }
        }

        return result;
    }
};

// Edge Case Check: If either nums1 or nums2 is empty, or k is 0, return an empty result since there are no pairs to find.

// Comparator Function: Defines a lambda function comp to sort pairs (i, j) based on the sum nums1[i] + nums2[j] in ascending order. This allows the priority queue to store the smallest sums at the top.

// Priority Queue Initialization:

// A min-heap pq is created, using comp as the comparator.
// Only the first k pairs (i, 0) (where i is from nums1 and 0 is the first index of nums2) are initially added to limit memory usage.
// Result Vector: result is initialized to store the k smallest pairs.

// Main Loop:

// While pq is not empty and k pairs are yet to be selected:
// Extract the top pair (i, j) from pq, representing the smallest available sum.
// Append the pair {nums1[i], nums2[j]} to result.
// Next Pair Insertion:

// If there’s a next element in nums2 for the same i (i.e., j + 1 is within bounds), push (i, j + 1) to pq.
// This ensures we explore pairs incrementally from each nums1[i] with increasing elements in nums2.
// Return Result: Once k pairs are selected or pq is exhausted, result is returned with the k smallest pairs