// Leetcode 1962. Remove Stones to Minimize the Total

class Solution
{
public:
    int minStoneSum(vector<int> &piles, int k)
    {
        priority_queue<int> pq;

        for (int x : piles)
        {
            pq.push(x);
        }

        while (k--)
        {
            int temp = pq.top();
            pq.pop();

            int newTemp = ceil(temp / 2.0); // floor will give wrong answer
            pq.push(newTemp);
        }
        int ans = 0;
        while (!pq.empty())
        {
            int num = pq.top();
            pq.pop();
            ans += num;
        }

        return ans;
    }
};

// Explanation:
// 1. Create a max heap to store the piles
// 2. Push all the piles into the heap
// 3. While k is greater than 0
// 4. Get the top element from the heap
// 5. Divide the top element by 2 and push it back into the heap
// 6. Decrement k
// 7. Initialize the answer to 0
// 8. While the heap is not empty
// 9. Get the top element from the heap and add it to the answer
// 10. Return the answer
