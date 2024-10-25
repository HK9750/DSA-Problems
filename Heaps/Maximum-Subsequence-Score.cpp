// Leetcode 2541. Maximum Subsequence Score

class Solution
{
public:
    long long maxScore(vector<int> &nums1, vector<int> &nums2, int k)
    {
        long long ans = INT_MIN;
        vector<pair<int, int>> v;
        for (int i = 0; i < nums1.size(); i++)
        {
            v.emplace_back(make_pair(nums1[i], nums2[i]));
        }
        sort(v.begin(), v.end(),
             [](auto &a, auto &b)
             { return a.second > b.second; });

        priority_queue<int, vector<int>, greater<int>> pq;
        long long sum = 0;
        for (int i = 0; i < v.size(); i++)
        {
            auto &[a, b] = v[i];
            pq.push(a);
            sum += a;
            if (pq.size() > k)
            {
                sum -= pq.top();
                pq.pop();
            }
            if (i >= k - 1)
            {
                ans = max(ans, sum * b);
                cout << ans;
            }
        }
        return ans;
    }
};

// Explaination

// First we make a vector of pairs of nums1 and nums2.
// We sort the vector in descending order of nums2.
// We make a priority queue of integers in ascending order.
// We iterate over the vector and push the first element of the pair to the priority queue and add it to the sum.
// If the size of the priority queue is greater than k, we subtract the top element from the sum as the top element is the smallest element and we need to find maximum k elements.
// If the index is greater than or equal to k-1, we find the maximum of the sum multiplied by the second element of the pair and the answer.
// Finally we return the answer.
// Time Complexity: O(nlogn)