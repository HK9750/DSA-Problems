// Leetcode 2302. Count Subarrays With Score Less Than K

class Solution
{
public:
    using ll = long long;
    long long countSubarrays(vector<int> &nums, long long k)
    {
        int n = nums.size();
        ll ans = 0;
        ll sum = 0;

        int j = 0, i = 0;

        while (j < n)
        {
            sum += nums[j];
            while (i <= j && sum * (j - i + 1) >= k)
            {
                sum -= nums[i];
                i++;
            }
            ans += (j - i + 1);
            j++;
        }

        return ans;
    }
};

// Explaination:

// 1. We initialize two pointers, i and j, to the start of the array.
// 2. We also initialize a variable sum to keep track of the sum of the elements between the two pointers and a variable ans to count the number of valid subarrays.
// 3. We iterate through the array using the j pointer, adding the current element to the sum.
// 4. If the sum multiplied by the length of the subarray (j - i + 1) is greater than or equal to k, we move the i pointer to the right and subtract the corresponding element from the sum until the condition is satisfied.
// 5. We then add the number of valid subarrays ending at j to the ans variable (i.e., (j - i + 1)).
// 6. Finally, we return the total count of valid subarrays (ans).
// 7. The time complexity is O(n) since we are iterating through the array once.
// 8. The space complexity is O(1) since we are using a constant amount of extra space.