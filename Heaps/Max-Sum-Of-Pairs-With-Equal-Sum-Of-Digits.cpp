// Leetcode 2342. Max Sum of a Pair with Equal Sum of Digits

class Solution
{
public:
    int maximumSum(vector<int> &nums)
    {
        int n = nums.size();
        unordered_map<int, pair<int, int>> mp;
        priority_queue<int> pq;

        for (int i = 0; i < n; i++)
        {
            int temp = nums[i], sum = 0;
            while (temp)
            {
                sum += temp % 10;
                temp /= 10;
            }

            if (mp.find(sum) != mp.end())
            {
                pq.push(nums[i] + mp[sum].first);
                if (nums[i] > mp[sum].first)
                {
                    mp[sum] = {nums[i], i};
                }
            }
            else
            {
                mp[sum] = {nums[i], i};
            }
        }

        return pq.empty() ? -1 : pq.top();
    }
};

// Explaination:

// We will iterate over the array and for each element we will calculate the sum of digits of that element.
// We will store the sum of digits and the maximum element with that sum in a map.
// If we find a sum of digits which is already present in the map, we will calculate the sum of the current element and the maximum element with that sum and push it into a max heap.
// We will return the top element of the max heap if it is not empty, else we will return -1.
// Time Complexity: O(nlogn)