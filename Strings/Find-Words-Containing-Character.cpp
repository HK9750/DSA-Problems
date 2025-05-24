// Leetcode 2942. Find Words Containing Character

class Solution
{
public:
    vector<int> findWordsContaining(vector<string> &words, char x)
    {
        int n = words.size();
        vector<int> ans;

        for (int i = 0; i < n; i++)
        {
            if (words[i].find(x) != string::npos)
            {
                ans.push_back(i);
            }
        }

        return ans;
    }
};

// Explanation:

// 1. The function `findWordsContaining` takes a vector of strings `words` and a character `x` as input.
// 2. It initializes an integer `n` to the size of the `words` vector and creates an empty vector `ans` to store the indices of words containing the character `x`.
// 3. It then iterates through each word in the `words` vector using a for loop.
// 4. Inside the loop, it checks if the character `x` is present in the current word using the `find` method.
// 5. If the character is found (i.e., `find` does not return `string::npos`), it adds the index `i` to the `ans` vector.
// 6. Finally, it returns the `ans` vector containing the indices of words that contain the character `x`.
// 7. The time complexity of this algorithm is O(n * m), where n is the number of words and m is the average length of the words, since we are checking each word for the presence of the character.
// 8. The space complexity is O(k), where k is the number of words that contain the character `x`, as we are storing their indices in the `ans` vector.