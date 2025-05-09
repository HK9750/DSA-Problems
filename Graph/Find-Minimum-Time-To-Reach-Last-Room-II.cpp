// Leetcode 3342. Find Minimum Time to Reach Last Room II

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
            if (currRow == n - 1 && currCol == m - 1)
                return currTime;
            dp[currRow][currCol] = currTime;

            for (auto &direction : directions)
            {
                int nextRow = currRow + direction[0];
                int nextCol = currCol + direction[1];
                if (nextRow >= 0 && nextRow < n &&
                    nextCol >= 0 && nextCol < m &&
                    dp[nextRow][nextCol] == INT_MAX)
                {
                    int cost = (currRow + currCol) % 2 + 1;
                    int start = max(moveTime[nextRow][nextCol], currTime);
                    int nextTime = start + cost;
                    minh.push({nextTime, nextRow, nextCol});
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
// 11. If we reach the last room `(n-1, m-1)`, we return the current time as the minimum time required to reach the last room.
// 12. We update the `dp` value for the current room with the current time.
// 13. We iterate through the possible directions to move to adjacent rooms.
// 14. For each adjacent room, we check if it is within bounds and has not been processed yet.
// 15. We calculate the cost to move to the adjacent room based on the parity of the current room's coordinates.
// 16. We calculate the next time to reach the adjacent room and push it into the priority queue if it is less than the recorded time in `dp`.
// 17. Finally, if we exhaust the priority queue without reaching the last room, we return -1 to indicate that it is not possible to reach the last room.
// 18. The algorithm uses Dijkstra's algorithm to find the shortest path in a weighted grid, where the weights are determined by the move times and the parity of the room coordinates.
// 19. The time complexity is O((n*m) * log(n*m)), where n and m are the dimensions of the grid, due to the priority queue operations.