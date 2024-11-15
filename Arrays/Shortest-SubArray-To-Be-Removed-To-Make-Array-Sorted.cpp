// Leetcode 1574: Shortest Subarray to be Removed to Make Array Sorted

class Solution
{
public:
    int findLengthOfShortestSubarray(vector<int> &arr)
    {
        int n = arr.size();
        int r = n - 1;

        while (r > 0 && arr[r - 1] <= arr[r])
        {
            r--;
        }
        if (r == 0)
            return 0;

        int ans = r;

        for (int i = 0; i < r; i++)
        {
            while (r < n && arr[i] > arr[r])
            {
                r++;
            }
            ans = min(ans, r - i - 1);
            if (i + 1 < n && arr[i] > arr[i + 1])
                break;
        }

        return ans;
    }
};

// Explaination:
// 1. Find the longest non-decreasing suffix of the array.
// 2. Find the shortest prefix of the array that needs to be removed to make the array sorted.
// 3. The answer is the minimum of the two lengths.
// 4. The answer is 0 if the array is already sorted.