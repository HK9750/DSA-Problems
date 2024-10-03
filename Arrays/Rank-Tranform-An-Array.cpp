// Leetcode 1331. Rank Transform of an Array

class Solution
{
public:
    vector<int> arrayRankTransform(vector<int> &arr)
    {
        vector<int> sortedArr = arr;
        sort(sortedArr.begin(), sortedArr.end());
        map<int, int> rank;
        int r = 1;
        for (int i = 0; i < sortedArr.size(); i++)
        {
            if (i == 0 || sortedArr[i] != sortedArr[i - 1])
            {
                rank[sortedArr[i]] = r++;
            }
        }
        for (int i = 0; i < arr.size(); i++)
        {
            arr[i] = rank[arr[i]];
        }
        return arr;
    }
};

// Explanation:

// We will create a sorted copy of the array.
// We will create a map of the element and its rank.
// We will iterate over the sorted array and assign ranks to the elements.
// We will iterate over the original array and replace the elements with their ranks.
// We will return the array.