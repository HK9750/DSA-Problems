// Leetcode 2551. Put Marbles in Bags

class Solution
{
public:
    long long putMarbles(vector<int> &weights, int k)
    {
        int n = weights.size();
        if (n <= 2)
            return 0;

        priority_queue<int> maxHeap;
        priority_queue<int, vector<int>, greater<int>> minHeap;
        long long maxP = 0, minP = 0;
        for (int i = 0; i < k - 1; i++)
        {
            int partition = weights[i] + weights[i + 1];
            maxP += partition;
            maxHeap.push(partition);
            minHeap.push(partition);
        }
        minP = maxP;

        for (int i = k - 1; i < n - 1; i++)
        {
            int partition = weights[i] + weights[i + 1];
            maxHeap.push(partition);
            minP += partition - maxHeap.top();
            maxHeap.pop();
            minHeap.push(partition);
            maxP += partition - minHeap.top();
            minHeap.pop();
        }
        return maxP - minP;
    }
};

// Explaination:

// The problem is asking us to find the maximum and minimum sum of weights of k-1 partitions of the array weights.
// We can do this by using two heaps: a max heap and a min heap.
// We can iterate through the array and for each partition, we can add the sum of the weights to both heaps.
// After that, we can pop the top element from both heaps to get the maximum and minimum sum of weights of k-1 partitions.
// Finally, we can return the difference between the maximum and minimum sum of weights of k-1 partitions.
// The time complexity of this solution is O(n log k), where n is the length of the array and k is the number of partitions.
// The space complexity is O(k) since we are using two heaps of size k to store the partitions.
// The space complexity can be reduced to O(1) if we only keep track of the maximum and minimum sum of weights of k-1 partitions.