// Leetcode 621. Task Scheduler-I

class Solution
{
public:
    int leastInterval(vector<char> &tasks, int n)
    {
        vector<int> taskCounts(26, 0);
        for (char task : tasks)
        {
            taskCounts[task - 'A']++;
        }
        priority_queue<int> pq;
        for (int count : taskCounts)
        {
            if (count > 0)
            {
                pq.push(count);
            }
        }
        int time = 0;

        while (!pq.empty())
        {
            vector<int> temp;
            for (int i = 0; i < n + 1; i++)
            {
                if (!pq.empty())
                {
                    int tp = pq.top();
                    pq.pop();
                    temp.push_back(tp - 1);
                }
            }

            for (auto &x : temp)
            {
                if (x > 0)
                    pq.push(x);
            }

            if (pq.empty())
            {
                time += temp.size();
            }
            else
            {
                time += n + 1;
            }
        }
        return time;
    }
};

// Explaination:
// 1. First we will count the frequency of each task.
// 2. Then we will push the frequency of each task in the priority queue.
// 3. We will iterate until the priority queue is empty.
// 4. We will create a temporary vector.
// 5. We will iterate from 0 to n+1.
// 6. If the priority queue is not empty then we will pop the top element and push the top element-1 in the temporary vector.
// 7. We will iterate the temporary vector and if the element is greater than 0 then we will push the element in the priority queue.
// 8. If the maxHeap is empty then we will increment the time by the size of the temporary vector.
// 9. Else we will increment the time by n+1.

// Second Approach

class Solution
{
public:
    int leastInterval(vector<char> &tasks, int n)
    {
        vector<int> taskCounts(26, 0);
        for (char task : tasks)
        {
            taskCounts[task - 'A']++;
        }
        priority_queue<int> pq;
        for (int count : taskCounts)
        {
            if (count > 0)
            {
                pq.push(count);
            }
        }
        queue<pair<int, int>> q;
        int time = 0;
        while (!pq.empty() || !q.empty())
        {
            time++;
            if (!pq.empty())
            {
                int val = pq.top();
                pq.pop();
                if (val - 1 != 0)
                {
                    q.push({val - 1, time + n});
                }
            }
            if (!q.empty() && time >= q.front().second)
            {
                pq.push(q.front().first);
                q.pop();
            }
        }
        return time;
    }
};

// Explaination:

// 1. First we will count the frequency of each task.
// 2. Then we will push the frequency of each task in the priority queue.
// 3. We will create a queue of pairs of frequency and time.
// 4. We will iterate until the priority queue and queue are empty.
// 5. We will increment the time.
// 6. If the priority queue is not empty then we will pop the top element and if the frequency is not 0 then we will push the frequency-1 and time+n in the queue.
// 7. If the queue is not empty and the time is greater than or equal to the front element of the queue then we will push the frequency of the front element of the queue in the priority queue and pop the front element of the queue.
// 8. At last, we will return the time.