// Leetcode 3208. Alternating Groups II

class Solution
{
public:
    int numberOfAlternatingGroups(vector<int> &colors, int k)
    {
        int n = colors.size();

        int N = n + (k - 1);
        for (int i = 0; i < k - 1; i++)
        {
            colors.push_back(colors[i]);
        }

        int result = 0;
        int i = 0;
        int j = 1;
        while (j < N)
        {
            if (colors[j] == colors[j - 1])
            {
                i = j;
                j++;
                continue;
            }

            if (j - i + 1 == k)
            {
                result++;
                i++;
            }

            j++;
        }

        return result;
    }
};

// Explaination:

// We can add the first k-1 elements to the end of the array to make the array circular. Then we can use a sliding window to find the number of alternating groups of length k. We can use two pointers i and j to represent the start and end of the window. We can move the end pointer j to the right until we find a group of k elements that are alternating. If we find such a group, we can increment the result and move the start pointer i to the right by 1. We can continue this process until the end pointer j reaches the end of the array. Finally, we can return the result. The time complexity of this approach is O(n), where n is the number of elements in the array. The space complexity is O(1).