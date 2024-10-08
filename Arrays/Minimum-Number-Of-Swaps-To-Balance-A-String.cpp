// Leetcode 1963. Minimum Number of Swaps to Make the String Balanced

class Solution
{
public:
    int minSwaps(string s)
    {
        int n = s.size();
        if (n == 0)
            return 0;

        int swap = 0;

        for (auto &ch : s)
        {
            if (ch == '[')
                swap++;
            else if (swap)
                swap--;
        }

        return (swap + 1) / 2;
    }
};

// Explaination:

// We are given a string s consisting of characters '[' and ']'. We have to find the minimum number of swaps required to make the string balanced. A string is balanced if it can be split into two equal halves such that the left half contains only '[' and the right half contains only ']'.
// We will iterate over the characters of the string s.
// If the current character is '[', we will increment the swap count.
// If the current character is ']' and the swap count is greater than 0, we will decrement the swap count.
// If the current character is ']' and the swap count is 0, we will increment the swap count.
// At the end of the iteration, we will return (swap + 1) / 2 as the answer.
