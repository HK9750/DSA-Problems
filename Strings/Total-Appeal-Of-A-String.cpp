// Leetcode 2262. Total Appeal of a String

class Solution
{
public:
    long long appealSum(string s)
    {
        unordered_map<char, int> lastIndex;
        long long totalAppeal = 0;
        long long currentAppeal = 0;

        for (int i = 0; i < s.size(); ++i)
        {
            char ch = s[i];
            if (lastIndex.count(ch))
            {
                currentAppeal += (i - lastIndex[ch]);
            }
            else
            {
                currentAppeal += (i + 1);
            }
            lastIndex[ch] = i;
            totalAppeal += currentAppeal;
        }

        return totalAppeal;
    }
};

// Explanation:

// We can use a hash map to store the last index of each character in the string.
// We can iterate over the string and calculate the appeal of each character.
// The appeal of a character is the sum of the distances between the current index and the last index of the character.
// We can update the total appeal by adding the current appeal.
// Finally, we can return the total appeal of the string.
