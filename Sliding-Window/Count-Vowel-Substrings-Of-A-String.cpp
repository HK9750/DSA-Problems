// Leetcode 2062. Count Vowel substrings of a string

class Solution
{
public:
    bool isVowel(char c)
    {
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }

    int countVowelSubstrings(string word)
    {
        int n = word.size();
        int i = 0, j = 0, ans = 0;

        while (i < n)
        {
            if (!isVowel(word[i]))
            {
                i++;
                continue;
            }

            unordered_map<char, int> mp;
            j = i;

            while (j < n && isVowel(word[j]))
            {
                mp[word[j]]++;
                if (mp.size() == 5)
                    ans++;
                j++;
            }

            i++;
        }

        return ans;
    }
};

// Explaination:

// We will use a sliding window approach to solve this problem. We will keep two pointers i and j. i will be the starting point of the window and j will be
// the ending point of the window. We will keep on moving the window and check if the window contains all the vowels or not. If it contains all the vowels
// then we will increment the answer. We will keep on moving the window until we reach the end of the string. We will return the answer at the end.