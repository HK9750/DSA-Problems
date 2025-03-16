// Leetcode 2594. Minimum Time To Repair Cars

class Solution
{
public:
    typedef long long ll;

    bool isPossible(vector<int> &ranks, ll mid, int cars)
    {
        ll carsFixed = 0;

        for (int i = 0; i < ranks.size(); i++)
        {
            carsFixed += sqrt(mid / ranks[i]);
        }

        return carsFixed >= cars;
    }

    long long repairCars(vector<int> &ranks, int cars)
    {
        int n = ranks.size();

        ll l = 1;
        int maxR = *max_element(begin(ranks), end(ranks));
        ll r = 1LL * maxR * cars * cars;

        ll result = -1;
        while (l <= r)
        {
            ll mid = l + (r - l) / 2;

            if (isPossible(ranks, mid, cars))
            {
                result = mid;
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }

        return result;
    }
};

// Explaination:
// We have to find the minimum time to repair cars such that all cars are repaired.
// We can use binary search to find the minimum time.
// We can check if it is possible to repair all cars in a given time by iterating over the ranks and calculating the number of cars that can be repaired in that time.
// If the number of cars that can be repaired is greater than or equal to the total number of cars, then we can update the answer and move to the left half of the binary search.
// Otherwise, we move to the right half of the binary search.
// We can find the minimum time by iterating over the ranks and finding the maximum rank.
// The minimum time will be the minimum rank and the maximum time will be the maximum rank multiplied by the total number of cars squared.
// We can then use binary search to find the minimum time.
// The time complexity of this approach is O(nlog(max)), where n is the number of ranks and max is the maximum rank.
// The space complexity is O(1).