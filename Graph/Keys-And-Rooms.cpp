// leetcode 841. Keys and Rooms

class Solution
{
public:
    bool canVisitAllRooms(vector<vector<int>> &rooms)
    {
        int n = rooms.size();
        vector<bool> visited(n, false);
        queue<int> q;

        q.push(0);
        visited[0] = true;

        while (!q.empty())
        {
            int room = q.front();
            q.pop();

            for (int key : rooms[room])
            {
                if (!visited[key])
                {
                    visited[key] = true;
                    q.push(key);
                }
            }
        }

        return all_of(visited.begin(), visited.end(), [](bool v)
                      { return v; });
    }
};

// Explanation:

// We can use a queue to keep track of the rooms that we can visit. We start by visiting room 0 and then we add all the keys of room 0 to the queue. We then visit the rooms that we can visit with the keys that we have. We keep doing this until the queue is empty. If we have visited all the rooms, then we return true, otherwise we return false.
