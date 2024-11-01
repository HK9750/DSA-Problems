// Leetcode 1957. Delete Characters to Make Fancy String

class Solution
{
public:
    string makeFancyString(string nums)
    {
        int n = nums.size();
        char prev = nums[0];
        string newstr = "";
        newstr += nums[0];
        int count = 1;

        for (int i = 1; i < n; i++)
        {
            if (prev == nums[i] && count > 1)
                continue;
            if (prev != nums[i])
            {
                prev = nums[i];
                count = 1;
                newstr += nums[i];
            }
            else
            {
                newstr += nums[i];
                count++;
            }
        }

        return newstr;
    }
};

// Explaination:

// Given a string s, a fancy string is a string made of two or more consecutive characters of the same type. For example, "aa", "aaa", "aaaa" are fancy strings, while "abc", "a", and "ab" are not fancy strings.
// We start off with the first character and keep adding the characters to the new string if the current character is same as the previous character and the count of the character is less than 2.
// If the current character is same as the previous character and the count of the character is greater than 1, we skip the current character.
// If the current character is different from the previous character, we add the current character to the new string and update the previous character and count.
// Finally, we return the new string.
