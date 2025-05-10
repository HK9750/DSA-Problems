// Leetcode 2918. Minimum Equal Sum Of Two Arrays After Replacing Zeroes

class Solution
{
public:
    using ll = long long;
    long long minSum(vector<int> &nums1, vector<int> &nums2)
    {
        int n1 = nums1.size(), n2 = nums2.size();
        ll sum1 = 0, sum2 = 0;
        int c1 = 0, c2 = 0;

        for (int i = 0; i < n1; i++)
        {
            if (nums1[i] == 0)
                c1++;
            sum1 += nums1[i];
        }

        for (int i = 0; i < n2; i++)
        {
            if (nums2[i] == 0)
                c2++;
            sum2 += nums2[i];
        }

        if (c1 == 0 && c2 == 0)
        {
            return sum1 == sum2 ? sum1 : -1;
        }

        ll min1 = sum1 + c1;
        ll min2 = sum2 + c2;

        if (min1 > min2 && c2 == 0)
            return -1;
        if (min2 > min1 && c1 == 0)
            return -1;

        return max(min1, min2);
    }
};

// Explanation:

// 1. The function `minSum` takes two vectors of integers `nums1` and `nums2` as input.
// 2. It calculates the sum of elements in both vectors, while also counting the number of zeros in each vector.
// 3. If both vectors have no zeros, it checks if their sums are equal. If they are, it returns the sum; otherwise, it returns -1.
// 4. It calculates the minimum possible sum for both vectors by adding the count of zeros to their respective sums.
// 5. If one vector has a minimum sum greater than the other and the other vector has no zeros, it returns -1.
// 6. Finally, it returns the maximum of the two minimum sums.
// 7. The function uses long long integers to handle large sums and avoid overflow.
// 8. The time complexity is O(n1 + n2), where n1 and n2 are the sizes of the input vectors.
// 9. The space complexity is O(1) since it uses a constant amount of extra space.