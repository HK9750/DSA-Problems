// Leetcode 1780. Check if Number is a Sum of Powers of Three

class Solution
{
public:
    bool checkPowersOfThree(int n)
    {
        int p = 0;

        while (n > pow(3, p))
        {
            p++;
        }

        while (n > 0)
        {
            if (n >= pow(3, p))
            {
                n = n - pow(3, p);
            }
            if (n >= pow(3, p))
            {
                return false;
            }

            p--;
        }

        return true;
    }
};

// Explaination:

// First we find the maximum power of 3 that is less than n.
// Then we keep subtracting the maximum power of 3 from n until n becomes 0.
// If at any point n becomes less than the maximum power of 3, we return false.
// If n becomes 0, we return true.