// Leetcode 2337. Move Pieces to Obtain a String

class Solution
{
public:
    static bool canChange(string &s, string &t)
    {
        int n = s.size();
        for (int i = 0, j = 0; i < n || j < n; i++, j++)
        {
            while (i < n && s[i] == '_')
                i++;
            while (j < n && t[j] == '_')
                j++;
            char c = s[i];
            if (c != t[j])
                return 0;
            if (c == 'L' && i < j)
                return 0;
            if (c == 'R' && i > j)
                return 0;
        }
        return 1;
    }
};

// Explaination:

// We can move a piece from index i to index j if and only if the following conditions are satisfied:
// 1. The character at index i is the same as the character at index j.
// 2. If the character is 'L', then i should be less than or equal to j.
// 3. If the character is 'R', then i should be greater than or equal to j.
// We can iterate over the strings s and t and check if the above conditions are satisfied for each index i and j. If the conditions are not satisfied for any index i and j, then we return false. Otherwise, we return true.
// The time complexity of this approach is O(n), where n is the length of the strings s and t. The space complexity is O(1).