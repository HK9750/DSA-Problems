// Leetcode 1790: Check If One String Swap Can Make Strings Equal

class Solution
{
public:
    bool areAlmostEqual(string s1, string s2)
    {
        if (s1.size() != s2.size())
            return false;

        vector<int> diff;

        for (int i = 0; i < s1.size(); i++)
        {
            if (s1[i] != s2[i])
            {
                diff.push_back(i);
                if (diff.size() > 2)
                    return false;
            }
        }

        if (diff.size() == 0)
            return true;
        if (diff.size() != 2)
            return false;

        int i = diff[0], j = diff[1];
        return s1[i] == s2[j] && s1[j] == s2[i];
    }
};

// Explaination:

// If the two strings are not of the same length, then they can never be equal. So, we return false.
// We create a vector diff to store the indices where the characters of the two strings are different.
// We iterate through the strings and whenever we find a character that is different, we push the index of that character into the diff vector.
// If the size of the diff vector is greater than 2, then we return false because more than 2 characters are different.
// If the size of the diff vector is 0, then the strings are already equal, so we return true.
// If the size of the diff vector is not 2, then we return false because exactly 2 characters should be different.
// If the size of the diff vector is 2, then we check if the characters at the two indices are equal in the two strings. If they are equal, then we return true, otherwise, we return false.
