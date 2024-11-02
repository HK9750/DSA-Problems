// Leetcode 1845. Seat Reservation Manager
// The logic can be optimized but if it works, it works.

class SeatManager
{
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    SeatManager(int n)
    {
        for (int i = 0; i < n; i++)
        {
            pq.push(i + 1);
        }
    }

    int reserve()
    {
        int num = pq.top();
        pq.pop();
        return num;
    }

    void unreserve(int seatNumber)
    {
        pq.push(seatNumber);
    }
};

// Explaination

// We make a priority queue of integers in ascending order.
// In the constructor, we push all the seat numbers from 1 to n in the priority queue.
// In the reserve function, we pop the top element of the priority queue and return it.
// In the unreserve function, we push the seat number back to the priority queue.