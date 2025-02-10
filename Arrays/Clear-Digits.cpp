// Leetcode 3174. Clear Digits

class Solution
{
public:
    string clearDigits(string s)
    {
        stack<char> st;
        string ans = "";
        for (auto &c : s)
        {
            if (isdigit(c) && !st.empty())
            {
                st.pop();
            }
            else
            {
                st.push(c);
            }
        }
        while (!st.empty())
        {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};

// Explaination:

// We will use a stack to store the characters of the string. We will iterate through the string and if the character is a digit and the stack is not empty, we will pop the top element from the stack. Otherwise, we will push the character into the stack. Finally, we will pop all the elements from the stack and store them in a string and return the string.
// Time Complexity: O(n)