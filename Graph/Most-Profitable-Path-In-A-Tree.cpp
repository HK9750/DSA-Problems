// Leetcode 2467. Most Profitable Path in a Tree

class Solution
{
public:
    unordered_map<int, vector<int>> adj;
    unordered_map<int, int> bobMap;
    int aliceIncome;
    bool DFSBob(int curr, int t, vector<bool> &visited)
    {
        visited[curr] = true;
        bobMap[curr] = t;

        if (curr == 0)
        { // reached target
            return true;
        }

        for (auto &ngbr : adj[curr])
        {
            if (!visited[ngbr])
            {
                if (DFSBob(ngbr, t + 1, visited) == true)
                {
                    return true;
                }
            }
        }

        bobMap.erase(curr);
        return false;
    }

    void DFSAlice(int curr, int t, int income, vector<bool> &visited, vector<int> &amount)
    {
        visited[curr] = true;

        if (bobMap.find(curr) == bobMap.end() || t < bobMap[curr])
        {
            income += amount[curr];
        }
        else if (t == bobMap[curr])
        {
            income += (amount[curr] / 2);
        }

        if (adj[curr].size() == 1 && curr != 0)
        { // leaf node
            aliceIncome = max(aliceIncome, income);
        }

        for (int &ngbr : adj[curr])
        {
            if (!visited[ngbr])
            {
                DFSAlice(ngbr, t + 1, income, visited, amount);
            }
        }
    }

    int mostProfitablePath(vector<vector<int>> &edges, int bob, vector<int> &amount)
    {
        int n = amount.size();

        aliceIncome = INT_MIN;
        for (vector<int> &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int time = 0;
        vector<bool> visited(n, false);
        DFSBob(bob, time, visited);

        int income = 0;
        visited.assign(n, false);
        DFSAlice(0, 0, income, visited, amount);

        return aliceIncome;
    }
};

// Explaination:

// Bob starts at node bob and moves along the tree to reach node 0. He can move from a node to any of its adjacent nodes in 1 minute. Bob can visit a node multiple times.
// Alice starts at node 0 and moves along the tree to reach node bob. She can move from a node to any of its adjacent nodes in 1 minute. Alice can visit a node multiple times.
// Alice earns amount[i] coins when she visits node i. However, if Alice visits a node i at the same time as Bob, Alice will earn amount[i] / 2 coins.
// Return the maximum profit that Alice can achieve.
