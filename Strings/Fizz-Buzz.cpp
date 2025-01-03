// Leetcode 412. Fizz Buzz

class Solution
{
public:
    vector<string> fizzBuzz(int n)
    {
        vector<string> ans(n);

        for (int i = 1; i <= n; i++)
        {
            if (i % 3 == 0 && i % 5 == 0)
                ans[i - 1] = "FizzBuzz";
            else if (i % 3 == 0)
                ans[i - 1] = "Fizz";
            else if (i % 5 == 0)
                ans[i - 1] = "Buzz";
            else
                ans[i - 1] = to_string(i);
        }

        return ans;
    }
};

// Explanation:

// We will iterate from 1 to n and check if the number is divisible by 3 and 5, 3, 5 or none of them.
// If the number is divisible by 3 and 5, we will add "FizzBuzz" to the answer vector.
// If the number is divisible by 3, we will add "Fizz" to the answer vector.
// If the number is divisible by 5, we will add "Buzz" to the answer vector.
// If the number is not divisible by 3 or 5, we will add the number as a string to the answer vector.
// Finally, we will return the answer vector.