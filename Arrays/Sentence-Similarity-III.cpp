// Leetcode 1813. Sentence Similarity III
// First two are for leetcode premium users

class Solution
{
public:
    bool areSentencesSimilar(string sentence1, string sentence2)
    {
        vector<string> words1 = splitSentence(sentence1);
        vector<string> words2 = splitSentence(sentence2);

        if (words1.size() < words2.size())
            swap(words1, words2);

        int n1 = words1.size(), n2 = words2.size();
        int s = 0, e = 0;

        while (s < n2 && words1[s] == words2[s])
            s++;
        while (e < n2 && words1[n1 - e - 1] == words2[n2 - e - 1])
            e++;

        return s + e >= n2;
    }

private:
    vector<string> splitSentence(const string &sentence)
    {
        vector<string> ans;
        string word = "";
        for (char c : sentence)
        {
            if (c == ' ')
            {
                if (!word.empty())
                {
                    ans.push_back(word);
                    word.clear();
                }
            }
            else
            {
                word += c;
            }
        }
        if (!word.empty())
            ans.push_back(word);
        return ans;
    }
};

// Explaination:

// We are given two sentences sentence1 and sentence2. We have to check if sentence2 is a subsequence of sentence1. We can do this by checking if the words of sentence2 are present in sentence1 in the same order.
// We will split the sentences into words and store them in vectors words1 and words2.
// If the number of words in words1 is less than the number of words in words2, we will swap words1 and words2.
// We will iterate over the words of words2 and find the longest common prefix and suffix between words1 and words2.
// If the sum of the length of the longest common prefix and suffix is greater than or equal to the length of words2, we will return true.
// If we reach the end of words2 and the sum of the length of the longest common prefix and suffix is less than the length of words2, we will return false.
