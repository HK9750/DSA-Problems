// Leetcode 3066. Minimum Operations to Exceed Threshold Value II

class Solution
{
public:
    int minOperations(vector<int> &nums, int k)
    {
        priority_queue<long, vector<long>, greater<>> pq;

        for (auto &num : nums)
        {
            pq.push(num);
        }

        int ans = 0;

        while (pq.top() < k)
        {
            long first = pq.top();
            pq.pop();
            long second = pq.top();
            pq.pop();
            long temp = min(first, second) * 2 + max(first, second);
            pq.push(temp);
            ans++;
        }

        return ans;
    }
};

// Explaination:

// We can use a priority queue to store the elements of the array. We will keep popping the top two elements of the priority queue and push the minimum of the two elements * 2 + maximum of the two elements back into the priority queue and increment the answer. We will keep doing this until the top element of the priority queue is greater than or equal to k. Finally, we will return the answer.