// Leetcode 567. Permutation in String

class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        if (s1.length() > s2.length())
            return false;

        vector<int> s1Count(26, 0), s2Count(26, 0);

        for (int i = 0; i < s1.length(); ++i)
        {
            s1Count[s1[i] - 'a']++;
            s2Count[s2[i] - 'a']++;
        }

        for (int i = 0; i < s2.length() - s1.length(); ++i)
        {
            if (s1Count == s2Count)
                return true;
            s2Count[s2[i] - 'a']--;
            s2Count[s2[i + s1.length()] - 'a']++;
        }

        return s1Count == s2Count;
    }
};

// Explaination:

// We are given two strings s1 and s2. We have to check if s1 is a permutation of s2. We can do this by checking if the frequency of each character in s1 is equal to the frequency of each character in s2.
// We will use two vectors s1Count and s2Count to store the frequency of each character in s1 and s2 respectively.
// We will iterate over the first s1.length() characters of s2 and store the frequency of each character in s2Count.
// Then we will iterate over the remaining characters of s2 and update the frequency of each character in s2Count.
// If at any point the frequency of each character in s1 is equal to the frequency of each character in s2, we will return true.
// If we reach the end of s2 and the frequency of each character in s1 is not equal to the frequency of each character in s2, we will return false.
