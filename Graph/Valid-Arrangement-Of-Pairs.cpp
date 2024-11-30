// Leetcode 2097. Valid Arrangement of Pairs

// Eulerian Path

class Solution
{
public:
    unordered_map<int, vector<int>> adj;
    unordered_map<int, int> deg;
    inline void build_graph(vector<vector<int>> &pairs)
    {
        for (auto &edge : pairs)
        {
            int start = edge[0], end = edge[1];
            adj[start].push_back(end);
            deg[start]++;
            deg[end]--;
        }
    }

    vector<int> rpath;
    inline void euler(int i)
    {
        vector<int> stk = {i};
        while (!stk.empty())
        {
            i = stk.back();
            if (adj[i].empty())
            {
                rpath.push_back(i);
                stk.pop_back();
            }
            else
            {
                int j = adj[i].back();
                adj[i].pop_back();
                stk.push_back(j);
            }
        }
    }

    vector<vector<int>> validArrangement(vector<vector<int>> &pairs)
    {
        const int e = pairs.size();
        adj.reserve(e);
        deg.reserve(e);

        build_graph(pairs);

        int i0 = deg.begin()->first;
        for (auto &[v, d] : deg)
        {
            if (d == 1)
            {
                i0 = v;
                break;
            }
        }

        euler(i0);

        vector<vector<int>> ans;
        ans.reserve(e);

        for (int i = rpath.size() - 2; i >= 0; i--)
            ans.push_back({rpath[i + 1], rpath[i]});

        return ans;
    }
};

auto init = []()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

// Explaination:

// The problem is to find a valid arrangement of pairs of integers from 1 to n such that the first element of the pair is divisible by the second element of the pair.
// The problem can be solved using the Eulerian Path algorithm.
// The Eulerian Path algorithm is used to find a path in a graph that visits every edge exactly once.
// The algorithm works as follows:
// 1. Build a graph from the given pairs of integers.
// 2. Find the starting node for the Eulerian Path.
// 3. Find the Eulerian Path using the DFS algorithm.
// 4. Construct the valid arrangement of pairs from the Eulerian Path.
// The build_graph function builds a graph from the given pairs of integers.
// The euler function finds the Eulerian Path using the DFS algorithm.
// The validArrangement function finds the valid arrangement of pairs using the Eulerian Path algorithm.
// The time complexity of the solution is O(n) where n is the number of pairs of integers. The space complexity of the solution is O(n) where n is the number of pairs of integers.