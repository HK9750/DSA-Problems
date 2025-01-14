// Leetcode 2657. Find The Prefix Common Array Of Two Arrays

class Solution
{
public:
    vector<int> findThePrefixCommonArray(vector<int> &A, vector<int> &B)
    {
        int n = A.size();
        vector<int> freq(n + 1, 0);
        vector<int> ans;
        int common = 0;

        for (int i = 0; i < n; i++)
        {
            if (++freq[A[i]] == 2)
                common++;
            if (++freq[B[i]] == 2)
                common++;
            ans.push_back(common);
        }

        return ans;
    }
};

// Explaination:

// We make a frequency array of size n+1, where n is the size of the array.
// We also make a vector to store the answer.
// We iterate over the array and increment the frequency of the element in the frequency array.
// If the frequency of the element becomes 2, we increment the common variable.
// We add the common variable to the answer vector.
// Finally, we return the answer vector.
