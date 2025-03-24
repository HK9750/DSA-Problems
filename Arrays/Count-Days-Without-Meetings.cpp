// Leetcode 3169. Count Days Without Meetings

class Solution
{
public:
    int countDays(int days, vector<vector<int>> &meetings)
    {
        sort(meetings.begin(), meetings.end());

        vector<vector<int>> merged;
        int idx = -1;

        for (int i = 0; i < meetings.size(); i++)
        {
            if (idx == -1 || merged[idx][1] < meetings[i][0])
            {
                merged.push_back(meetings[i]);
                idx++;
            }
            else
            {
                merged[idx][1] = max(merged[idx][1], meetings[i][1]);
            }
        }

        int occupied = 0;
        for (int i = 0; i <= idx; i++)
        {
            occupied += (merged[i][1] - merged[i][0] + 1);
        }

        return days - occupied;
    }
};

// Explanation:

// Sort the meetings based on the start time.
// Merge the overlapping meetings.
// For merging, if the current meeting's start time is greater than the previous meeting's end time, then push the current meeting into the merged array.
// Otherwise, update the end time of the previous meeting.
// Calculate the total occupied days from the merged array.
// Loop through the merged array and add the total days of each meeting.
// Subtract the total occupied days from the total days to get the days without meetings.
// Return the result.
