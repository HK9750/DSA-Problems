// Leetcode 506. Relative Ranks

class Solution
{
public:
    vector<string> findRelativeRanks(vector<int> &score)
    {
        priority_queue<pair<int, int>> pq;

        for (int i = 0; i < score.size(); i++)
        {
            pq.push(make_pair(score[i], i));
        }

        vector<string> res(score.size());
        int pos = 1;

        for (int i = 0; i < score.size(); i++)
        {
            auto [val, index] = pq.top();
            pq.pop();

            if (pos == 1)
                res[index] = "Gold Medal";
            else if (pos == 2)
                res[index] = "Silver Medal";
            else if (pos == 3)
                res[index] = "Bronze Medal";
            else
                res[index] = to_string(pos);

            pos++;
        }

        return res;
    }
};

// Explanation:

// We are given an array of scores. We have to return the relative ranks of the players. The relative ranks are as follows:
// 1. The player with the highest score gets the Gold Medal.
// 2. The player with the second-highest score gets the Silver Medal.
// 3. The player with the third-highest score gets the Bronze Medal.
// 4. The player with the fourth-highest score gets the 4th rank.
// 5. The player with the fifth-highest score gets the 5th rank.
// and so on.

// We can solve this problem using a priority queue. We will store the scores along with their indices in the priority queue. We will then pop the elements from the priority queue and assign the ranks to the players based on their indices.
