// Leetcode 1383. Maximum Performance of a Team
// Similar to maximum subsequence score 2541. Maximum Performance of a Team
// I feel super proud that I solved this problem on my own in 20 minutes.

class Solution
{
public:
    const int mod = 1e9 + 7;
    int maxPerformance(int n, vector<int> &speed, vector<int> &efficiency, int k)
    {
        vector<pair<int, int>> v;
        for (int i = 0; i < speed.size(); i++)
        {
            v.emplace_back(efficiency[i], speed[i]);
        }

        sort(v.rbegin(), v.rend());

        priority_queue<int, vector<int>, greater<int>> minHeap;
        long long sumSpeed = 0, maxPerf = 0;

        for (const auto &[eff, spd] : v)
        {
            minHeap.push(spd);
            sumSpeed += spd;

            if (minHeap.size() > k)
            {
                sumSpeed -= minHeap.top();
                minHeap.pop();
            }

            maxPerf = max(maxPerf, sumSpeed * eff);
        }

        return maxPerf % mod;
    }
};

// Explaination

// First we make a vector of pairs of efficiency and speed.
// We sort the vector in descending order of efficiency.
// We make a priority queue of integers in ascending order.
// We iterate over the vector and push the second element of the pair to the priority queue and add it to the sum.
// If the size of the priority queue is greater than k, we subtract the top element from the sum as the top element is the smallest element and we need to find maximum k elements.
// If the index is greater than or equal to k-1, we find the maximum of the sum multiplied by the first element of the pair and the answer.
// Finally we return the answer.