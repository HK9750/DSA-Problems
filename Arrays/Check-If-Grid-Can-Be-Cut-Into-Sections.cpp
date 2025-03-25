// Leetcode 3394. Check if the Grid Can Be Cut Into Sections

class Solution
{
public:
    bool check(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end());

        int sections = 0;
        int max_end = intervals[0][1];

        for (auto &interval : intervals)
        {
            int start = interval[0], end = interval[1];
            if (max_end <= start)
            {
                sections++;
            }
            max_end = max(max_end, end);
        }

        return sections >= 2;
    }

    bool checkValidCuts(int n, vector<vector<int>> &rectangles)
    {
        vector<vector<int>> x_intervals, y_intervals;

        for (auto &rect : rectangles)
        {
            x_intervals.push_back({rect[0], rect[2]});
            y_intervals.push_back({rect[1], rect[3]});
        }

        return check(x_intervals) || check(y_intervals);
    }
};

// Explaination:

// We are given a list of cooridantes of rectangles that do not overlap. We need to check if we can cut the grid into 2 or more sections.
// We first make intervals of x and y coordinates of the rectangles.
// We then sort the intervals based on the start of the intervals.
// We then iterate over the intervals and check if the max_end is less than the start of the interval. If it is, we increment the sections.
// We then update the max_end to the max of max_end and end of the interval.
// If the sections are greater than or equal to 2, we return true.
// Otherwise, we return false.