// Leetcode 292. Nim Game

// A hard question diguised as an easy question to troll the beginners.

class Solution
{
public:
    bool canWinNim(int n)
    {
        return !(n % 4 == 0);
        // I can win if the number of stones is not a multiple of 4.
    }
};