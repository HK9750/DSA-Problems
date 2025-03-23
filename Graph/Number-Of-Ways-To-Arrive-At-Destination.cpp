// Leetcode 1976. Number of ways to arrive at destination

class Solution
{
public:
    typedef pair<long long, int> P;
    const int M = 1e9 + 7;
    int countPaths(int n, vector<vector<int>> &roads)
    {

        unordered_map<int, vector<P>> adj;
        for (auto &road : roads)
        {
            int u = road[0];
            int v = road[1];
            int time = road[2];
            adj[u].push_back({v, time});
            adj[v].push_back({u, time});
        }

        priority_queue<P, vector<P>, greater<P>> pq;
        vector<long long> result(n, LLONG_MAX);
        vector<int> pathCount(n, 0);

        result[0] = 0;
        pathCount[0] = 1;
        pq.push({0, 0});

        while (!pq.empty())
        {
            long long currTime = pq.top().first;
            int currNode = pq.top().second;
            pq.pop();

            if (currTime > result[currNode])
                continue;

            for (auto &vec : adj[currNode])
            {
                int adjNode = vec.first;
                int roadTime = vec.second;

                if (currTime + roadTime < result[adjNode])
                {
                    result[adjNode] = currTime + roadTime;
                    pathCount[adjNode] = pathCount[currNode];
                    pq.push({result[adjNode], adjNode});
                }
                else if (currTime + roadTime == result[adjNode])
                {
                    pathCount[adjNode] =
                        (pathCount[adjNode] + pathCount[currNode]) % M;
                }
            }
        }

        return pathCount[n - 1];
    }
};

// First we create an adjacency list from the given roads.
// We use Dijkstra's algorithm to find the shortest path from the source to the destination.
// We also keep track of the number of ways to reach a node.
// If the time taken to reach a node is less than the current time, we update the time and the number of ways to reach that node.
// If the time taken to reach a node is equal to the current time, we add the number of ways to reach the current node to the number of ways to reach the destination node.
// Finally, we return the number of ways to reach the destination node.