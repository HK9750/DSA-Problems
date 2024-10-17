// Leetcode 215. Kth Largest Element in an Array

class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        priority_queue<int> pq;

        for (auto &x : nums)
            pq.push(x);

        for (int i = 0; i < k - 1; i++)
        {
            pq.pop();
        }

        return pq.top();
    }
};

// Explaination

// We can use a max heap to solve this problem. The heap stores the top k elements. Whenever the size is greater than k, delete the maximum element. Time complexity is O(nlog(k)). Space complexity is O(k) for storing the top k numbers.
