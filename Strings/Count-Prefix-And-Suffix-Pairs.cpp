// Leetcode 3042. Count Prefix And Suffix Pairs I

class Solution
{
public:
    bool check(string str1, string str2)
    {
        int n = str1.size();
        int m = str2.size();

        for (int i = 0; i < m; ++i)
        {
            if (str1[i] != str2[i])
            {
                return false;
            }
        }

        for (int i = 0; i < m; ++i)
        {
            if (str1[n - m + i] != str2[i])
            {
                return false;
            }
        }

        return true;
    }

    int countPrefixSuffixPairs(vector<string> &words)
    {
        int n = words.size();
        int count = 0;

        for (int i = 0; i < n; ++i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                if (check(words[j], words[i]))
                {
                    count++;
                }
            }
        }

        return count;
    }
};

// Explaination:

// We have to find the number of pairs of strings such that one string is a prefix of the other and the other is a suffix of the first string.
// We can do this by checking if the first m characters of the second string are equal to the first m characters of the first string and the last m characters of the first string are equal to the last m characters of the second string.
// If both conditions are satisfied, then the strings are a prefix-suffix pair.
// We can iterate over all pairs of strings and check if they are a prefix-suffix pair.
// If they are, we increment the count.
// Finally, we return the count.
