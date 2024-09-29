// Leetcode 242. Valid Anagram

class Solution
{
public:
    bool isAnagram(string s, string t)
    {

        if (s.size() != t.size())
            return false;

        unordered_map<char, int> sMap, tMap;

        for (char c : s)
            sMap[c]++;
        for (char c : t)
            tMap[c]++;

        return sMap == tMap;
    }
};

// Explaination
// The idea is to use a hash map to store the frequency of each character in the string s and t. If the frequency of each character in the string s is equal to the frequency of each character in the string t, then return true. Otherwise, return false.

// Solution 2
class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};

// Explaination

// The idea is to sort the strings s and t. If the sorted strings are equal, then return true. Otherwise, return false.
