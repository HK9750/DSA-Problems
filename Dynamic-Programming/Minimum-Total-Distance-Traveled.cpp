// Leetcode 2463. Minimum Total Distance Traveled

class Solution
{
public:
    const long long inf = 1e15;
    long long solve(int i, int j, vector<int> &robots, vector<vector<int>> &F,
                    vector<vector<long long>> &dp)
    {
        if (i == robots.size())
        {
            return 0;
        }
        if (j == F.size())
        {
            return 1000000000000;
        }

        if (dp[i][j] != inf)
            return dp[i][j];

        long long ans = 1000000000000;

        long long d = 0;

        int k = i;

        for (int taken = 1; taken <= F[j][1]; taken++)
        {

            d += labs(robots[k] - F[j][0]);

            ans = min(ans, d + solve(k + 1, j + 1, robots, F, dp));
            k++;

            if (k == robots.size())
                break;
        }

        // Not taking current factory
        ans = min(ans, solve(i, j + 1, robots, F, dp));

        return dp[i][j] = ans;
    }
    long long minimumTotalDistance(vector<int> &robot,
                                   vector<vector<int>> &factory)
    {

        vector<vector<long long>> dp(robot.size(),
                                     vector<long long>(factory.size(), inf));

        sort(factory.begin(), factory.end());

        sort(robot.begin(), robot.end());

        return solve(0, 0, robot, factory, dp);
    }
};

// Explaiantion:

// Inputs:
// robots: List of robot positions.
// factory: List of [position, capacity] pairs for factories.
// Objective: Minimize the total distance traveled by robots to assigned factories, while ensuring no factory exceeds its capacity.
// Approach
// Recursive Function solve(i, j, robots, F, dp):

// Parameters:
// i: Current robot index.
// j: Current factory index.
// Base Cases:
// i == robots.size(): All robots are assigned, so cost is 0.
// j == F.size(): No factories left, return a large cost to indicate invalid path.
// Memoization: dp[i][j] stores minimum cost for assigning robots from i with factories from j to avoid recomputation.
// Decision:
// Option 1: Assign up to F[j][1] robots to F[j], accumulating distance d.
// Option 2: Skip the current factory and consider the next.
// Dynamic Programming Table Setup:

// Initialize dp with large value inf to mark uncomputed states.
// Store recursive results in dp[i][j].
// Main Function minimumTotalDistance:

// Sort robots and factories by positions to minimize distance efficiently.
// Calls solve(0, 0, robot, factory, dp) to get the minimum distance starting from the first robot and factory.