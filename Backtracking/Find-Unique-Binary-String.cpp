// Leetcode 1980. Find Unique Binary String

// Using Backtracking

class Solution
{
public:
    string findDifferentBinaryString(vector<string> &nums)
    {
        int n = nums[0].size();
        unordered_set<string> numSet(nums.begin(), nums.end());

        string ans = "";

        function<void(string)> generateBinary = [&](string binary)
        {
            if (binary.size() == n)
            {
                if (numSet.find(binary) == numSet.end())
                {
                    ans = binary;
                }
                return;
            }
            if (!ans.empty())
                return;
            generateBinary(binary + '0');
            generateBinary(binary + '1');
        };

        generateBinary("");
        return ans;
    }
};

// Explaination:

// We are given a vector of strings, each string is a binary number of length n. We have to find a binary number of length n which is not present in the given vector of strings.
// We can solve this problem using backtracking. We will generate all possible binary numbers of length n and check if the number is present in the given vector of strings or not.
// If the number is not present in the given vector of strings, we will return that number as the answer.
// We will use a set to store all the given binary numbers. We will generate all possible binary numbers of length n using backtracking. If the generated number is not present in the set, we will return that number as the answer.

// Time Complexity: O(2^n)

// Using Simple Approach

class Solution
{
public:
    string findDifferentBinaryString(vector<string> &nums)
    {
        string result;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i][i] == '0')
            {
                result += '1';
            }
            else
            {
                result += '0';
            }
        }
        return result;
    }
};