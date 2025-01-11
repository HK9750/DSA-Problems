// Leetcode 1400. Construct K Palindrome Strings

class Solution
{
public:
    bool canConstruct(string s, int k)
    {
        if (s.size() < k)
            return false;
        if (s.size() == k)
            return true;

        int mp[26] = {0};

        for (auto &c : s)
            mp[c - 'a']++;

        int oddcnt = 0;

        for (int i = 0; i < 26; i++)
        {
            if (mp[i] % 2 != 0)
                oddcnt++;
        }

        return oddcnt <= k;
    }
};

// Explaination:

// If the length of the string is less than k, then it is impossible to construct k palindromic strings.
// If the length of the string is equal to k, then we can construct k palindromic strings.
// If the length of the string is greater than k, then we can construct k palindromic strings if the number of characters with odd frequency is less than or equal to k. This is because we can use the characters with odd frequency to form the middle character of the palindrome and the characters with even frequency to form the left and right half of the palindrome. If the number of characters with odd frequency is greater than k, then it is impossible to construct k palindromic strings.
// The above logic is based on the fact that a palindrome can have at most one character with odd frequency. If the number of characters with odd frequency is greater than one, then it is impossible to construct a palindrome.
