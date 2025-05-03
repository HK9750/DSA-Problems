// Leetcode 1007. Minimum Domino Rotations For Equal Row

class Solution
{
public:
    int find(vector<int> &tops, vector<int> &bottoms, int val)
    {
        int n = tops.size();

        int swapTop = 0;
        int swapBottom = 0;

        for (int i = 0; i < n; i++)
        {
            if (tops[i] != val && bottoms[i] != val)
            {
                return -1;
            }
            else if (tops[i] != val)
            {
                swapTop++;
            }
            else if (bottoms[i] != val)
            {
                swapBottom++;
            }
        }

        return min(swapTop, swapBottom);
    }

    int minDominoRotations(vector<int> &tops, vector<int> &bottoms)
    {
        int result = INT_MAX;

        for (int val = 1; val <= 6; val++)
        {
            int swaps = find(tops, bottoms, val);

            if (swaps != -1)
            {
                result = min(result, swaps);
            }
        }

        return result == INT_MAX ? -1 : result;
    }
};

// Explaination:

// 1. We need to find the minimum number of rotations to make all the values in the row equal.
// 2. We can only rotate the dominoes, not flip them. So, we need to check for each value from 1 to 6 (the possible values on the dominoes) how many rotations are needed to make all the values equal to that value.
// 3. We can do this by iterating through the tops and bottoms arrays and counting how many swaps are needed for each value.
// 4. If we find a value that cannot be made equal (i.e., both tops and bottoms have different values), we return -1.
// 5. Finally, we return the minimum number of swaps needed for any value from 1 to 6. If no value can be made equal, we return -1.
// 6. The time complexity of this solution is O(n), where n is the number of dominoes, as we are iterating through the tops and bottoms arrays for each value from 1 to 6.
// 7. The space complexity is O(1) as we are using a constant amount of extra space.