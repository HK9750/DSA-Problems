// Leetcode 3513. Number of Unique XOR Triplets I

class Solution
{
public:
    int uniqueXorTriplets(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return 1;
        if (n == 2)
            return 2;
        int msb = 31 - __builtin_clz(n);
        return 1 << (msb + 1);
    }
};

// Explaination:

// 1. The function `uniqueXorTriplets` calculates the number of unique XOR triplets in the given vector `nums`.
// 2. It first checks the size of the vector `nums` and returns 1 if it has only one element and 2 if it has two elements.
// 3. It calculates the most significant bit (MSB) of the size of the vector using `__builtin_clz` and stores it in the variable `msb`.
// 4. Finally, it returns `1 << (msb + 1)`, which is equivalent to `2^(msb + 1)`, representing the number of unique XOR triplets possible with the given size of the vector.
