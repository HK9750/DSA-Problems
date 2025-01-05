// Leetcode 2381. Shifting Letters II

class Solution
{
public:
    string shiftingLetters(string s, vector<vector<int>> &Q)
    {
        int n = s.size();
        vector<int> A(n, 0);
        for (auto &it : Q)
        {
            int l = it[0];
            int r = it[1];
            int t = it[2];
            if (t == 1)
            {
                A[l] += 1;
                if (r + 1 < n)
                {
                    A[r + 1] -= 1;
                }
            }
            else
            {
                A[l] -= 1;
                if (r + 1 < n)
                {
                    A[r + 1] += 1;
                }
            }
        }
        for (int i = 1; i < n; ++i)
        {
            A[i] += A[i - 1];
        }
        for (int i = 0; i < n; ++i)
        {
            int shift = (A[i] % 26 + 26) % 26;
            int ch = s[i] - 'a';
            ch = (ch + shift) % 26;
            s[i] = 'a' + ch;
        }
        return s;
    }
};

// Explaination:

// We start by creating an array A of size n, initialized with 0. We iterate over the queries and update the array A as follows:
// If the query is of type 1, we increment A[l] by 1 and decrement A[r + 1] by 1.
// If the query is of type 2, we decrement A[l] by 1 and increment A[r + 1] by 1.
// After processing all the queries, we calculate the prefix sum of the array A.
// Finally, we iterate over the string s and shift the ith character by A[i] positions to the right. We take care of the negative values by adding 26 to the shift value and taking the modulo 26.
// The time complexity of this approach is O(n + q), where n is the size of the string s and q is the number of queries. The space complexity is O(n) to store the array A.
