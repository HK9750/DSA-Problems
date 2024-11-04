// Leetcode 3163. String Compression III

class Solution
{
public:
    string compressedString(string word)
    {
        int n = word.size();
        string comp = "";
        int i = 0;

        while (i < n)
        {
            int count = 0;
            char ch = word[i];
            while (i < n && word[i] == ch && count < 9)
            {
                i++;
                count++;
            }
            comp += to_string(count) + ch;
        }

        return comp;
    }
};

// Explaination:

// The idea is to iterate over the string and keep track of the count of the current character.
// If the count exceeds 9, we can't compress the string, so we add the count and the character to the compressed string.
// If the count is less than 9, we can compress the string, so we add the count and the character to the compressed string.
// We keep track of the count of the current character and the character itself.
// We return the compressed string.