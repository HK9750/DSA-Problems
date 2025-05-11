// Leetcode 1550. Three Consecutive Odds

class Solution
{
public:
    bool threeConsecutiveOdds(vector<int> &arr)
    {
        int count = 0;

        for (int n : arr)
        {
            if (n % 2 == 1)
                count++;
            if (n % 2 == 0)
                count = 0;
            if (count == 3)
                return true;
        }

        return false;
    }
};

// Explanation:

// 1. The function `threeConsecutiveOdds` takes a vector of integers `arr` as input.
// 2. It initializes a variable `count` to keep track of the number of consecutive odd numbers.
// 3. It iterates through each element `n` in the vector `arr`.
// 4. If `n` is odd (i.e., `n % 2 == 1`), it increments the `count`.
// 5. If `n` is even (i.e., `n % 2 == 0`), it resets the `count` to 0.
// 6. If `count` reaches 3, it means there are three consecutive odd numbers, and the function returns `true`.
// 7. If the loop completes without finding three consecutive odd numbers, the function returns `false`.
// 8. The time complexity is O(n), where n is the size of the input vector.
// 9. The space complexity is O(1) since it uses a constant amount of extra space.