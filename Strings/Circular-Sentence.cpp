// Leetcode 2490. Circular Sentence

class Solution
{
public:
    bool isCircularSentence(string s)
    {
        int n = s.size();
        if (s[0] != s[n - 1])
            return false;
        int i = 0;
        while (i < n)
        {
            if (s[i] == ' ')
            {
                if (s[i - 1] != s[i + 1])
                    return false;
            }
            i++;
        }
        return true;
    }
};

// Explanation:

// The first condition is that the first and last character of the string should be the same. If it is not the same, then the string cannot be circular.
// The second condition is that if there is a space in the string, then the character before the space and after the space should be the same. If it is not the same, then the string cannot be circular.
// If both the conditions are satisfied, then the string is circular.