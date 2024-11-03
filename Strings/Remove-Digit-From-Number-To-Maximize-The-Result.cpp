// Leetcode 2259. Remove One Digit from Number to Maximize the Result

class Solution
{
public:
    string removeDigit(string number, char digit)
    {
        int maxInd = -1;
        int n = number.length();

        for (int i = 0; i < n; ++i)
        {
            if (number[i] == digit)
            {
                maxInd = i;
                if (i < n - 1 && number[i + 1] > digit)
                {
                    break;
                }
            }
        }

        return number.substr(0, maxInd) + number.substr(maxInd + 1);
    }
};

// Explanation:
// We can iterate over the number string and find the first digit that is less than the next digit.
// We can remove this digit to maximize the result.
// If there are multiple such digits, we can remove the first one.
// We can return the number string after removing the digit.