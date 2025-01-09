// Leetcode 2185. Counting words with a given prefix

class Solution
{
public:
    bool check(string word, string pref)
    {
        int m = pref.size();

        for (int i = 0; i < m; i++)
        {
            if (word[i] != pref[i])
                return false;
        }

        return true;
    }

    int prefixCount(vector<string> &words, string pref)
    {
        int n = words.size();
        int count = 0;

        for (int i = 0; i < n; i++)
        {
            if (check(words[i], pref))
                count++;
        }

        return count;
    }
};

// Explaination:

// We are given a vector of strings and a prefix string. We have to count the number of words in the vector that have the given prefix.
// We can do this by iterating over the vector and checking if the prefix is present in the word. If it is present, we increment the count.
// Finally, we return the count.