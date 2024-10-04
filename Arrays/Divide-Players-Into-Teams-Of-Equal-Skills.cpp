// Leetcode 2491. Divide Players Into Teams Of Equal Skills

// We can also use two pointers to solve this problem.
class Solution
{
public:
    long long dividePlayers(vector<int> &arr)
    {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        long long ans = 0;
        int target = arr[0] + arr[n - 1];
        int r = n - 1, l = 0;
        for (int i = 0; i < n / 2; i++)
        {
            if (arr[i] + arr[n - i - 1] != target)
                return -1;
            else
                ans += arr[i] * arr[n - i - 1];
        }
        return ans;
    }
};

// Explanation:
// We will sort the array.
// We will calculate the target sum by taking the sum of the first and last element of the array.
// We will keep two pointers, one at the start and one at the end.
// We will iterate over the first half of the array.
// If the sum of the elements at the two pointers is not equal to the target sum, we will return -1.
// Otherwise, we will update the answer by multiplying the two elements.
// We will return the answer.