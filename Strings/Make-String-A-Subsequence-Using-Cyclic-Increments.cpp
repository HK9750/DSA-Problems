// Leetcode 2825. Make a string a subsequence of another string using cyclic increments

class Solution
{
public:
    bool canMakeSubsequence(string str1, string str2)
    {
        int n = str1.size();
        int m = str2.size();
        if (m > n)
            return false;
        int j = 0;

        for (int i = 0; i < n && j < m; i++)
        {
            if (str1[i] == str2[j] || str1[i] + 1 == str2[j] ||
                str1[i] - 25 == str2[j])
            {
                j++;
            }
        }

        return j == m;
    }
};

// Explaination:

// We can make a string a subsequence of another string using cyclic increments if and only if the following conditions are satisfied:
// 1. The characters at the corresponding indices in the two strings are the same.
// 2. If the character in the first string is 'z', then the character in the second string should be 'a'.
// 3. If the character in the first string is 'a', then the character in the second string should be 'z'.
// We can iterate over the two strings and check if the above conditions are satisfied for each index i and j. If the conditions are not satisfied for any index i and j, then we return false. Otherwise, we return true.
// The time complexity of this approach is O(n), where n is the length of the strings str1 and str2. The space complexity is O(1).