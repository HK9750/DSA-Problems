// Leetcode 2425. Bitwise XOR of All Pairs

class Solution
{
public:
    int xorAllNums(vector<int> &nums1, vector<int> &nums2)
    {
        int result = 0;

        if (nums2.size() % 2 != 0)
        {
            for (int x : nums1)
                result ^= x;
        }

        if (nums1.size() % 2 != 0)
        {
            for (int y : nums2)
                result ^= y;
        }

        return result;
    }
};

// Explanation:

// If the size of both arrays is even, then the XOR of all elements of both arrays will be 0.
// If the size of any array is odd, then the XOR of all elements of that array will be the result.
// If the size of both arrays is odd, then the XOR of all elements of both arrays will be the result.