// Leetcode 2962. Count Subarrays Where Max Element Appears at Least K Times

class Solution
{
public:
    using ll = long long;
    long long countSubarrays(vector<int> &nums, int k)
    {
        int n = nums.size();
        int maxi = *max_element(nums.begin(), nums.end());
        ll ans = 0;
        int i = 0, count = 0;

        for (int j = 0; j < n; ++j)
        {
            if (nums[j] == maxi)
                count++;
            while (count >= k)
            {
                ans += (n - j);
                if (nums[i] == maxi)
                    count--;
                i++;
            }
        }

        return ans;
    }
};

// Explaination:

// 1. We are given an array of integers and we need to count the number of subarrays where the maximum element appears at least k times.
// 2. We first find the maximum element in the array using the `max_element` function from the STL.
// 3. We initialize a variable `ans` to store the count of valid subarrays, and two pointers `i` and `j` to represent the start and end of the current subarray respectively.
// 4. We also initialize a variable `count` to keep track of the number of times the maximum element appears in the current subarray.
// 5. We iterate through the array using the `j` pointer, and for each element, we check if it is equal to the maximum element. If it is, we increment the `count` variable.
// 6. If the `count` variable is greater than or equal to `k`, we know that we have found a valid subarray. We then add the number of valid subarrays that can be formed with the current `j` pointer to the `ans` variable. The number of valid subarrays is equal to the number of elements remaining in the array after the `j` pointer, which is `n - j`.
// 7. We then move the `i` pointer to the right until the `count` variable is less than `k`, decrementing the `count` variable if we encounter the maximum element at the `i` pointer.
// 8. Finally, we return the `ans` variable which contains the count of valid subarrays.