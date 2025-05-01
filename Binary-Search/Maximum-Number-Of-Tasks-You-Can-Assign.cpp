// Leetcode 2071. Maximum Number of Tasks You Can Assign

class Solution
{
public:
    bool check(vector<int> &tasks, vector<int> &workers, int pills,
               int strength, int mid)
    {
        int pillsUsed = 0;
        multiset<int> st(begin(workers), begin(workers) + mid);

        for (int i = mid - 1; i >= 0; i--)
        {
            int reqrd = tasks[i];
            auto it = prev(st.end());

            if (*it >= reqrd)
            {
                st.erase(it);
            }
            else if (pillsUsed >= pills)
            {
                return false;
            }
            else
            {
                auto weakestWorkerIt = st.lower_bound(reqrd - strength);
                if (weakestWorkerIt == st.end())
                {
                    return false;
                }
                st.erase(weakestWorkerIt);
                pillsUsed++;
            }
        }

        return true;
    }
    int maxTaskAssign(vector<int> &tasks, vector<int> &workers, int pills,
                      int strength)
    {
        int m = tasks.size();
        int n = workers.size();

        int l = 0;
        int r = min(m, n);

        sort(begin(tasks), end(tasks));
        sort(begin(workers), end(workers), greater<int>());

        int result = 0;

        while (l <= r)
        {
            int mid = l + (r - l) / 2;

            if (check(tasks, workers, pills, strength, mid))
            {
                result = mid;
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }

        return result;
    }
};

// Explaination:

// 1. The problem is to assign tasks to workers such that the maximum number of tasks can be assigned while considering the constraints of pills and strength.
// 2. The function `check` is used to determine if it is possible to assign `mid` tasks to workers given the constraints of pills and strength. It uses a multiset to keep track of the available workers and their strengths.
// 3. The function iterates through the tasks in reverse order and checks if the strongest available worker can complete the task. If not, it checks if a weaker worker can complete the task using a pill. If neither is possible, it returns false.
// 4. The main function `maxTaskAssign` uses binary search to find the maximum number of tasks that can be assigned. It initializes the left and right pointers for binary search and sorts the tasks and workers arrays.
// 5. The binary search continues until the left pointer exceeds the right pointer. If the `check` function returns true for a mid value, it updates the result and moves the left pointer to mid + 1. Otherwise, it moves the right pointer to mid - 1.
// 6. Finally, the function returns the maximum number of tasks that can be assigned.
// 7. The time complexity of this solution is O(n log n) due to sorting and binary search, where n is the number of tasks or workers. The space complexity is O(n) for the multiset used in the `check` function.
