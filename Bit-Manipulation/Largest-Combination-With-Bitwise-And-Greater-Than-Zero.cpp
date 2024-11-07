// Leetcode 2275. Largest Combination With Bitwise And Greater Than Zero

#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr);

class Solution
{
public:
    int largestCombination(vector<int> &A)
    {
        fast;
        int ans = 0, n = A.size();
        for (int i = 0; i < 32; ++i)
        {
            int cnt = 0;
            for (int num : A)
            {
                cnt += (num >> i & 1);
            }
            ans = max(ans, cnt);
        }
        return ans;
    }
};

// Explanation:
// We need to find the maximum number of elements that can be combined to form a number with bitwise AND greater than 0.
// We can do this by iterating over all the bits of the numbers in the array and counting the number of elements that have that bit set.
// The maximum number of elements that can be combined to form a number with bitwise AND greater than 0 is the maximum count of any bit.
// We can find this by iterating over all the bits and counting the number of elements that have that bit set.
// The maximum count of any bit is the answer.
