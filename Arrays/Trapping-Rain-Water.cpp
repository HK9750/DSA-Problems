// Leetcode 42. Trapping Rain Water

class Solution
{
public:
    int trap(vector<int> &heights)
    {
        int n = heights.size();
        int l = 0, r = heights.size() - 1;
        int rmax = heights[r];
        int lmax = heights[l];
        int res = 0;

        while (l < r)
        {
            if (rmax > lmax)
            {
                l++;
                lmax = max(lmax, heights[l]);
                res += lmax - heights[l];
            }
            else
            {
                r--;
                rmax = max(rmax, heights[r]);
                res += rmax - heights[r];
            }
        }

        return res;
    }
};

// Explaination

// The idea is to use two pointers to trap rainwater between the walls.
// Initialize two pointers, l and r, to the start and end of the array, respectively.
// Initialize two variables, lmax and rmax, to store the maximum height of the walls on the left and right sides.
// Initialize a variable, res, to store the total trapped rainwater.
// While the left pointer is less than the right pointer, check if the maximum height of the right wall is greater than the maximum height of the left wall.
// If the maximum height of the right wall is greater, move the left pointer to the right and update the maximum height of the left wall.
// Add the difference between the maximum height of the left wall and the current height to the result.
// If the maximum height of the left wall is greater, move the right pointer to the left and update the maximum height of the right wall.
// Add the difference between the maximum height of the right wall and the current height to the result.
// Return the result.

// Solution 2

class Solution
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size();
        vector<int> rmax(n);
        vector<int> lmax(n);
        int water = 0;

        lmax[0] = height[0];
        for (int i = 1; i < n; i++)
        {
            lmax[i] = max(lmax[i - 1], height[i]);
        }

        rmax[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            rmax[i] = max(rmax[i + 1], height[i]);
        }

        for (int i = 0; i < n; i++)
        {
            water += min(rmax[i], lmax[i]) - height[i];
        }

        return water;
    }
};

// Explaination

// The idea is to use two arrays to store the maximum height of the walls on the left and right sides.
// Initialize two arrays, lmax and rmax, to store the maximum height of the walls on the left and right sides.
// Initialize a variable, water, to store the total trapped rainwater.
// Calculate the maximum height of the walls on the left side and store it in the lmax array.
// Calculate the maximum height of the walls on the right side and store it in the rmax array.
// Iterate over the input array and calculate the trapped rainwater at each index.
// Add the minimum of the maximum height of the walls on the left and right sides to the result.
// Return the result.
