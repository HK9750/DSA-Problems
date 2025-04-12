// Leetcode 2177. Find Three Consecutive Integers That Sum to a Given Number

class Solution
{
public:
    vector<long long> sumOfThree(long long num)
    {
        if (num % 3 != 0)
            return {};
        long long curr = num / 3;
        return {curr - 1, curr, curr + 1};
    }
};

// Explaination:

// 1. The function `sumOfThree` checks if the given number is divisible by 3.
// 2. If it is not divisible, it returns an empty vector.
// 3. If it is divisible, it calculates the three consecutive integers by dividing the number by 3 and adjusting accordingly.
// 4. The function returns a vector containing the three consecutive integers.