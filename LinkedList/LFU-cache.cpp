// Leetcode 460. LFU Cache
// A Least Frequently Used (LFU) cache is a type of cache that removes the least frequently used items first.
// A leetcode hard problem and the most lengthy one. It is a good problem to understand the concept of LFU cache.
#include <unordered_map>

class LFUCache
{
public:
    struct ListNode
    {
        int key, value, freq;
        ListNode(int _key, int _value, int _freq) : key(_key), value(_value), freq(_freq) {}
    };

    int capacity, minFreq;
    unordered_map<int, ListNode *> keyToNode;
    unordered_map<int, list<ListNode *>> freqToList;
    unordered_map<int, list<ListNode *>::iterator> keyToIter;

    LFUCache(int _capacity)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        capacity = _capacity;
        minFreq = 0;
    }

    void updateFreq(ListNode *node)
    {
        int curFreq = node->freq;
        freqToList[curFreq].erase(keyToIter[node->key]);
        if (freqToList[curFreq].empty())
        {
            freqToList.erase(curFreq);
            if (minFreq == curFreq)
            {
                minFreq++;
            }
        }

        node->freq++;
        freqToList[node->freq].push_front(node);
        keyToIter[node->key] = freqToList[node->freq].begin();
    }

    int get(int key)
    {
        if (keyToNode.find(key) == keyToNode.end())
        {
            return -1;
        }

        ListNode *node = keyToNode[key];
        updateFreq(node);

        return node->value;
    }

    void put(int key, int value)
    {
        if (capacity == 0)
            return;

        if (keyToNode.find(key) != keyToNode.end())
        {
            ListNode *node = keyToNode[key];
            node->value = value;
            updateFreq(node);
        }
        else
        {
            if (keyToNode.size() == capacity)
            {
                ListNode *evictNode = freqToList[minFreq].back();
                keyToNode.erase(evictNode->key);
                keyToIter.erase(evictNode->key);
                freqToList[minFreq].pop_back();
                if (freqToList[minFreq].empty())
                {
                    freqToList.erase(minFreq);
                }
                delete evictNode;
            }

            ListNode *newNode = new ListNode(key, value, 1);
            keyToNode[key] = newNode;
            freqToList[1].push_front(newNode);
            keyToIter[key] = freqToList[1].begin();
            minFreq = 1;
        }
    }
};

// Time Complexity: O(1) for both get and put operations

// Space Complexity: O(N) where N is the capacity of the cache

// Explanation:

// 1. We maintain a hashmap keyToNode which stores the key to the corresponding node in the cache.
// 2. We maintain a hashmap freqToList which stores the frequency of the nodes in the cache.
// 3. We maintain a hashmap keyToIter which stores the iterator of the node in the freqToList.
// 4. We maintain a minFreq variable which stores the minimum frequency of the nodes in the cache.
// 5. In the constructor, we initialize the capacity and minFreq.
// 6. In the updateFreq function, we update the frequency of the node and move it to the front of the list of nodes with the same frequency.
// 7. In the get function, we check if the key is present in the cache. If it is present, we update the frequency of the node and return the value.
// 8. In the put function, we check if the key is present in the cache. If it is present, we update the value and frequency of the node. If it is not present, we check if the cache is full. If the cache is full, we evict the least frequently used node. We create a new node with the key, value, and frequency 1 and add it to the cache. We update the keyToNode, freqToList, and keyToIter accordingly. We update the minFreq if necessary.
// 9. The time complexity of both get and put operations is O(1) as we are using hashmaps for constant time lookups.