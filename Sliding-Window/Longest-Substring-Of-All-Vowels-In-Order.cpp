// Leetcode 1839. Longest Substring Of All Vowels In Order

class Solution
{
public:
    int longestBeautifulSubstring(string word)
    {
        int n = word.size();
        if (n < 5)
            return 0;

        int i = 0, j = 0, ans = 0, uniqueVowels = 0;

        while (j < n)
        {
            if (j > 0 && word[j] < word[j - 1])
            {
                i = j;
                uniqueVowels = 0;
            }

            if (j == i || word[j] != word[j - 1])
                uniqueVowels++;

            if (uniqueVowels == 5)
                ans = max(ans, j - i + 1);
            j++;
        }

        return ans;
    }
};

// Explaination:

// We will use a sliding window approach to solve this problem. We will keep track of the number of unique vowels in the current window. If the current character is less than the previous character, we will reset the window and start counting the unique vowels from the current character. If the number of unique vowels in the current window is equal to 5, we will update the answer. We will keep updating the answer as we move the window to the right. Finally, we will return the maximum length of the window that contains all the vowels in order.