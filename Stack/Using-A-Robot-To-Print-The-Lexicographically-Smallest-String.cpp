// Leetcode 2434. Using a Robot to Print the Lexicographically Smallest String

class Solution
{
public:
    char l(vector<int> &freq)
    {
        for (int i = 0; i < 26; i++)
        {
            if (freq[i])
                return 'a' + i;
        }
        return 'a';
    }

    string robotWithString(string s)
    {
        stack<char> st;
        string t = "";
        vector<int> freq(26);

        for (char ch : s)
        {
            freq[ch - 'a']++;
        }

        for (char ch : s)
        {
            st.push(ch);
            freq[ch - 'a']--;

            while (!st.empty() && st.top() <= l(freq))
            {
                t += st.top();
                st.pop();
            }
        }

        while (!st.empty())
        {
            t += st.top();
            st.pop();
        }

        return t;
    }
};

// Explanation:

// 1. We define a helper function `l` that returns the lexicographically smallest character from the frequency array `freq`.
// 2. In the main function `robotWithString`, we initialize a stack `st` to hold characters and a string `t` to build the result.
// 3. We create a frequency array `freq` to count occurrences of each character in the input string `s`.
// 4. We iterate through each character `ch` in the string `s`.
// 5. For each character, we push it onto the stack and decrement its frequency in the `freq` array.
// 6. We then check if the top character of the stack is less than or equal to the lexicographically smallest character from the frequency array.
// 7. If it is, we pop the character from the stack and append it to the result string `t`.
// 8. After processing all characters in `s`, we pop any remaining characters from the stack and append them to `t`.
// 9. Finally, we return the result string `t`.
// Time Complexity: O(n), where n is the length of the input string s.
// Space Complexity: O(1), as we are using a constant amount of space for the frequency array and the stack.