// Leetcode 773. Sliding Puzzle

class Solution
{
public:
    int slidingPuzzle(vector<vector<int>> &A)
    {
        string target = "123450", start;
        int ans = 0;
        vector<vector<int>> neighbors = {{1, 3}, {0, 2, 4}, {1, 5}, {0, 4}, {1, 3, 5}, {2, 4}};
        for (int i = 0; i < 2; ++i)
        {
            for (int j = 0; j < 3; ++j)
                start += '0' + A[i][j];
        }
        if (target == start)
            return 0;
        unordered_set<string> seen;
        seen.insert(start);
        queue<string> q;
        q.push(start);
        while (q.size())
        {
            int cnt = q.size();
            ++ans;
            while (cnt--)
            {
                auto B = q.front();
                q.pop();
                int from = 0;
                for (int i = 0; i < 6; ++i)
                {
                    if (B[i] == '0')
                    {
                        from = i;
                        break;
                    }
                }
                for (auto &to : neighbors[from])
                {
                    swap(B[from], B[to]);
                    if (B == target)
                        return ans;
                    if (seen.count(B) == 0)
                    {
                        seen.insert(B);
                        q.push(B);
                    }
                    swap(B[from], B[to]);
                }
            }
        }
        return -1;
    }
};

// Explanation:

// The idea is to use BFS to find the minimum number of moves required to reach the target state.
// We will start from the initial state and visit all the possible states that can be reached from the current state.
// We will keep track of the states that we have visited using a set.
// We will use a queue to visit all the states in the graph.
// We will start from the initial state and visit all the states that can be reached from the current state.
// We will keep track of the states that we have visited using the set.
// We will return the minimum number of moves required to reach the target state.
// We will return -1 if the target state cannot be reached from the initial state.
