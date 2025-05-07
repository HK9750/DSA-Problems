// Leetcode 3341. Find Minimum Time to Reach Last Room I

class Solution
{
public:
    int minTimeToReach(vector<vector<int>> &moveTime)
    {
        int n = moveTime.size(), m = moveTime[0].size();
        vector<vector<int>> dp(n, vector<int>(m, INT_MAX));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minh;
        minh.push({0, 0, 0});
        moveTime[0][0] = 0;

        vector<vector<int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

        while (!minh.empty())
        {
            auto current = minh.top();
            minh.pop();
            int currTime = current[0];
            int currRow = current[1];
            int currCol = current[2];

            if (currTime >= dp[currRow][currCol])
                continue;
            dp[currRow][currCol] = currTime;
            if (currRow == n - 1 && currCol == m - 1)
                return currTime;

            for (auto &direction : directions)
            {
                int nextRow = currRow + direction[0];
                int nextCol = currCol + direction[1];
                if (nextRow >= 0 && nextRow < n && nextCol >= 0 && nextCol < m)
                {
                    int nextTime = max(moveTime[nextRow][nextCol], currTime) + 1;
                    if (nextTime < dp[nextRow][nextCol])
                    {
                        minh.push({nextTime, nextRow, nextCol});
                    }
                }
            }
        }

        return -1;
    }
};

// Explaination:

// 1. The problem is about finding the minimum time to reach the last room in a grid, where each room has a move time associated with it.
// 2. The input is a 2D vector `moveTime`, where `moveTime[i][j]` represents the time required to move to room `(i, j)`.
// 3. The goal is to find the minimum time required to reach the last room `(n-1, m-1)` starting from the first room `(0, 0)`.
// 4. We first determine the size of the input grid `n` and `m` using `moveTime.size()` and `moveTime[0].size()` respectively.
// 5. We create a 2D vector `dp` of the same size as `moveTime` to store the minimum time required to reach each room, initialized to `INT_MAX` (infinity).
// 6. We use a priority queue `minh` to keep track of the rooms to be processed, sorted by the minimum time required to reach them.
// 7. We push the starting room `(0, 0)` with a time of `0` into the priority queue and set `moveTime[0][0]` to `0`.
// 8. We define the possible directions to move in the grid using a vector of vectors `directions`.
// 9. We enter a loop that continues until the priority queue is empty. In each iteration, we pop the room with the minimum time from the queue.
// 10. We check if the current time is greater than or equal to the recorded time in `dp` for that room. If it is, we skip processing that room.
// 11. If the current room is the last room `(n-1, m-1)`, we return the current time as the result.
// 12. We iterate through each possible direction and calculate the next room's coordinates. If the next room is within bounds, we calculate the time to reach it.
// 13. If the calculated time is less than the recorded time in `dp` for that room, we push the next room into the priority queue with the new time.
// 14. Finally, if we exit the loop without reaching the last room, we return `-1` to indicate that it's not reachable.
// 15. The time complexity of this solution is O(n * m * log(n * m)), as we are processing each room and using a priority queue to keep track of the minimum times. The space complexity is O(n * m) due to the use of the `dp` vector and the priority queue.