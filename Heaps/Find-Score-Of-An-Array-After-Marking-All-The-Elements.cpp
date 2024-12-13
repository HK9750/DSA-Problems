// Leetcode 2593. Find Score of an Array After Marking All the Elements

class Solution
{
public:
#define ll long long
    long long findScore(vector<int> &nums)
    {
        int n = nums.size();
        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
        vector<bool> marked(n, false);

        for (int i = 0; i < n; i++)
            pq.push({nums[i], i});
        ll score = 0;

        while (!pq.empty())
        {
            pair<ll, int> top = pq.top();
            pq.pop();
            ll val = top.first;
            int index = top.second;
            if (marked[index])
                continue;
            score += val;
            marked[index] = true;
            if (index > 0)
                marked[index - 1] = true;
            if (index + 1 < n)
                marked[index + 1] = true;
        }

        return score;
    }
};

// Explantion:

// We are given an array of integers. We have to find the score of the array after marking all the elements. We can mark an element only if it is not already marked. If we mark an element, we also have to mark the elements adjacent to it. The score of the array is the sum of all the elements that are marked.
// We can solve this problem using a priority queue. We will push all the elements of the array into the priority queue along with their indices. We will use a boolean array to keep track of the elements that are marked. We will iterate over the priority queue and mark the elements and their adjacent elements. We will also add the value of the element to the score. Finally, we will return the score.