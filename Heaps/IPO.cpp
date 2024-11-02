// Leetcode 502. IPO
// The problem looks scary but it is very simple.

class Solution
{
public:
    int findMaximizedCapital(int k, int w, vector<int> &profits, vector<int> &capital)
    {
        vector<pair<int, int>> projects;
        for (int i = 0; i < profits.size(); i++)
        {
            projects.push_back({capital[i], profits[i]});
        }

        sort(projects.begin(), projects.end());

        priority_queue<int> maxProfitHeap;

        int i = 0;
        while (k--)
        {
            while (i < projects.size() && projects[i].first <= w)
            {
                maxProfitHeap.push(projects[i].second);
                i++;
            }

            if (maxProfitHeap.empty())
                break;

            w += maxProfitHeap.top();
            maxProfitHeap.pop();
        }

        return w;
    }
};

// Explaination:

// First we make a vector of pairs of profits and capital.
// We sort the vector in ascending order of capital.
// We make a priority queue of integers in descending order.
// We iterate over the vector and push the profits to the priority queue if the capital is less than or equal to the current capital.
// If the priority queue is empty, we break the loop.
// If the priority queue is not empty, we add the top element of the priority queue to the capital.
// Finally we return the capital.
