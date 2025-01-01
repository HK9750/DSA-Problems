// Leetcode 1422. Maximum Score After Spliting A String

class Solution
{
public:
    int maxScore(string s)
    {
        int n = s.size();
        vector<int> p(n + 1, 0);

        for (int i = 0; i < n; i++)
        {
            p[i + 1] = p[i] + (s[i] == '1');
        }

        int ans = 0;
        int zeroCount = 0;

        for (int i = 0; i < n - 1; i++)
        {
            if (s[i] == '0')
                zeroCount++;
            ans = max(ans, zeroCount + (p[n] - p[i + 1]));
        }

        return ans;
    }
};

// Explaination:

// We will maintain a prefix sum array p where p[i] will store the count of 1's in the string s from 0 to i.
// We will iterate over the string and update the prefix sum array.
// We will iterate over the string and for each character, we will check if it is 0.
// If it is 0, we will increment the zeroCount.
// We will update the answer with the maximum of the zeroCount and the count of 1's from i+1 to n.
// Finally, we will return the answer.