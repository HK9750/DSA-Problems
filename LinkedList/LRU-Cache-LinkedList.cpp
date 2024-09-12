// Leetcode 146. LRU Cache

// One of the hardest questions I have ever done. I had to look at the solution to understand how to implement it and this question is the base for another hard question that is actually a leetcode hard LFU Cache.
// I recommend the ones seeing this code should first watch this video https://www.youtube.com/watch?v=z9bJUPxzFOw

class LRUCache
{
public:
    struct ListNode
    {
        int key;
        int val;
        ListNode *next;
        ListNode *prev;
        ListNode(int _key, int _val)
        {
            key = _key;
            val = _val;
        }
    };

    ListNode *head = new ListNode(-1, -1);
    ListNode *tail = new ListNode(-1, -1);
    int cap;
    unordered_map<int, ListNode *> mp;

    LRUCache(int capacity)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void addNode(ListNode *newNode)
    {
        ListNode *nxt = head->next;
        head->next = newNode;
        newNode->prev = head;
        newNode->next = nxt;
        nxt->prev = newNode;
    }

    void deleteNode(ListNode *delNode)
    {
        ListNode *delnext = delNode->next;
        ListNode *delprev = delNode->prev;
        delprev->next = delnext;
        delnext->prev = delprev;
    }

    int get(int key1)
    {
        if (mp.find(key1) == mp.end())
            return -1;

        ListNode *resNode = mp[key1];
        int res = resNode->val;

        mp.erase(key1);

        deleteNode(resNode);
        addNode(resNode);

        mp[key1] = head->next;

        return res;
    }

    void put(int key2, int value)
    {
        if (mp.find(key2) != mp.end())
        {
            ListNode *existingnode = mp[key2];
            mp.erase(key2);
            deleteNode(existingnode);
        }
        if (mp.size() == cap)
        {
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        ListNode *addPar = new ListNode(key2, value);
        addNode(addPar);
        mp[key2] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

// Explaination

// The class implements LRU cache with get and put functions, get retrieves the item from cache and put adds the item to cache. The cache has a capacity and if the cache is full, the least recently used item is removed from the cache.

// The class uses a doubly linked list and a hashmap to implement the cache. The doubly linked list is used to keep track of the order of items in the cache. The head->next of the list is the most recently used item and the tail->prev of the list is the least recently used item. The hashmap is used to store the key-value pairs of the items in the cache.

// The class has a constructor that takes the capacity of the cache as input and initializes the head and tail of the linked list. The head and tail are dummy nodes that are not used to store any data.

// The addNode function adds a new node to the head->next of the linked list. The deleteNode function deletes a node from the linked list.

// The get function retrieves the item from the cache. If the item is not present in the cache, it returns -1. If the item is present in the cache, it moves the item to the head->next of the linked list and updates the hashmap with the new position of the item i.e head->next.

// The put function adds the item to the cache. If the item is already present in the cache, it deletes the item from the cache and adds the new item to the head->next of the linked list. If the cache is full, it deletes the least recently used item from the cache i.e tail->prev and adds the new item to the head->next of the linked list.