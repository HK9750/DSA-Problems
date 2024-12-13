// Leetcode 1387. Sort Integers by The Power Value

class Solution
{
public:
#define P pair<int, int>
    int findPower(int n)
    {
        int ans = 0;
        while (n != 1)
        {
            if (n % 2 == 0)
            {
                n = n / 2;
                ans++;
            }
            else
            {
                n = 3 * n + 1;
                ans++;
            }
        }

        return ans;
    }
    int getKth(int lo, int hi, int k)
    {
        priority_queue<P, vector<P>, greater<P>> pq;

        for (int i = lo; i <= hi; i++)
        {
            int s = findPower(i);
            pq.push({s, i});
        }

        for (int i = 0; i < k - 1 && !pq.empty(); i++)
        {
            pq.pop();
        }

        return pq.top().second;
    }
};

// Explaination:

// We have to find the power of the number and sort the numbers based on the power.
// We will use a priority queue to store the power and the number.
// We will iterate from lo to hi and find the power of each number and push it into the priority queue.
// We will pop the k-1 elements from the priority queue and return the top element.