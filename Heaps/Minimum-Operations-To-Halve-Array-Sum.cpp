// Leetcode 2208. Minimum Operations to Halve Array Sum

class Solution
{
public:
    int halveArray(vector<int> &nums)
    {
        double sum = 0;
        priority_queue<double> pq;

        for (auto &x : nums)
        {
            sum += x;
            pq.push(x);
        }

        double target = sum / 2.0;
        int ans = 0;

        while (sum > target)
        {
            double temp = pq.top();
            pq.pop();
            double newTemp = temp / 2.0;
            sum -= temp;
            sum += newTemp;
            ans++;
            pq.push(newTemp);
        }

        return ans;
    }
};

// We take a max heap and populate it with all the elements of the array.
// We also calculate the sum of the array.
// We then calculate the target sum which is sum/2.
// We then keep popping the max element from the heap and keep dividing it by 2.
// We keep track of the number of operations we have done.
// We keep doing this until the sum is less than or equal to the target sum.
// We return the number of operations we have done.