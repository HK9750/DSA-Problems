// Leetcode 2182. Construct String With Repeat Limit

class Solution
{
public:
    string repeatLimitedString(string s, int repeatLimit)
    {
        vector<int> count(26, 0);

        for (char c : s)
            count[c - 'a']++;
        int i = 25;
        string ans;

        while (i >= 0)
        {
            if (count[i] == 0)
            {
                i--;
                continue;
            }

            int freq = min(count[i], repeatLimit);
            count[i] -= freq;
            ans.append(freq, 'a' + i);

            if (count[i] > 0)
            {
                int j = i - 1;
                while (j >= 0 && count[j] == 0)
                    j--;
                if (j < 0)
                    break;
                ans.push_back('a' + j);
                count[j]--;
            }
        }

        return ans;
    }
};

// Explanation:

// We will count the frequency of each character in the string.
// We will iterate over the count array from the end and for each character, we will append the character to the answer string and decrement its frequency by the repeatLimit.
// If the frequency of the character is greater than the repeatLimit, we will append the character to the answer string and decrement its frequency by the repeatLimit.
// If the frequency of the character is greater than 0, we will find the next character with a non-zero frequency and append it to the answer string.
// We will repeat the above steps until all the characters are exhausted.
// We will return the answer string.
// Complexity Analysis:
// The time complexity for this approach is O(26 * n) = O(n), where n is the length of the string s.