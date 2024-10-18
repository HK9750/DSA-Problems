// Leetcode 295. Find Median from Data Stream
// A Leetcode hard

// Solution 1
class MedianFinder
{
public:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    MedianFinder()
    {
    }

    void addNum(int num)
    {
        if (maxHeap.empty() || num <= maxHeap.top())
            maxHeap.push(num);
        else
            minHeap.push(num);

        if (maxHeap.size() > minHeap.size() + 1)
        {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        else if (minHeap.size() > maxHeap.size())
        {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    double findMedian()
    {
        if (maxHeap.size() == minHeap.size())
            return (maxHeap.top() + minHeap.top()) / 2.0;
        return maxHeap.top();
    }
};

// Explaination
// Approach
// We can maintain two heaps, a maxHeap to store the smaller half of the elements and a minHeap to store the larger half of the elements. The maxHeap is a max-heap, which means that the largest element is at the top. The minHeap is a min-heap, which means that the smallest element is at the top. The median will be the top of the maxHeap if the number of elements is odd. If the number of elements is even, the median will be the average of the top of the maxHeap and the top of the minHeap.

// Solution 2

class MedianFinder
{
public:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

    MedianFinder()
    {
    }

    void addNum(int num)
    {
        maxHeap.push(num);

        if (!minHeap.empty() && !maxHeap.empty() && maxHeap.top() > minHeap.top())
        {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }

        if (maxHeap.size() > minHeap.size() + 1)
        {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        if (minHeap.size() > maxHeap.size() + 1)
        {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    double findMedian()
    {
        if (maxHeap.size() > minHeap.size())
            return maxHeap.top();
        else if (minHeap.size() > maxHeap.size())
            return minHeap.top();
        else
            return static_cast<double>((minHeap.top() + maxHeap.top()) / 2.0);
    }
};

// Explaination
// Difference between Solution 1 and Solution 2
// In Solution 1, we add the element to the maxHeap first and then balance the heaps. In Solution 2, we add the element to the maxHeap first and then balance the heaps. The difference is that in Solution 1, we balance the heaps before adding the element to the minHeap. In Solution 2, we balance the heaps after adding the element to the minHeap. Both solutions are correct and have the same time complexity. The only difference is the order in which we balance the heaps.