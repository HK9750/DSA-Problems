// Leetcode 2140. Solving Questions With Brainpower

// Recursion + Memoization

class Solution
{
public:
    vector<long long> memo;

    long long solve(vector<vector<int>> &questions, int index, int n)
    {
        if (index >= n)
            return 0;
        if (memo[index] != -1)
            return memo[index];

        long long skip = solve(questions, index + 1, n);

        long long take = questions[index][0];
        if (index + questions[index][1] + 1 < n)
        {
            take += solve(questions, index + questions[index][1] + 1, n);
        }

        return memo[index] = max(skip, take);
    }

    long long mostPoints(vector<vector<int>> &questions)
    {
        int n = questions.size();
        memo = vector<long long>(n, -1);
        return solve(questions, 0, n);
    }
};

// Explaination:

// 1. We are given a list of questions, each with a point value and a brainpower cost.
// 2. We can either solve a question and gain its points, or skip it and lose brainpower.
// 3. The goal is to maximize the total points we can earn by solving questions while managing our brainpower effectively.
// 4. We use recursion with memoization to explore all possible combinations of solving and skipping questions.
// 5. The base case is when we reach the end of the list of questions, where we return 0 points.
// 6. For each question, we have two choices: skip it or solve it. If we solve it, we also consider the brainpower cost of the next question.
// 7. We store the results of previously computed states in a memoization array to avoid redundant calculations.
// 8. Finally, we return the maximum points we can earn by starting from the first question.
// 9. The time complexity is O(n) due to memoization, where n is the number of questions.
// 10. The space complexity is O(n) for the memoization array.

// Bottom-Up Dynamic Programming

class Solution
{
public:
    long long mostPoints(vector<vector<int>> &questions)
    {
        int n = questions.size();
        vector<long long> dp(n + 1, 0);

        for (int i = n - 1; i >= 0; i--)
        {
            long long skip = dp[i + 1];
            long long take = questions[i][0];
            if (i + questions[i][1] + 1 < n)
            {
                take += dp[i + questions[i][1] + 1];
            }
            dp[i] = max(skip, take);
        }

        return dp[0];
    }
};

// Explaination:

// 1. We are given a list of questions, each with a point value and a brainpower cost.
// 2. We can either solve a question and gain its points, or skip it and lose brainpower.
// 3. The goal is to maximize the total points we can earn by solving questions while managing our brainpower effectively.
// 4. We use a bottom-up dynamic programming approach to iteratively compute the maximum points we can earn from each question.
// 5. We create a dp array where dp[i] represents the maximum points we can earn starting from question i.
// 6. We iterate through the questions in reverse order, calculating the maximum points for each question based on the choices we can make.
// 7. For each question, we have two choices: skip it or solve it. If we solve it, we also consider the brainpower cost of the next question.
// 8. We update the dp array with the maximum points we can earn for each question.
// 9. Finally, we return the maximum points we can earn by starting from the first question.
// 10. The time complexity is O(n) due to the single pass through the questions, where n is the number of questions.
// 11. The space complexity is O(n) for the dp array.
