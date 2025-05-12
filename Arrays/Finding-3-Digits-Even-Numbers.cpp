// Leetcode 2094. Finding 3-Digit Even Numbers

class Solution
{
public:
    vector<int> findEvenNumbers(vector<int> &digits)
    {
        vector<int> mpp(10, 0);
        for (int i = 0; i < digits.size(); i++)
            mpp[digits[i]]++;

        vector<int> res;
        for (int i = 1; i <= 9; i++)
        {
            if (mpp[i] == 0)
                continue;
            mpp[i]--;

            for (int j = 0; j <= 9; j++)
            {
                if (mpp[j] == 0)
                    continue;
                mpp[j]--;
                for (int k = 0; k <= 8; k += 2)
                {
                    if (mpp[k] == 0)
                        continue;
                    res.push_back(i * 100 + j * 10 + k);
                }
                mpp[j]++;
            }
            mpp[i]++;
        }
        return res;
    }
};

// Explanation:

// 1. The function `findEvenNumbers` takes a vector of integers `digits` as input.
// 2. It initializes a vector `mpp` of size 10 to count the occurrences of each digit (0-9).
// 3. It iterates through the `digits` vector and increments the corresponding index in `mpp`.
// 4. It initializes an empty vector `res` to store the resulting 3-digit even numbers.
// 5. It iterates through the digits from 1 to 9 (to ensure the first digit is not zero).
// 6. If the count of the digit is zero, it continues to the next iteration.
// 7. It decrements the count of the first digit in `mpp`.
// 8. It then iterates through the digits from 0 to 9 for the second digit.
// 9. If the count of the second digit is zero, it continues to the next iteration.
// 10. It decrements the count of the second digit in `mpp`.
// 11. It then iterates through the even digits (0, 2, 4, 6, 8) for the third digit.
// 12. If the count of the third digit is zero, it continues to the next iteration.
// 13. It adds the 3-digit even number formed by the first, second, and third digits to the `res` vector.
// 14. It increments the count of the third digit in `mpp`.
// 15. After processing all combinations, it increments the count of the second digit in `mpp`.
// 16. Finally, it returns the `res` vector containing all the valid 3-digit even numbers.
