// Leetcode 1769. Minimum Number of Operations to Move All Balls to Each Box

class Solution
{
public:
    vector<int> minOperations(string boxes)
    {
        int n = boxes.size();
        vector<int> left(n, 0), right(n, 0), res(n, 0);
        int count = (boxes.at(0) == '1' ? 1 : 0);

        for (int i = 1; i < n; i++)
        {
            left[i] = left[i - 1] + count;
            count += (boxes.at(i) == '1' ? 1 : 0);
        }

        count = (boxes.at(n - 1) == '1' ? 1 : 0);

        for (int i = n - 2; i >= 0; i--)
        {
            right[i] = right[i + 1] + count;
            count += (boxes.at(i) == '1' ? 1 : 0);
        }

        for (int i = 0; i < n; i++)
        {
            res[i] = left[i] + right[i];
        }

        return res;
    }
};

// Explaination:

// 1. Create a vector left and right of size n, and a vector res of size n.
// 2. Create a variable count and initialize it to 0.
// 3. Traverse the boxes from left to right and calculate the left vector.
// 4. Traverse the boxes from right to left and calculate the right vector.
// 5. Traverse the boxes and calculate the res vector.
// 6. Return the res vector.
