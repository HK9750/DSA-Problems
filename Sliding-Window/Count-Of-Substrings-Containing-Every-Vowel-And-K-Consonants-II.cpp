// Leetcode 3306. Count-Of-Substrings-Containing-Every-Vowel-And-K-Consonants-II

class Solution
{
public:
    bool isVowel(char c)
    {
        return (c == 'a') || (c == 'e') || (c == 'i') || (c == 'o') ||
               (c == 'u');
    }

    long long countOfSubstrings(string word, int k)
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
        long long ans = 0;

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

// The problem is to find the number of substrings that contain every vowel and k consonants.
// We can solve this problem using the sliding window technique.
// We first find the first consonant from the right for each character.
// Then we use sliding window to find the number of substrings containing all vowels and k consonants.
// We use a map to store the frequency of each vowel.
// We also use a counter to store the number of consonants.
// We use two pointers i and j to iterate over the string.
// We increment j until we have k consonants in the window.
// If we have more than k consonants, we increment i until we have k consonants in the window.
// If we have all vowels and k consonants in the window, we increment i until we have all vowels and k consonants in the window.
// We add the number of substrings that contain all vowels and k consonants to the answer.
// We return the answer.