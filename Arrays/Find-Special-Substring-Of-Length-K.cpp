// Leetcode 3456. Find Special Substring of Length K

class Solution
{
public:
    bool hasSpecialSubstring(string s, int k)
    {
        int n = s.length();
        if (k > n)
            return false;

        for (int i = 0; i < n; i++)
        {
            int cnt = 1;
            while (i + 1 < n && s[i] == s[i + 1])
            {
                cnt++;
                i++;
            }
            if (cnt == k)
                return true;
        }

        return false;
    }
};

// Explaination:

// We are given a string s and an integer k. We need to find if there is a substring of length k in the string s which is a special substring. A special substring is a substring in which all the characters are the same.
// We can solve this problem by iterating over the string s and checking if there is a substring of length k which is a special substring. We can do this by keeping track of the count of the characters in the substring and checking if the count is equal to k. If the count is equal to k, then the substring is a special substring and we return true. If we do not find any special substring of length k, then we return false.
