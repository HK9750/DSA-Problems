// Leetcode 2558. Take Gifts From The Richest Pile

class Solution
{
public:
    long long pickGifts(vector<int> &gifts, int k)
    {
        long long ans = 0;

        priority_queue<long long> pq;

        for (auto &gift : gifts)
        {
            pq.push(gift);
            ans += gift;
        }

        while (k--)
        {
            long long temp = pq.top();
            pq.pop();
            long long newTemp = sqrt(temp);
            ans -= temp - newTemp;
            pq.push(newTemp);
        }

        return ans;
    }
};

// Explaination:

// We take a priority queue and push all the gifts in it.
// We also keep a variable ans to store the sum of all the gifts.
// We run a loop k times and in each iteration we pop the top element from the priority queue subtract the difference between the popped element and its square root from the ans.
// We then push the square root of the popped element in the priority queue.
// Finally we return the ans.