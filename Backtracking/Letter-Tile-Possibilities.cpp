// Leetcode 1079. Letter Tile Possibilities

class Solution
{
private:
    int ans = 0, cnts[26] = {};
    long long count(int n)
    {
        long long val = 1;
        for (int i = 1; i <= n; ++i)
            val *= i;
        return val;
    }
    void updateAns()
    {
        long long total = 0, div = 1;
        for (int i = 0; i < 26; ++i)
        {
            total += cnts[i];
            div *= count(cnts[i]);
        }
        ans += count(total) / div;
    }
    void compute(string &A, int begin)
    {
        if (begin == A.size())
        {
            updateAns();
            return;
        }
        cnts[A[begin] - 'A']++;
        compute(A, begin + 1);
        cnts[A[begin] - 'A']--;
        do
        {
            ++begin;
        } while (begin < A.size() && A[begin] == A[begin - 1]);
        compute(A, begin);
    }

public:
    int numTilePossibilities(string tiles)
    {
        sort(tiles.begin(), tiles.end());
        compute(tiles, 0);
        return ans - 1;
    }
};

// Explainaion:

// The idea is to count the number of permutations of the given string. We can do this by using backtracking. We will keep track of the count of each character in the given string. We will then calculate the total number of permutations of the given string by dividing the total number of permutations of the string by the product of the factorials of the count of each character in the string. We will then update the answer by adding the total number of permutations of the string divided by the product of the factorials of the count of each character in the string. We will then recursively call the function to calculate the total number of permutations of the string by incrementing the count of the character at the current index and then recursively calling the function. We will then decrement the count of the character at the current index and then recursively call the function. We will then skip the characters that are the same as the current character and then recursively call the function. We will then sort the given string and then call the function to calculate the total number of permutations of the string. We will then return the answer.