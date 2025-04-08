// Leetcode 3396. Minimum Number of Operations to Make All Array Elements Distinct

class Solution
{
public:
    int minimumOperations(vector<int> &nums)
    {
        set<int> s;
        int n = nums.size();

        for (int i = n - 1; i >= 0; i--)
        {
            if (s.find(nums[i]) != s.end())
            {
                return i / 3 + 1;
            }
            s.insert(nums[i]);
        }

        return 0;
    }
};

// Explaination:

// The approach is to use a set to keep track of the unique elements in the array. We iterate through the array from the end to the beginning, and for each element, we check if it is already in the set. If it is, we return the number of operations needed to make all elements distinct, which is equal to the index divided by 3 plus 1. If the element is not in the set, we insert it into the set. If we reach the beginning of the array without finding any duplicates, we return 0, indicating that no operations are needed.
// Why we are dividing by 3? Because we are considering the number of operations needed to make all elements distinct, and since we are iterating through the array from the end to the beginning, we can assume that we can make 3 elements distinct in one operation. Therefore, we divide the index by 3 to get the number of operations needed. The +1 is added to account for the current element being processed.