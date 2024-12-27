// Leetcode 1014. Best Sight Seeing Pair

class Solution
{
public:
    int maxScoresSightseeingPair(vector<int> &values)
    {
        int n = values.size();
        vector<int> left(n);
        left[0] = values[0] + 0;
        int ans = 0;

        for (int i = 1; i < n; i++)
        {
            int currLeft = values[i] + i;
            left[i] = max(left[i - 1], curr);
            int currRight = values[i] - i;
            ans = max(ans, currLeft + currRight);
        }

        return ans;
    }
}

// The problem states that we maximize (values[i] + i) + (values[j] - j) in which i < j.
// So we keep count of maximum suffix array left which stores that maximum value of values[i] + i upto i-1 index.
// Then in each iteration we calculate currLeft to update the maximum of that index and currRight to calculate the maximum answer.
// So in a greedy way we calculate the answer and in the end return it.
