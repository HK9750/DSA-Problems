// Leetcode 2696. Minimum String Length After Removing Substrings

class Solution
{
public:
    int minLength(string s)
    {
        int n = s.size();
        stack<char> st;

        for (int i = 0; i < n; i++)
        {
            char val = s[i];

            if (st.empty())
            {
                st.push(val);
                continue;
            }

            else if (val == 'B' && st.top() == 'A')
                st.pop();
            else if (val == 'D' && st.top() == 'C')
                st.pop();
            else
                st.push(val);
        }
        return st.size();
    }
};

// Explaination:

// We are given a string s consisting of characters 'A', 'B', 'C', and 'D'. We have to find the minimum length of the string after removing some substrings. We can remove substrings "AB" and "CD" from the string.
// We will iterate over the characters of the string s.
// If the stack is empty, we will push the current character onto the stack.
// If the current character is 'B' and the top of the stack is 'A', we will pop the top of the stack.
// If the current character is 'D' and the top of the stack is 'C', we will pop the top of the stack.
// If the current character is not 'B' or 'D' or the top of the stack is not 'A' or 'C', we will push the current character onto the stack.
// At the end of the iteration, we will return the size of the stack as the answer.
