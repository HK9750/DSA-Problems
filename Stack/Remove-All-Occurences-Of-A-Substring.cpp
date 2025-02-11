// Leetcode 1910. Remove All Occurrences of a Substring

// Using stack approach
class Solution
{
public:
    string removeOccurrences(string s, string part)
    {
        int n = s.length();
        int m = part.length();
        stack<char> st;

        string ans = "";

        for (int i = 0; i < n; i++)
        {
            st.push(s[i]);

            if (st.size() >= m && check(st, part, m))
            {
                for (int j = 0; j < m; j++)
                    st.pop();
            }
        }

        while (!st.empty())
        {
            ans = st.top() + ans;
            st.pop();
        }

        return ans;
    }

private:
    bool check(stack<char> st, string &part, int m)
    {
        stack<char> temp = st;

        for (int i = m - 1; i >= 0; i--)
        {
            if (st.top() != part[i])
                return false;
            st.pop();
        }

        return true;
    }
};

// Explaination:

// Used a stack to store the characters of the string s.
// If the size of the stack is greater than or equal to the size of the part string, then check if the last m characters of the stack are equal to the part string.
// If they are equal, then pop the last m characters from the stack.
// Finally, return the stack as a string.

// using string find method of cpp

class Solution
{
public:
    string removeOccurrences(string s, string part)
    {
        int i = s.find(part);
        while (i != string::npos)
        {
            s = s.substr(0, i) + s.substr(i + part.size());
            i = s.find(part);
        }
        return s;
    }
};

// Explaination:

// Used the find method of the string class to find the first occurrence of the part string in the string s.
// If the part string is found, then remove the part string from the string s.
// Repeat the above steps until the part string is not found in the string s.
// Finally, return the string s.
