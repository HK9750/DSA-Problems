// Leetcode 862: Shortest Subarray with Sum at Least K

class Solution
{
public:
    int shortestSubarray(vector<int> &A, int K)
    {
        int N = A.size(), ans = INT_MAX;
        vector<long> P(N + 1);
        for (int i = 0; i < N; ++i)
            P[i + 1] = P[i] + A[i];
        deque<int> q;
        for (int y = 0; y < P.size(); ++y)
        {
            while (q.size() && P[y] <= P[q.back()])
                q.pop_back();
            while (q.size() && P[y] >= P[q.front()] + K)
            {
                ans = min(ans, y - q.front());
                q.pop_front();
            }
            q.push_back(y);
        }
        return ans == INT_MAX ? -1 : ans;
    }
};

// Explaination

// The idea is to use a deque to store the indices of the prefix sum.
// We iterate over the array and calculate the prefix sum at each index.
// We then check if the prefix sum at the current index is less than the prefix sum at the index stored at the back of the deque. If it is, we pop the back of the deque.
// We then check if the prefix sum at the current index is greater than or equal to the prefix sum at the index stored at the front of the deque plus K. If it is, we update the answer and pop the front of the deque.
// Finally, we push the current index into the deque.
// Finally, we return the answer. If the answer is still INT_MAX, we return -1.
