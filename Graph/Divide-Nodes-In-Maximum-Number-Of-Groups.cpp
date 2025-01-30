// Leetcode 2493. Divide Nodes Into Maximum Number of Groups

class Solution
{
public:
    int magnificentSets(int n, vector<vector<int>> &edges)
    {
        vector<vector<int>> adjList(n);
        for (auto edge : edges)
        {
            adjList[edge[0] - 1].push_back(edge[1] - 1);
            adjList[edge[1] - 1].push_back(edge[0] - 1);
        }

        vector<int> colors(n, -1);
        for (int node = 0; node < n; node++)
        {
            if (colors[node] != -1)
                continue;
            colors[node] = 0;
            if (!isBipartite(adjList, node, colors))
                return -1;
        }

        vector<int> distances(n);
        for (int node = 0; node < n; node++)
        {
            distances[node] = getLongestShortestPath(adjList, node, n);
        }

        int maxNumberOfGroups = 0;
        vector<bool> visited(n, false);
        for (int node = 0; node < n; node++)
        {
            if (visited[node])
                continue;
            maxNumberOfGroups += getNumberOfGroupsForComponent(
                adjList, node, distances, visited);
        }

        return maxNumberOfGroups;
    }

private:
    bool isBipartite(vector<vector<int>> &adjList, int node,
                     vector<int> &colors)
    {
        for (int neighbor : adjList[node])
        {
            if (colors[neighbor] == colors[node])
                return false;
            if (colors[neighbor] != -1)
                continue;
            colors[neighbor] = (colors[node] + 1) % 2;
            if (!isBipartite(adjList, neighbor, colors))
                return false;
        }
        return true;
    }

    int getLongestShortestPath(vector<vector<int>> &adjList, int srcNode,
                               int n)
    {
        queue<int> nodesQueue;
        vector<bool> visited(n, false);
        nodesQueue.push(srcNode);
        visited[srcNode] = true;
        int distance = 0;

        while (!nodesQueue.empty())
        {
            int numOfNodesInLayer = nodesQueue.size();
            for (int i = 0; i < numOfNodesInLayer; i++)
            {
                int currentNode = nodesQueue.front();
                nodesQueue.pop();
                for (int neighbor : adjList[currentNode])
                {
                    if (visited[neighbor])
                        continue;
                    visited[neighbor] = true;
                    nodesQueue.push(neighbor);
                }
            }
            distance++;
        }
        return distance;
    }

    int getNumberOfGroupsForComponent(vector<vector<int>> &adjList, int node,
                                      vector<int> &distances,
                                      vector<bool> &visited)
    {
        int maxNumberOfGroups = distances[node];
        visited[node] = true;
        for (int neighbor : adjList[node])
        {
            if (visited[neighbor])
                continue;
            maxNumberOfGroups = max(maxNumberOfGroups,
                                    getNumberOfGroupsForComponent(
                                        adjList, neighbor, distances, visited));
        }
        return maxNumberOfGroups;
    }
};

// Explaination

// The problem is to divide the nodes of a graph into groups such that each group is a connected component and the number of groups is maximized. A connected component is a subgraph in which each pair of nodes is connected by a path.
// The graph is represented as an undirected graph with n nodes and edges. The edges are given as a list of pairs of nodes. The nodes are numbered from 1 to n.
// We solve the problem using the following steps:
// 1. Create an adjacency list representation of the graph.
// 2. Check if the graph is bipartite. If the graph is not bipartite, return -1.
// 3. Calculate the longest shortest path from each node to any other node in the graph.
// 4. For each connected component in the graph, calculate the number of groups that can be formed.
// 5. Return the maximum number of groups that can be formed.

// Question why we are checking if the graph is bipartite?
// Answer: A graph is bipartite if it can be divided into two sets of nodes such that no two nodes in the same set are connected by an edge. If the graph is not bipartite, it is not possible to divide the nodes into groups such that each group is a connected component.

// Question why we are calculating the longest shortest path from each node to any other node in the graph?
// Answer: The longest shortest path from a node to any other node in the graph is the maximum distance between the node and any other node in the graph. This distance represents the number of groups that can be formed in the connected component containing the node. We are doing this to calculate the number of groups that can be formed in each connected component.

// Question why we are calculating the number of groups that can be formed for each connected component?
// Answer: For each connected component in the graph, we calculate the number of groups that can be formed. This number represents the maximum number of groups that can be formed in the connected component. We are doing this to find the maximum number of groups that can be formed in the graph.