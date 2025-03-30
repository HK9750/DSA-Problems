// Leetcode 2405. Optimal Partition of String

class Solution
{
public:
    int partitionString(string s)
    {
        unordered_set<char> seen;
        int ans = 1;

        for (char c : s)
        {
            if (seen.count(c))
            {
                ans++;
                seen.clear();
            }
            seen.insert(c);
        }

        return ans;
    }
};

// Explaination:

// We just need to find the paritions that are not repeating any characters.
// We can do this by using a set to keep track of the characters we have seen so far in the current partition.
// If we encounter a character that is already in the set, we increment the partition count and clear the set to start a new partition.
// Finally, we return the total number of partitions we have found.
// The time complexity of this solution is O(n), where n is the length of the string, as we are iterating through the string once.
// The space complexity is O(1) since the size of the set is constant (at most 26 characters for lowercase English letters).