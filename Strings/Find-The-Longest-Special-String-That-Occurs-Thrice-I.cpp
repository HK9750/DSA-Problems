// Leetcode 2981. Find The Longest Special String That Occurs Thrice I

// Three Approaches

// Approach 1: Brute Force

// Time Complexity: O(N^2 * LogN) Because we are iterating over the string and for each character we are checking the substring of the string which will take O(N) time and then we are inserting the substring into the map which will take O(LogN) time.

class Solution
{
public:
    int maximumLength(string s)
    {
        int n = s.size();
        unordered_map<string, int> mp;
        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            string temp;
            for (int j = i; j < n; j++)
            {
                if (temp.empty() || temp.back() == s[j])
                {
                    temp.push_back(s[j]);
                    mp[temp]++;
                }
                else
                    break;
            }
        }

        for (auto &x : mp)
        {
            int strlength = x.first.length();
            if (x.second >= 3 && strlength > ans)
            {
                ans = strlength;
            }
        }

        return ans == 0 ? -1 : ans;
    }
};

// Explaination:
// We will maintain a unordered_map of string and its count.
// We will iterate over the string and for each character, we will check the substring of the string.
// We will insert the substring into the map.
// Finally, we will iterate over the map and check if the count of any substring is greater than or equal to 3.
// If it is, we will update the answer with the maximum length of the substring.
// Finally, we will return the answer. If the answer is 0, we will return -1.

// Approach 2: Optimizing the above approach using pair<char,int> instead of string to store the substring
// Time Complexity: O(N^2)

class Solution
{
public:
    int maximumLength(string s)
    {
        int n = s.size();
        map<pair<char, int>, int> mp;
        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            char temp = s[i];
            int len = 0;
            for (int j = i; j < n; j++)
            {
                if (temp == s[j])
                {
                    len++;
                    mp[{temp, len}]++;
                }
                else
                    break;
            }
        }

        for (auto &x : mp)
        {
            int strlength = x.first.second;
            if (x.second >= 3 && strlength > ans)
            {
                ans = strlength;
            }
        }

        return ans == 0 ? -1 : ans;
    }
};

// Explaination:
// We will maintain a map of pair<char,int> and its count.
// We will iterate over the string and for each character, we will check the substring of the string.
// We will insert the substring into the map.
// Finally, we will iterate over the map and check if the count of any substring is greater than or equal to 3.
// If it is, we will update the answer with the maximum length of the substring.
// Finally, we will return the answer. If the answer is 0, we will return -1.

// Approach 3: Optimizing the above approach using a single variable to store the substring
// Time Complexity: O(N)
// Find the longest substring of the same character that occurs thrice II can be solved using the same approach

class Solution
{
public:
    int maximumLength(string s)
    {
        int n = s.size();
        if (n == 0)
            return -1;

        vector<vector<int>> dp(26, vector<int>(n + 1, 0));
        int ans = 0, l = 0;

        for (int i = 0; i < n; i++)
        {
            if (i > 0 && s[i] == s[i - 1])
            {
                l++;
            }
            else
            {
                l = 1;
            }
            dp[s[i] - 'a'][l]++;
        }

        for (int row = 0; row < 26; row++)
        {
            int cumSum = 0;
            for (int col = n; col >= 1; col--)
            {
                cumSum += dp[row][col];
                if (cumSum >= 3)
                {
                    ans = max(ans, col);
                    break;
                }
            }
        }

        return ans == 0 ? -1 : ans;
    }
};

// Explaination:

// We will maintain a 2D dp array for each character and its length for about n.
// We will keep track of the count of each character and its length.
// We will iterate over the dp array and check if the count of any character is greater than or equal to 3.
// If it is, we will update the answer with the maximum length of the character.
// Finally, we will return the answer. If the answer is 0, we will return -1.