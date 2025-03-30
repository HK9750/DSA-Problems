// Leetcode 763. Partition Labels

class Solution
{
public:
    vector<int> partitionLabels(string s)
    {
        map<char, int> lastPosition;
        for (int i = 0; i < s.size(); i++)
        {
            lastPosition[s[i]] = i;
        }
        int start = 0;
        int end = 0;
        vector<int> result;
        for (int i = 0; i < s.size(); i++)
        {
            end = max(end, lastPosition[s[i]]);
            if (i == end)
            {
                result.push_back(end - start + 1);
                start = i + 1;
            }
        }
        return result;
    }
};

// Explaination:

// The technique used in this problem is to find the last position of each character in the string.
// Then, we iterate through the string and keep track of the maximum last position of the characters we have seen so far.
// When we reach the end of a partition (i.e., when the current index is equal to the maximum last position), we add the size of the partition to the result vector and update the start index for the next partition.
// This ensures that we are partitioning the string in such a way that no characters from one partition appear in another partition.
// The time complexity of this solution is O(n), where n is the length of the string, as we are iterating through the string twice (once to find the last positions and once to create the partitions).
// The space complexity is O(1) since the size of the lastPosition map is constant (at most 26 characters for lowercase English letters).