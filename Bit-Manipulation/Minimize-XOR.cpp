// Leetcode 2429. Minimize XOR

class Solution
{
public:
    int minimizeXor(unsigned num1, unsigned num2)
    {
        int B = popcount(num2), A = popcount(num1);
        bitset<31> y = num1, x = 0;
        if (A > B)
        {
            for (int b = 30; B >= 1 && b >= 0; b--)
            {
                if (y[b])
                {
                    x[b] = 1;
                    B--;
                }
            }
            return x.to_ulong();
        }
        else
        {
            B -= A;
            for (int b = 0; B >= 1 && b < 31; b++)
            {
                if (y[b] == 0)
                {
                    y[b] = 1;
                    B--;
                }
            }
            return y.to_ulong();
        }
    }
};

// Explanation:

// Let's say we have two numbers num1 and num2. We need to minimize the XOR of these two numbers. We can do this by setting the bits of num1 to 0 and num2 to 1. We can do this by counting the number of bits in num1 and num2. If the number of bits in num1 is greater than the number of bits in num2, then we can set the bits of num1 to 0 and num2 to 1. If the number of bits in num2 is greater than the number of bits in num1, then we can set the bits of num2 to 0 and num1 to 1. We can do this by using the popcount function to count the number of bits in num1 and num2. We can then set the bits of num1 to 0 and num2 to 1 by using the bitset function. We can then return the XOR of num1 and num2. This will give us the minimum XOR of num1 and num2.