// Leetcode 916. Word Subsets

class Solution
{
public:
    vector<string> wordSubsets(vector<string> &A, vector<string> &B)
    {
        vector<int> bmax(26, 0);

        for (const string &b : B)
        {
            vector<int> bCount = count(b);
            for (int i = 0; i < 26; ++i)
            {
                bmax[i] = max(bmax[i], bCount[i]);
            }
        }

        vector<string> ans;
        for (const string &a : A)
        {
            vector<int> aCount = count(a);
            bool isSubset = true;
            for (int i = 0; i < 26; ++i)
            {
                if (aCount[i] < bmax[i])
                {
                    isSubset = false;
                    break;
                }
            }
            if (isSubset)
            {
                ans.push_back(a);
            }
        }

        return ans;
    }

private:
    vector<int> count(const string &S)
    {
        vector<int> ans(26, 0);
        for (char c : S)
        {
            ans[c - 'a']++;
        }
        return ans;
    }
};

// Explanation:

// We are given two arrays of strings A and B. We need to find all the strings in A which are universal to all the strings in B. A string is universal to another string if it contains all the characters of the other string.
// We can solve this problem by counting the frequency of each character in each string of A and B. We will maintain a vector bmax of size 26 which will store the maximum frequency of each character in all the strings of B. We will iterate over all the strings of B and update the bmax vector. After that, we will iterate over all the strings of A and check if the frequency of each character in the string is greater than or equal to the frequency of the same character in the bmax vector. If it is true for all the characters, then the string is universal to all the strings of B and we will add it to the answer vector. Finally, we will return the answer vector.
