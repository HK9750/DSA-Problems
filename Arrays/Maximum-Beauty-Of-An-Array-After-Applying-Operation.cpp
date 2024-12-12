// Leetcode 2779. Maximum Beauty of an Array After Applying Operations

class Solution
{
public:
    int maximumBeauty(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<pair<int, int>> v(n);

        for (int i = 0; i < n; i++)
        {
            v[i] = {nums[i] - k, nums[i] + k};
        }

        sort(v.begin(), v.end());

        int ans = 0;
        queue<int> q;
        for (pair<int, int> &pair : v)
        {
            while (!q.empty() && q.front() < pair.first)
            {
                q.pop();
            }
            q.push(pair.second);
            ans = max(ans, (int)q.size());
        }

        return ans;
    }
};

// Explanation:

// First we create a vector of pairs of integers. The first element of the pair is the minimum value of the range and the second element is the maximum value of the range. The minimum value of the range is the current element minus k and the maximum value of the range is the current element plus k.
// We sort the vector of pairs of integers.
// We create a queue of integers.
// We iterate through the vector of pairs of integers.
// We check if the queue is not empty and the front element of the queue is less than the first element of the current pair of integers. If it is true, we pop the front element of the queue.
// We push the second element of the current pair of integers into the queue.
// We update the answer by taking the maximum of the current answer and the size of the queue.
// Finally, we return the answer.

// Using technique of line sweep

class Solution
{
public:
    int maximumBeauty(vector<int> &nums, int k)
    {
        map<int, int> mp;

        for (auto &num : nums)
        {
            mp[num - k]++;
            mp[num + k + 1]--;
        }

        int ans = 0, sum = 0;

        for (auto &pairs : mp)
        {
            sum += pairs.second;
            ans = max(ans, sum);
        }

        return ans;
    }
};

// Explanation:
// We create a map of integers.
// We iterate through the vector of integers.
// For each element in the vector, we increment the value of the element minus k in the map and decrement the value of the element plus k plus 1 in the map.
// We create two variables ans and sum and initialize them to 0.
// We iterate through the map.
// For each pair in the map, we add the value of the pair to the sum.
// We update the answer by taking the maximum of the current answer and the sum.
// Finally, we return the answer.