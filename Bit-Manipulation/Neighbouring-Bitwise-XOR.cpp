// Leetcode 2683. Neighbouring Bitwise XOR

class Solution
{
public:
    bool doesValidArrayExist(vector<int> &derived)
    {
        int ans = 0;
        for (auto &x : derived)
        {
            ans ^= x; // same results in 0 and different results in 1 (XOR)
        }
        return ans == 0;
    }
};

// Explanation:

// If the XOR of all elements of the derived array is 0, then it is possible to create the derived array from the original array.
// Because the XOR of all elements of the original array will be the same as the XOR of all elements of the derived array.