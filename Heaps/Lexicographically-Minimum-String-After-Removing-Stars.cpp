// Leetcode 3170. Lexicographically Minimum String After Removing Stars

class Solution
{
public:
    string clearStars(string s)
    {
        priority_queue<pair<char, int>, vector<pair<char, int>>, greater<pair<char, int>>> minh;
        unordered_map<int, bool> mpp;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '*')
            {
                mpp[-minh.top().second] = true;
                minh.pop();
            }
            else
            {
                minh.push({s[i], -i});
            }
        }
        string res;
        for (int i = 0; i < s.size(); i++)
        {
            if (mpp.count(i) || s[i] == '*')
                continue;
            res += s[i];
        }
        return res;
    }
};

// Explanation:

// 1. We define a function `clearStars` that takes a string `s` as input.
// 2. We initialize a priority queue `minh` to store pairs of characters and their negative indices, allowing us to retrieve the lexicographically smallest character efficiently.
// 3. We also create an unordered map `mpp` to keep track of indices that should be skipped (those that correspond to removed stars).
// 4. We iterate through each character in the string `s`.
// 5. If we encounter a star (`*`), we mark the index of the lexicographically smallest character (the top of the priority queue) as removed in the map `mpp` and pop it from the queue.
// 6. If the character is not a star, we push it onto the priority queue with its negative index to maintain the order.
// 7. After processing all characters, we initialize an empty string `res` to build the result.
// 8. We iterate through the string `s` again, and for each character, we check if its index is in the map `mpp` or if it is a star. If so, we skip it.
// 9. If the character is not skipped, we append it to the result string `res`.
// 10. Finally, we return the result string `res` which contains the lexicographically minimum string after removing stars.
// Time Complexity: O(n log n), where n is the length of the input string s, due to the priority queue operations.
// Space Complexity: O(n) for the priority queue and the unordered map.