// Leetcode 3305. Count-Of-Substrings-Containing-Every-Vowel-And-K-Consonants-I

class Solution
{
public:
    bool isVowel(char c)
    {
        return (c == 'a') || (c == 'e') || (c == 'i') || (c == 'o') ||
               (c == 'u');
    }
    int countOfSubstrings(string word, int k)
    {
        int n = word.size();
        unordered_map<char, int> mp;
        vector<int> c(n);
        int cons = n;

        for (int i = n - 1; i >= 0; i--)
        {
            c[i] = cons;
            char ch = word[i];
            if (!isVowel(ch))
            {
                cons = i;
            }
        }

        int i = 0, j = 0, cnt = 0;
        int ans = 0;

        while (j < n)
        {
            char ch = word[j];
            if (isVowel(ch))
            {
                mp[ch]++;
            }
            else
            {
                cnt++;
            }

            while (cnt > k)
            {
                char ch = word[i];
                if (isVowel(ch))
                {
                    mp[ch]--;
                    if (mp[ch] == 0)
                    {
                        mp.erase(ch);
                    }
                }
                else
                {
                    cnt--;
                }
                i++;
            }

            while (i < n && mp.size() == 5 && cnt == k)
            {
                int inc = c[j];
                ans += (inc - j);
                char ch = word[i];
                if (isVowel(ch))
                {
                    mp[ch]--;
                    if (mp[ch] == 0)
                    {
                        mp.erase(ch);
                    }
                }
                else
                {
                    cnt--;
                }
                i++;
            }

            j++;
        }

        return ans;
    }
};

// Explaination:

// We first find the first consonant from the right for each character.
// Then we use sliding window to find the number of substrings containing all vowels and k consonants.
// We use a map to store the frequency of vowels and a counter to store the number of consonants.
// We keep increasing the window size until we have k consonants.
// Then we keep increasing the left pointer until we have exactly k consonants.
// Then we keep increasing the left pointer until we have exactly 5 vowels.
// We add the number of substrings to the answer.
// We keep doing this until the right pointer reaches the end of the string.
// Finally we return the answer.