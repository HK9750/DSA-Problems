// Leetcode 8. String to Integer (atoi)
// It has the most annoying test cases I have ever seen and the person who wrote these test cases should be fired.

class Solution
{
public:
    int myAtoi(string s)
    {
        int n = s.size();
        int i = 0;
        int sign = 1;

        while (i < n && s[i] == ' ')
            i++;

        if (i < n && (s[i] == '-' || s[i] == '+'))
        {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        long ans = 0;
        while (i < n && s[i] >= '0' && s[i] <= '9')
        {
            ans = ans * 10 + (s[i] - '0');

            if (ans > INT_MAX)
            {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }

            i++;
        }

        return (int)(ans * sign);
    }
};

// Explanation:

// First we check that if the string is empty or not. If it is empty then we return 0.
// Then we check for the white spaces in the string and remove them.
// Then we check for the sign of the number. If it is negative then we set the sign to -1 else we set it to 1.
// Then we iterate through the string and check for the digits. If we find a digit then we multiply the ans by 10 and add the digit to it.
// If the ans is greater than INT_MAX then we return INT_MAX if the sign is positive else we return INT_MIN.
// In the end we return the ans * sign.
