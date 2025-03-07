// Leetcode 125. Valid Palindrome

class Solution
{
public:
    bool isAlphaChar(char c)
    {
        return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
    }
    char toLower(char c)
    {
        return (c >= 'A' && c <= 'Z' ? c + 32 : c);
    }
    bool isPalindrome(string s)
    {
        int l = 0;
        int r = s.size() - 1;
        while (r > l)
        {
            if (!isAlphaChar(s[r]))
            {
                r--;
                continue;
            }
            if (!isAlphaChar(s[l]))
            {
                l++;
                continue;
            }
            if (toLower(s[r]) != toLower(s[l]))
            {
                return false;
            }
            r--;
            l++;
        }
        return true;
    }
};

// Explaination

// The idea is to use two pointers to check if the string is a valid palindrome.
// Initialize two pointers, l and r, to the start and end of the string, respectively.
// While the left pointer is less than the right pointer, check if the characters at the left and right pointers are alphanumeric characters.
// If the characters are not alphanumeric, move the pointers accordingly.
// If the characters are alphanumeric, check if the lowercase characters are equal.
// If the characters are not equal, return false.
// If the characters are equal, move the pointers accordingly.
// If the loop completes without returning false, return true.

// Solution 2

class Solution
{
public:
    bool isPalindrome(string s)
    {
        int i = 0, j = s.size() - 1;

        while (i < j)
        {
            while (!isalnum(s[j]) && i < j)
                j--;
            while (!isalnum(s[i]) && i < j)
                i++;

            if (tolower(s[i]) != tolower(s[j]))
                return 0;
            i++, j--;
        }
        return 1;
    }
};

// Explaination

// The idea is to use two pointers to check if the string is a valid palindrome.
// Initialize two pointers, i and j, to the start and end of the string, respectively.
// While the left pointer is less than the right pointer, check if the characters at the left and right pointers are alphanumeric characters.
// If the characters are not alphanumeric, move the pointers accordingly.
// If the characters are alphanumeric, check if the lowercase characters are equal.
// If the characters are not equal, return false.
// If the characters are equal, move the pointers accordingly.
// If the loop completes without returning false, return true.
