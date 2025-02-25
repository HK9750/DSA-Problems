// Leetcode 1524. Number of Sub-arrays With Odd Sum

class Solution
{
public:
    const int mod = 1e9 + 7;
    int numOfSubarrays(vector<int> &arr)
    {
        long long oddCount = 0, prefixSum = 0;
        for (int a : arr)
        {
            prefixSum += a;
            oddCount += prefixSum % 2;
        }
        oddCount += (arr.size() - oddCount) * oddCount;
        return oddCount % mod;
    }
};

// Explaination:

// Let's say we have an array of size n. We can have n * (n + 1) / 2 subarrays in total.
// Let's say we have a subarray from index i to j. The sum of this subarray will be prefixSum[j] - prefixSum[i - 1].
// If the sum of the subarray is odd, then prefixSum[j] and prefixSum[i - 1] should have different parity.
// So, we can count the number of odd prefix sums and even prefix sums.
// Let's say we have x odd prefix sums and y even prefix sums.
// The number of subarrays with odd sum will be x * y.
// The number of subarrays with even sum will be x * (x - 1) / 2 + y * (y - 1) / 2 + x + y.
// So, the total number of subarrays with odd sum will be x * y.
// We can calculate the number of subarrays with odd sum by calculating the number of odd prefix sums and even prefix sums.
// We can calculate the number of odd prefix sums by iterating over the array and keeping track of the prefix sum and the number of odd prefix sums.
// The number of even prefix sums will be n - the number of odd prefix sums.
// The number of subarrays with odd sum will be the number of odd prefix sums * the number of even prefix sums.
// We can return the result modulo 1e9 + 7.
