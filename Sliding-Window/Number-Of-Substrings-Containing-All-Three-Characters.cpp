// Leetcode 1358: Number of Substrings Containing All Three Characters

class Solution
{
public:
    int numberOfSubstrings(string s)
    {
        int n = s.size();
        unordered_map<char, int> mp;
        int i = 0, j = 0, ans = 0;

        while (j < n)
        {
            char ch = s[j];
            mp[ch]++;

            while (mp.size() == 3)
            {
                ans += (n - j);
                char ch = s[i];
                mp[ch]--;
                if (mp[ch] == 0)
                {
                    mp.erase(ch);
                }
                i++;
            }

            j++;
        }

        return ans;
    }
};

// Explaination:

// We will use sliding window technique to solve this problem. We will keep track of the frequency of the characters in the window using a map. We will keep expanding the window until we have all the characters in the window. Once we have all the characters in the window, we will start shrinking the window from the left side. We will keep track of the number of substrings that can be formed with the current window. We will keep adding the number of substrings to the answer. We will keep shrinking the window until we have all the characters in the window. We will keep repeating this process until we reach the end of the string. At the end, we will return the answer.