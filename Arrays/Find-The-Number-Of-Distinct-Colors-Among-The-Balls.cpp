// Leetcode 3160. Find the Number of Distinct Colors Among the Balls

class Solution
{
public:
    vector<int> queryResults(int limit, vector<vector<int>> &queries)
    {
        int n = queries.size();
        vector<int> result(n);

        unordered_map<int, int> colormp;
        unordered_map<int, int> ballmp;

        for (int i = 0; i < n; i++)
        {
            int ball = queries[i][0];
            int color = queries[i][1];

            if (ballmp.count(ball))
            {
                int prevColor = ballmp[ball];
                colormp[prevColor]--;

                if (colormp[prevColor] == 0)
                {
                    colormp.erase(prevColor);
                }
            }

            ballmp[ball] = color;
            colormp[color]++;

            result[i] = colormp.size();
        }

        return result;
    }
};

// Explaination:

// We can use two hash maps to store the color of each ball and the number of balls of each color. The first hash map ballmp stores the color of each ball, and the second hash map colormp stores the number of balls of each color.
// For each query, we update the color of the ball in the ballmp hash map and update the number of balls of each color in the colormp hash map. If the color of the ball has changed, we need to update the number of balls of the previous color in the colormp hash map.
// Finally, we return the number of distinct colors in the colormp hash map after each query.
