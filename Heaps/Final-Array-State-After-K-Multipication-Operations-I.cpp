// Leetcode 3264. Final Array State After K Multiplication Operations I

class Solution
{
public:
    vector<int> getFinalState(vector<int> &nums, int k, int multiplier)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (int i = 0; i < nums.size(); i++)
        {
            pq.push(make_pair(nums[i], i));
        }

        for (int i = 0; i < k; i++)
        {
            auto [minVal, minIndex] = pq.top();
            pq.pop();
            minVal = minVal * multiplier;
            pq.push(make_pair(minVal, minIndex));
        }
        vector<int> res(nums.size());
        while (!pq.empty())
        {
            auto pair = pq.top();
            res[pair.second] = pair.first;
            pq.pop();
        }
        return res;
    }
};

// Explanation:
// We are given an array of integers. We have to perform k multiplication operations on the array. In each operation, we have to multiply the minimum element of the array by a given multiplier. We have to return the final state of the array after performing k operations.
// We can solve this problem using a priority queue. We will store the elements of the array along with their indices in the priority queue. We will then pop the minimum element from the priority queue, multiply it by the given multiplier, and push it back into the priority queue. We will repeat this process k times. Finally, we will store the elements of the priority queue in the result array based on their indices and return the result array.
