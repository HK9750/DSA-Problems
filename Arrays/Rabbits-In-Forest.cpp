// Leetcode 781. Rabbits in Forest

class Solution
{
public:
    int numRabbits(vector<int> &nums, int total = 0)
    {
        unordered_map<int, int> mp;
        for (int i : nums)
            mp[i]++;

        for (auto &p : mp)
            total += ceil((double)p.second / (p.first + 1)) * (p.first + 1);
        return total;
    }
};

// Explaination:

// The problem is about counting the number of rabbits in a forest based on their colors and the number of rabbits that can see each other.
// Each rabbit can see the other rabbits of the same color, and they will report the number of rabbits they see. The goal is to find the minimum number of rabbits in the forest.
// The solution uses a hash map to count the occurrences of each color and then calculates the total number of rabbits based on the formula:
// total += ceil((double)p.second / (p.first + 1)) * (p.first + 1);
// Then we return the total number of rabbits in the forest.