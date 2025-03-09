// Leetcode 3206. Alternating Groups I

class Solution
{
public:
    int numberOfAlternatingGroups(vector<int> &colors)
    {
        int n = colors.size();

        int N = n + 2;
        for (int i = 0; i < 2; i++)
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

            if (j - i + 1 == 3)
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

// We can add the first two elements to the end of the array to make the array circular. Then we can use a sliding window to find the number of alternating groups of length 3. We can use two pointers i and j to represent the start and end of the window. We can move the end pointer j to the right until we find a group of 3 elements that are alternating. If we find such a group, we can increment the result and move the start pointer i to the right by 1. We can continue this process until the end pointer j reaches the end of the array. Finally, we can return the result. The time complexity of this approach is O(n), where n is the number of elements in the array. The space complexity is O(1).