// Leetcode 1834. Single-Threaded CPU

class Solution
{
public:
    vector<int> getOrder(vector<vector<int>> &tasks)
    {
        int n = tasks.size();

        for (int i = 0; i < n; i++)
        {
            tasks[i].push_back(i);
        }
        sort(begin(tasks), end(tasks));

        long long curr_time = 0;
        int index = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>
            pq;
        vector<int> ans;

        while (index < n || !pq.empty())
        {
            if (pq.empty() && tasks[index][0] > curr_time)
            {
                curr_time = tasks[index][0];
            }

            while (index < n && tasks[index][0] <= curr_time)
            {
                pq.push({tasks[index][1], tasks[index][2]});
                index++;
            }

            pair<int, int> temp = pq.top();
            pq.pop();
            curr_time += temp.first;
            ans.push_back(temp.second);
        }

        return ans;
    }
};

// Explanation:
// 1. Add the index of the task to the task array
// 2. Sort the tasks based on the start time
// 3. Initialize the current time, index, and a priority queue
// 4. While the index is less than the number of tasks or the priority queue is not empty
// 5. If the priority queue is empty and the current time is less than the start time of the next task, update the current time
// 6. While the index is less than the number of tasks and the start time of the task is less than or equal to the current time, push the task into the priority queue
// 7. Get the task with the smallest processing time from the priority queue
// 8. Update the current time and add the task index to the answer
// 9. Return the answer
