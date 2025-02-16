// Leetcode 1718. Construct The Lexicographically Largest Valid Sequence

class Solution
{
public:
    vector<int> constructDistancedSequence(int n)
    {
        vector<int> result(2 * n - 1, 0);
        vector<bool> used(n + 1, false);
        backtrack(result, used, n, 0);
        return result;
    }

private:
    bool backtrack(vector<int> &result, vector<bool> &used, int n, int index)
    {
        while (index < result.size() && result[index] != 0)
        {
            index++;
        }
        if (index == result.size())
        {
            return true;
        }

        for (int i = n; i >= 1; i--)
        {
            if (used[i])
                continue;

            if (i == 1)
            {
                result[index] = 1;
                used[1] = true;
                if (backtrack(result, used, n, index + 1))
                    return true;
                result[index] = 0;
                used[1] = false;
            }
            else if (index + i < result.size() && result[index + i] == 0)
            {
                result[index] = i;
                result[index + i] = i;
                used[i] = true;
                if (backtrack(result, used, n, index + 1))
                    return true;
                result[index] = 0;
                result[index + i] = 0;
                used[i] = false;
            }
        }
        return false;
    }
};

// Explaination:

// We are using backtracking to solve this problem. We are checking if the index is equal to the size of the result array. If it is, we return true.
// We are using a while loop to find the next empty index in the result array.
// We are using a for loop to iterate through the numbers from n to 1.
// We are checking if the number is already used. If it is, we continue to the next number.
// We are checking if the number is 1. If it is, we set the result at the current index to 1 and call the helper function recursively with the updated index.
// We are setting the result at the current index and the index + i to i and calling the helper function recursively with the updated index.
// We are returning true if the partition is valid.
// We are setting the result at the current index and the index + i to 0 and calling the helper function recursively with the updated index.
// We are returning false if the partition is not valid.
// We are returning the result array as the lexicographically largest valid sequence.
// Time Complexity: O(2^n)