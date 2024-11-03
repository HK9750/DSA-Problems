// Leetcode 2260. Minimum Consecutive Cards to Pick Up

class Solution
{
public:
    int minimumCardPickup(vector<int> &cards)
    {
        unordered_map<int, int> lastIndex;
        int minLength = INT_MAX;

        for (int i = 0; i < cards.size(); ++i)
        {
            if (lastIndex.find(cards[i]) != lastIndex.end())
            {
                minLength = min(minLength, i - lastIndex[cards[i]] + 1);
            }
            lastIndex[cards[i]] = i;
        }

        return minLength == INT_MAX ? -1 : minLength;
    }
};

// Explanation:
// We can use a hash map to store the last index of each card.
// We can iterate over the cards and check if the card has been seen before.
// If it has, we can calculate the length of the subarray from the last index of the card to the current index.
// We can update the minimum length of the subarray.
// Finally, we can return the minimum length of the subarray.
// If no subarray is found, we can return -1.
