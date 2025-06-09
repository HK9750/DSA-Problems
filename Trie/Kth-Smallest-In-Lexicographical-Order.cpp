// Leetcode 440. Kth Smallest in Lexicographical Order

class Solution
{
public:
    int findKthNumber(int n, int k)
    {
        long long ans = 1;
        k--;
        while (k > 0)
        {
            long long steps = calculateSteps(n, ans, ans + 1);
            if (steps <= k)
            {
                ans += 1;
                k -= steps;
            }
            else
            {
                ans *= 10;
                k--;
            }
        }

        return ans;
    }

private:
    long long calculateSteps(int n, long long curr, long long next)
    {
        long long steps = 0;
        while (curr <= n)
        {
            steps += min((long long)n + 1, next) - curr;
            curr *= 10;
            next *= 10;
        }
        return steps;
    }
};

// Explanation:

// 1. The function `findKthNumber` takes two parameters: `n`, the upper limit, and `k`, the position of the number we want to find in lexicographical order.
// 2. We initialize `ans` to 1 and decrement `k` by 1 because we want to find the k-th smallest number starting from 0.
// 3. We enter a loop that continues until `k` becomes 0.
// 4. Inside the loop, we calculate the number of steps from the current number `ans` to the next number `ans + 1` using the helper function `calculateSteps`.
// 5. If the number of steps is less than or equal to `k`, it means the k-th number is in the next range, so we increment `ans` by 1 and reduce `k` by the number of steps.
// 6. If the number of steps is greater than `k`, it means the k-th number is in the current range, so we multiply `ans` by 10 to go deeper into the lexicographical order and decrement `k` by 1.
// 7. The helper function `calculateSteps` calculates the number of steps from the current number `curr` to the next number `next` within the limit `n`.
// 8. It does this by counting how many numbers can be formed starting from `curr` and going deeper into the lexicographical order until it exceeds `n`.
// 9. Finally, when the loop ends, we return `ans`, which is the k-th smallest number in lexicographical order up to `n`.
// Time Complexity: O(log n * log n), where log n is the number of digits in n.
// Space Complexity: O(1), as we are using a constant amount of space for variables.