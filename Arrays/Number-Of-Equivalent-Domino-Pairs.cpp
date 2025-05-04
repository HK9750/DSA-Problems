// Leetcode 1128. Number of Equivalent Domino Pairs

class Solution
{
public:
    int numEquivDominoPairs(vector<vector<int>> &dominoes)
    {
        map<pair<int, int>, int> mp;
        int count = 0;
        for (auto &d : dominoes)
        {
            if (d[0] > d[1])
                swap(d[0], d[1]);
            count += mp[make_pair(d[0], d[1])]++;
        }
        return count;
    }
};

// Explaination:

// 1. We need to find the number of equivalent domino pairs in the given list of dominoes.
// 2. Two dominoes are considered equivalent if they have the same values, regardless of their order. For example, [1, 2] and [2, 1] are equivalent.
// 3. We can use a map to store the count of each unique domino pair. The key will be a pair of integers representing the domino, and the value will be the count of that pair.
// 4. We iterate through the list of dominoes and for each domino, we check if the first value is greater than the second. If it is, we swap them to ensure that the smaller value is always first. This way, we can treat [1, 2] and [2, 1] as the same pair.
// 5. We then increment the count of that pair in the map and also add the current count to the total count of equivalent pairs. This is because for each new occurrence of a domino pair, it can form equivalent pairs with all previous occurrences of that pair.
// 6. Finally, we return the total count of equivalent pairs.
// 7. The time complexity of this solution is O(n), where n is the number of dominoes, as we are iterating through the list once and performing constant time operations for each domino. The space complexity is O(n) in the worst case, as we may need to store all unique domino pairs in the map.