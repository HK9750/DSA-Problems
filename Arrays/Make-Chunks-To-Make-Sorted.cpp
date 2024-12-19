// Leetcode 769. Max Chunks To Make Sorted

class Solution
{
public:
    int maxChunksToSorted(vector<int> &arr)
    {
        int n = arr.size();
        int maxi = 0;
        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            maxi = max(maxi, arr[i]);
            if (maxi == i)
                ans++;
        }

        return ans;
    }
};

// Explainaion: The idea is to keep track of the maximum element in the current chunk. If the maximum element is equal to the index of the element, then we can make a chunk. So, we increment the answer.
