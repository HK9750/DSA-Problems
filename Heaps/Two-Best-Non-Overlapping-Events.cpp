// Leetcode 2084. Two Best Non-Overlapping Events

class Solution
{
public:
    int maxTwoEvents(vector<vector<int>> &events)
    {
        sort(begin(events), end(events));

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        int smax = 0;
        int tmax = 0;

        for (auto &event : events)
        {
            int s = event[0];
            int e = event[1];
            int v = event[2];

            while (!pq.empty() && pq.top().first < s)
            {
                smax = max(smax, pq.top().second);
                pq.pop();
            }

            tmax = max(tmax, v + smax);
            pq.push({e, v});
        }

        int ans = max(smax, tmax);

        return ans;
    }
};

// Explaination:

// We sort the events by their start time. We use a priority queue to keep track of the best event that ends before the current event starts. We iterate through the events and update the best event that ends before the current event starts. We update the best two events that do not overlap with each other. We return the maximum value of the two events.
// Time Complexity: O(nlogn)