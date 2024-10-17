// Leetcode 1046. Last Stone Weight

class Solution
{
public:
    int lastStoneWeight(vector<int> &stones)
    {
        priority_queue<int> pq;
        for (auto &x : stones)
        {
            pq.push(x);
        }

        while (pq.size() > 1)
        {
            int one = pq.top();
            pq.pop();
            int two = pq.top();
            pq.pop();
            if (one != two)
                pq.push(one - two);
        }

        return pq.size() == 0 ? 0 : pq.top();
    }
};

// Explaination

// We can use a max heap to store the stones.
// While the number of stones is > 1, we can pop the top two stones and push the difference back into the heap.
// Finally, we can return the top element of the heap if it exists, else return 0.
