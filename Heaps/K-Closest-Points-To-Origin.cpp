// Leetcode 973: K Closest Points to Origin
// Anoying negative test cases

class Solution
{
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {

        priority_queue<pair<double, vector<int>>, vector<pair<double, vector<int>>>,
                       greater<pair<double, vector<int>>>>
            minHeap;

        for (int i = 0; i < points.size(); i++)
        {
            int first = points[i][0];
            int second = points[i][1];

            double dist = sqrt(pow(first, 2) + pow(second, 2));
            minHeap.push(make_pair(dist, points[i]));
        }

        vector<vector<int>> res;
        while (k-- && !minHeap.empty())
        {
            res.push_back(minHeap.top().second);
            minHeap.pop();
        }

        return res;
    }
};

// Explaination:

// We have to find the K closest points to the origin.
// We can use a minHeap to solve this problem.
// We will calculate the distance of each point from the origin and push it into the minHeap.
// We will then pop the top element from the minHeap and push it into the result vector.
// We will repeat this process K times.
// Finally, we will return the result vector.
// The time complexity of this solution is O(NlogK) where N is the number of points and K is the number of closest points we have to find.