// Leetcode 2116. Check If a Parentheses String Can Be Valid

class Solution
{
public:
    bool canBeValid(string s, string locked)
    {
        int n = s.size();

        if (n % 2 == 1)
            return false;

        stack<int> open, openclose;

        for (int i = 0; i < n; i++)
        {
            if (locked[i] == '0')
                openclose.push(i);
            else if (s[i] == '(')
                open.push(i);
            else if (s[i] == ')')
            {
                if (!open.empty())
                    open.pop();
                else if (!openclose.empty())
                    openclose.pop();
                else
                    return false;
            }
        }

        while (!open.empty() && !openclose.empty() &&
               openclose.top() > open.top())
        {
            open.pop();
            openclose.pop();
        }

        if (!open.empty())
            return false;

        return true;
    }
};

// Explaination

// The idea is to use a stack to check if a parentheses string can be valid.
// Initialize a stack to store the indices of the open parentheses.
// Initialize a stack to store the indices of the open and close parentheses.
// Iterate through the string and check the following:
// If the character is an open parentheses and the index is not locked, push the index to the open stack.
// If the character is a close parentheses and the index is not locked, check the following:
// If the open stack is not empty, pop the index from the open stack.
// If the open stack is empty and the openclose stack is not empty, pop the index from the openclose stack.
// If the open stack is empty and the openclose stack is empty, return false.
// If the open stack and openclose stack are not empty, check the following:
// While the open stack and openclose stack are not empty and the top index of the openclose stack is greater than the top index of the open stack, pop the top index from both stacks.
// If the open stack is not empty, return false.
// If the loop completes without returning false, return true.