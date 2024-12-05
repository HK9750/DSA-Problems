// Leetcode 389. Find The Difference

class Solution
{
public:
    char findTheDifference(string s, string t)
    {
        unordered_map<char, int> mp;
        for (char c : s)
            mp[c]++;
        for (char c : t)
        {
            if (!mp[c])
                return c;
            mp[c]--;
        }
        return ' ';
    }
};

// Explaination: We can use a hashmap to store the frequency of each character in the string s. Then we can iterate over the string t and decrement the frequency of each character in the hashmap. If we find a character in t that is not in the hashmap or has a frequency of 0, then we can return that character as the answer. This is because the character that is added in t will have a frequency of 1 in the hashmap, while all other characters will have a frequency of 0. So the character that is not in the hashmap or has a frequency of 0 is the one that is added in t.