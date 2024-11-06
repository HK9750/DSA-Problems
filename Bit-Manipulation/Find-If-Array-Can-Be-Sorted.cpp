// Leetcode 3011. Find If Array Can Be Sorted

class Solution
{
public:
    bool canSortArray(vector<int> &nums)
    {
        // Number of set bits of the elements in the current segment
        int numOfSetBits = __builtin_popcount(nums[0]);
        int maxOfSegment = nums[0];
        int minOfSegment = nums[0];

        // Initialize max of the previous segment to the smallest possible
        // integer
        int maxOfPrevSegment = INT_MIN;

        for (int i = 1; i < nums.size(); i++)
        {
            if (__builtin_popcount(nums[i]) == numOfSetBits)
            {
                // Element belongs to the same segment
                // Update min and max values of the segment
                maxOfSegment = max(maxOfSegment, nums[i]);
                minOfSegment = min(minOfSegment, nums[i]);
            }
            else
            { // Element belongs to a new segment
                // Check if the segments are arranged properly
                if (minOfSegment < maxOfPrevSegment)
                {
                    return false;
                }

                // Update the previous segment's max
                maxOfPrevSegment = maxOfSegment;

                // Start a new segment with the current element
                maxOfSegment = nums[i];
                minOfSegment = nums[i];
                numOfSetBits = __builtin_popcount(nums[i]);
            }
        }
        // Final check for proper segment arrangement
        if (minOfSegment < maxOfPrevSegment)
        {
            return false;
        }
        return true;
    }
};

// Explanation:

// The problem can be solved by iterating over the array and checking if the current element belongs to the same segment as the previous element or not. If the current element belongs to the same segment, we update the min and max values of the segment. If the current element belongs to a new segment, we check if the previous segment is arranged properly (i.e., the min value of the current segment is greater than or equal to the max value of the previous segment). If not, we return false. We then update the max value of the previous segment and start a new segment with the current element.