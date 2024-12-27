// Leetcode 1014. Best Sight Seeing Pair

class Solution
{
public:
    int maxScoreSightseeingPair(vector<int> &values)
    {
        int n = values.size();
        vector<int> left(n);
        left[0] = values[0];
        int ans = 0;

        for (int i = 1; i < n; i++)
        {
            int curr = values[i] - i;
            ans = max(ans, left[i - 1] + curr);
            int right = values[i] + i;
            left[i] = max(left[i - 1], right);
        }

        return ans;
    }
};

// The problem states that we maximize (values[i] + i) + (values[j] - j) in which i < j.
// So we keep count of maximum suffix array left which stores that maximum value of values[i] + i upto i-1 index.
// Then we calculate the current value of values[i] - i and add it to the left[i-1] and store it in ans.
// So in a greedy way we calculate the answer and in the end return it.
