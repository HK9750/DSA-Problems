#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Heap
{
public:
    int arr[100];
    int size = 0;

    void insert(int val)
    {
        size++;
        int index = size;
        arr[index] = val;

        while (index > 1)
        {
            int parent = index / 2;
            if (arr[parent] < arr[index])
            {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else
            {
                return;
            }
        }
    }

    void deleteFromHeap()
    {
        swap(arr[1], arr[size]);
        size--;

        int i = 1;

        while (i < size)
        {
            int left = 2 * i;
            int right = 2 * i + 1;

            if (left < size && arr[i] < arr[left])
            {
                swap(arr[i], arr[left]);
                i = left;
            }
            else if (right < size && arr[i] < arr[right])
            {
                swap(arr[i], arr[right]);
                i = right;
            }
            else
            {
                return;
            }
        }
    }

    // 1 - Based Indexing
    void heapify1(vector<int> &arr, int n, int i)
    {
        int largest = i;
        int left = 2 * i;
        int right = 2 * i + 1;

        if (left < n && arr[largest] < arr[left])
        {
            largest = left;
        }
        else if (right < n && arr[largest] < arr[right])
        {
            largest = right;
        }

        if (largest != i)
        {
            swap(arr[largest], arr[i]);
            heapify(arr, n, largest);
        }
    }

    // 0-based indexing
    void heapify(vector<int> &arr, int n, int i)
    {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && arr[left] > arr[largest])
        {
            largest = left;
        }
        else if (right < n && arr[right] > arr[largest])
        {
            largest = right;
        }
        if (largest != i)
        {
            swap(arr[largest], arr[i]);
            heapify(arr, n, largest);
        }
    }

    void heapSort(vector<int> &arr)
    {
        for (int i = arr.size() / 2; i >= 0; i--)
        {
            heapify(arr, arr.size(), i);
        }

        for (int i = arr.size() - 1; i >= 0; i--)
        {
            swap(arr[0], arr[i]);
            heapify(arr, i, 0);
        }
    }

    void print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
    }
};

int main()
{
    Heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.print();
    cout << endl;
    h.deleteFromHeap();
    h.print();

    printf("\n");

    vector<int> res;
    res.push_back(50);
    res.push_back(55);
    res.push_back(53);
    res.push_back(52);
    res.push_back(54);

    for (int i = res.size() / 2; i >= 0; i--)
    {
        h.heapify(res, res.size(), i);
    }

    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }

    cout << endl;

    vector<int> res1;
    res1.push_back(50);
    res1.push_back(55);
    res1.push_back(53);
    res1.push_back(52);
    res1.push_back(54);

    h.heapSort(res1);

    for (int i = 0; i < res1.size(); i++)
    {
        cout << res1[i] << " ";
    }

    cout << endl;

    priority_queue<int> maxHeap;
    maxHeap.push(50);
    maxHeap.push(55);
    maxHeap.push(53);
    maxHeap.push(52);

    while (!maxHeap.empty())
    {
        cout << maxHeap.top() << " ";
        maxHeap.pop();
    }

    cout << endl;

    priority_queue<int, vector<int>, greater<int>> minHeap;
    minHeap.push(50);
    minHeap.push(55);
    minHeap.push(53);
    minHeap.push(52);

    while (!minHeap.empty())
    {
        cout << minHeap.top() << " ";
        minHeap.pop();
    }

    return 0;
}
