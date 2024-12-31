// Leetcode 983. Minimum Cost For Tickets

class Solution
{
public:
    unordered_set<int> travelDays;
    int dp[366];

    int solve(vector<int> &costs, int currDay, int lastDay)
    {
        if (currDay > lastDay)
            return 0;
        if (dp[currDay] != -1)
            return dp[currDay];
        if (travelDays.find(currDay) == travelDays.end())
        {
            return dp[currDay] = solve(costs, currDay + 1, lastDay);
        }
        int oneDay = costs[0] + solve(costs, currDay + 1, lastDay);
        int sevenDay = costs[1] + solve(costs, currDay + 7, lastDay);
        int thirtyDay = costs[2] + solve(costs, currDay + 30, lastDay);
        return dp[currDay] = min(oneDay, min(sevenDay, thirtyDay));
    }

    int mincostTickets(vector<int> &days, vector<int> &costs)
    {
        int lastDay = days.back();
        for (int day : days)
            travelDays.insert(day);
        memset(dp, -1, sizeof(dp));
        return solve(costs, days[0], lastDay);
    }
};

// Explanation:
// We will create a set of travel days and store all the days in it.
// We will create a dp array of size 366 and initialize it with -1.
// We will create a recursive function solve which will take the costs, current day and last day as input.
// If the current day is greater than the last day, we will return 0.
// If the dp array has the current day, we will return the value stored in the dp array.
// If the current day is not in the travel days set, we will return the value of the recursive function with the current day + 1 and last day.
// We will calculate the cost of the ticket for 1 day, 7 days and 30 days and return the minimum of the three.
// In the mincostTickets function, we will call the solve function with the costs, first day and last day.
// We will return the value returned by the solve function.
