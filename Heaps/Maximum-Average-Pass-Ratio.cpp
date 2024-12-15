// Leetcode 1792. Maximum Average Pass Ratio

class Solution
{
public:
    double maxAverageRatio(vector<vector<int>> &classes, int extraStudents)
    {
        auto gain = [](int pass, int total)
        {
            return (double)(pass + 1) / (total + 1) - (double)pass / total;
        };

        priority_queue<pair<double, pair<int, int>>> pq;
        for (auto &c : classes)
        {
            pq.push({gain(c[0], c[1]), {c[0], c[1]}});
        }

        while (extraStudents--)
        {
            auto [g, c] = pq.top();
            pq.pop();
            int pass = c.first, total = c.second;
            pass++, total++;
            pq.push({gain(pass, total), {pass, total}});
        }

        double res = 0.0;
        while (!pq.empty())
        {
            auto [g, c] = pq.top();
            pq.pop();
            res += (double)c.first / c.second;
        }

        return res / classes.size();
    }
};
