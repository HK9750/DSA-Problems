// Leetcode 1455. Check If a Word Occurs As a Prefix of Any Word in a Sentence

class Solution
{
public:
    int isPrefixOfWord(string s, string k)
    {
        int n = s.size();
        int m = k.size();
        int ans = 1;
        int j = 0;
        bool isWordStart = true;

        for (int i = 0; i < n; i++)
        {
            if (s[i] == ' ')
            {
                ans++;
                isWordStart = true;
                j = 0;
            }
            else
            {
                if (isWordStart && s[i] == k[j])
                {
                    j++;
                    if (j == m)
                        return ans;
                }
                else
                {
                    isWordStart = false;
                    j = 0;
                }
            }
        }

        return -1;
    }
};

// Explaination

// We will iterate over the string and check if the current character is a space or not.
// If it is a space, we will increment the word count and reset the j pointer to 0.
// If it is not a space, we will check if the current character is the same as the character in the prefix string.
// If it is the same, we will increment the j pointer.
// If j becomes equal to the length of the prefix string, we will return the word count.
// If the current character is not the same as the character in the prefix string, we will reset the j pointer to 0.
// We will also set the isWordStart flag to false.
// If we reach the end of the string and the prefix string is not found in any word, we will return -1.