// Leetcode 796. Rotate String

class Solution
{
public:
    bool rotateString(string s, string goal)
    {
        if (s.size() != goal.size())
            return false;

        string newStr = s + s;
        return newStr.find(goal) != string::npos;
    }
};

// Explanation:
// We can concatenate the string s with itself and check if the goal string is a substring of the new string.
// If it is, then we can say that the goal string is a rotated string of the original string s.
