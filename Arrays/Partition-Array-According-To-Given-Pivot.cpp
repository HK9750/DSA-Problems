// Leetcode 2161. Partition Array According to Given Pivot

class Solution
{
public:
    vector<int> pivotArray(vector<int> &nums, int pivot)
    {
        int n = nums.size();
        vector<int> less;
        vector<int> greater;
        int pivcnt = 0;

        for (int i = 0; i < n; i++)
        {
            if (pivot == nums[i])
                pivcnt++;
            else if (pivot > nums[i])
                less.push_back(nums[i]);
            else
                greater.push_back(nums[i]);
        }

        vector<int> ans;

        for (auto &x : less)
            ans.push_back(x);
        while (pivcnt--)
            ans.push_back(pivot);
        for (auto &x : greater)
            ans.push_back(x);

        return ans;
    }
};

// Explaination:

// We will create two vectors less and greater to store the elements less than and greater than the pivot element.
// We will also store the count of the pivot element in the variable pivcnt.
// We will iterate through the array and store the elements in the respective vectors.
// We will then create a new vector ans and store the elements in the order less, pivot, greater.
// Finally, we will return the ans vector.
