# 03. Database And Storage Trees

## B-Tree

A B-Tree keeps many keys per node. This reduces disk or page reads because each node can match a storage block. Databases, filesystems, embedded stores, and key-value engines use this idea.

For minimum degree `t`:

| Rule | Meaning |
| --- | --- |
| Max keys | `2t - 1` keys per node |
| Min keys | `t - 1` keys per non-root node |
| Children | A node with `k` keys has `k + 1` children |
| Sorted keys | Keys inside every node are sorted |
| Balanced height | All leaves are at the same depth |

### Required Operations

| Operation | Explanation | Cost |
| --- | --- | --- |
| Search | Binary/linear search inside node, then descend | O(log n) page levels |
| Insert | Split full child before descending | O(log n) |
| Split child | Move median key up into parent | O(t) |
| Delete leaf key | Remove directly after ensuring min keys | O(log n) |
| Delete internal key | Replace with predecessor/successor or merge children | O(log n) |
| Borrow | Move one key from sibling through parent | O(t) |
| Merge | Combine two small siblings and a parent separator | O(t) |
| Traverse | Inorder walk through keys and children | O(n) |

### C++ From Scratch: Search And Insert

```cpp
#include <bits/stdc++.h>
using namespace std;

struct BNode {
    bool leaf;
    vector<int> keys;
    vector<BNode*> child;
    BNode(bool isLeaf) : leaf(isLeaf) {}
};

class BTree {
    int t;
    BNode* root;

    bool search(BNode* x, int key) {
        int i = lower_bound(x->keys.begin(), x->keys.end(), key) - x->keys.begin();
        if (i < (int)x->keys.size() && x->keys[i] == key) return true;
        if (x->leaf) return false;
        return search(x->child[i], key);
    }

    void splitChild(BNode* parent, int i) {
        BNode* y = parent->child[i];
        BNode* z = new BNode(y->leaf);
        int median = y->keys[t - 1];

        for (int j = t; j < (int)y->keys.size(); j++) z->keys.push_back(y->keys[j]);
        y->keys.resize(t - 1);

        if (!y->leaf) {
            for (int j = t; j < (int)y->child.size(); j++) z->child.push_back(y->child[j]);
            y->child.resize(t);
        }

        parent->keys.insert(parent->keys.begin() + i, median);
        parent->child.insert(parent->child.begin() + i + 1, z);
    }

    void insertNonFull(BNode* x, int key) {
        int i = (int)x->keys.size() - 1;
        if (x->leaf) {
            x->keys.push_back(0);
            while (i >= 0 && key < x->keys[i]) {
                x->keys[i + 1] = x->keys[i];
                i--;
            }
            x->keys[i + 1] = key;
            return;
        }

        while (i >= 0 && key < x->keys[i]) i--;
        i++;
        if ((int)x->child[i]->keys.size() == 2 * t - 1) {
            splitChild(x, i);
            if (key > x->keys[i]) i++;
        }
        insertNonFull(x->child[i], key);
    }

    void traverse(BNode* x) {
        int i = 0;
        for (; i < (int)x->keys.size(); i++) {
            if (!x->leaf) traverse(x->child[i]);
            cout << x->keys[i] << ' ';
        }
        if (!x->leaf) traverse(x->child[i]);
    }

public:
    BTree(int minDegree) : t(minDegree), root(new BNode(true)) {}

    bool contains(int key) { return search(root, key); }

    void insert(int key) {
        if ((int)root->keys.size() == 2 * t - 1) {
            BNode* newRoot = new BNode(false);
            newRoot->child.push_back(root);
            splitChild(newRoot, 0);
            root = newRoot;
        }
        insertNonFull(root, key);
    }

    void printSorted() { traverse(root); }
};
```

### Delete Algorithm

Before descending into a child during deletion, make sure that child has at least `t` keys. If it only has `t - 1`, repair it first.

| Case | Fix |
| --- | --- |
| Key is in leaf | Remove it |
| Key is internal and left child has enough keys | Replace key with predecessor |
| Key is internal and right child has enough keys | Replace key with successor |
| Both children are minimum size | Merge them with the separator key, then recurse |
| Descending child is too small and sibling can lend | Borrow one key through parent |
| Descending child and siblings are too small | Merge child with a sibling |

### Dry Run: Split

Let `t = 2`, so a node can hold at most `3` keys. Insert `10, 20, 5, 6`.

| Step | Result |
| --- | --- |
| Insert 10 | root `[10]` |
| Insert 20 | root `[10, 20]` |
| Insert 5 | root `[5, 10, 20]`, now full |
| Insert 6 | root is split before insert; median `10` moves up |

Final shape:

```text
        [10]
       /    \
   [5,6]   [20]
```

### Go Real-Life Example: Page-Oriented Index Lookup

```go
package main

import "fmt"

type Page struct {
    Keys     []int
    Children []*Page
    Leaf     bool
}

func Search(p *Page, key int) bool {
    i := 0
    for i < len(p.Keys) && key > p.Keys[i] {
        i++
    }
    if i < len(p.Keys) && key == p.Keys[i] {
        return true
    }
    if p.Leaf {
        return false
    }
    return Search(p.Children[i], key)
}

func main() {
    root := &Page{
        Keys: []int{50},
        Children: []*Page{
            {Keys: []int{10, 20}, Leaf: true},
            {Keys: []int{70, 90}, Leaf: true},
        },
    }
    fmt.Println(Search(root, 70))
}
```

## B+ Tree

A B+ Tree is a B-Tree variant where all actual records live in leaf nodes. Internal nodes only guide search. Leaves are linked, which makes range scans fast.

### Required Operations

| Operation | Explanation | Cost |
| --- | --- | --- |
| Search | Descend internal separators to one leaf | O(log n) |
| Insert | Insert in leaf, split leaf if full, copy separator upward | O(log n) |
| Delete | Remove from leaf, borrow or merge if underfull | O(log n) |
| Range scan | Find first leaf, then follow leaf links | O(log n + k) |
| Pagination | Continue scan from last key or leaf pointer | O(log n + page size) |

### C++ From Scratch: Leaf Range Scan Model

```cpp
#include <bits/stdc++.h>
using namespace std;

struct BPlusLeaf {
    vector<int> keys;
    vector<string> values;
    BPlusLeaf* next = nullptr;
};

struct BPlusInternal {
    vector<int> sep;
    vector<BPlusLeaf*> child;
};

BPlusLeaf* findLeaf(BPlusInternal* root, int key) {
    int i = upper_bound(root->sep.begin(), root->sep.end(), key) - root->sep.begin();
    return root->child[i];
}

string search(BPlusInternal* root, int key) {
    BPlusLeaf* leaf = findLeaf(root, key);
    auto it = lower_bound(leaf->keys.begin(), leaf->keys.end(), key);
    if (it == leaf->keys.end() || *it != key) return "";
    int pos = it - leaf->keys.begin();
    return leaf->values[pos];
}

vector<string> rangeScan(BPlusInternal* root, int lo, int hi) {
    vector<string> out;
    BPlusLeaf* leaf = findLeaf(root, lo);
    while (leaf) {
        for (int i = 0; i < (int)leaf->keys.size(); i++) {
            if (leaf->keys[i] > hi) return out;
            if (leaf->keys[i] >= lo) out.push_back(leaf->values[i]);
        }
        leaf = leaf->next;
    }
    return out;
}
```

### Insert And Delete Notes

| Operation | Essential idea |
| --- | --- |
| Leaf split | Keep half the keys in old leaf, half in new leaf, link old to new |
| Separator update | Copy the first key of the new right leaf into parent |
| Internal split | Promote/copy separator upward when parent overflows |
| Delete underflow | Borrow from sibling if possible, otherwise merge leaves and remove parent separator |

### Dry Run: Range Scan

Leaves:

```text
[1, 4, 7] -> [10, 12, 15] -> [20, 25]
```

Query `[6, 16]`:

| Step | Action |
| --- | --- |
| 1 | Find leaf that could contain `6`: `[1, 4, 7]` |
| 2 | Read `7` |
| 3 | Follow `next` pointer to `[10, 12, 15]` |
| 4 | Read `10, 12, 15` |
| 5 | Next leaf begins with `20`, stop |

Output: `7, 10, 12, 15`.

### Go Real-Life Example: SQL-Like Pagination

```go
package main

import "fmt"

type Leaf struct {
    Keys []int
    Rows []string
    Next *Leaf
}

func PageFrom(start *Leaf, afterKey, limit int) []string {
    var rows []string
    for leaf := start; leaf != nil && len(rows) < limit; leaf = leaf.Next {
        for i, key := range leaf.Keys {
            if key > afterKey {
                rows = append(rows, leaf.Rows[i])
                if len(rows) == limit {
                    return rows
                }
            }
        }
    }
    return rows
}

func main() {
    a := &Leaf{Keys: []int{1, 4, 7}, Rows: []string{"r1", "r4", "r7"}}
    b := &Leaf{Keys: []int{10, 12}, Rows: []string{"r10", "r12"}}
    a.Next = b
    fmt.Println(PageFrom(a, 4, 3))
}
```

## LSM Tree

An LSM tree is built for write-heavy systems. Writes go to an in-memory sorted table first. When it fills, it is flushed to immutable sorted files. Background compaction merges files and removes overwritten values or tombstones.

### Required Operations

| Operation | Explanation |
| --- | --- |
| Put | Write key/value to memtable and append log |
| Get | Check memtable first, then newest SSTable to oldest |
| Delete | Write tombstone, do not immediately remove old data |
| Flush | Move sorted memtable into an immutable SSTable |
| Compact | Merge SSTables, keep newest version, drop tombstones |
| Range scan | Merge sorted iterators from memtable and SSTables |

### C++ From Scratch: Educational LSM

```cpp
#include <bits/stdc++.h>
using namespace std;

struct Entry {
    string value;
    bool deleted;
};

class MiniLSM {
    map<string, Entry> memtable;
    vector<map<string, Entry>> sstables; // newest table at the back
    int flushLimit;

public:
    MiniLSM(int limit = 4) : flushLimit(limit) {}

    void put(const string& key, const string& value) {
        memtable[key] = {value, false};
        if ((int)memtable.size() >= flushLimit) flush();
    }

    void remove(const string& key) {
        memtable[key] = {"", true};
        if ((int)memtable.size() >= flushLimit) flush();
    }

    optional<string> get(const string& key) {
        if (memtable.count(key)) {
            if (memtable[key].deleted) return nullopt;
            return memtable[key].value;
        }

        for (int i = (int)sstables.size() - 1; i >= 0; i--) {
            auto it = sstables[i].find(key);
            if (it == sstables[i].end()) continue;
            if (it->second.deleted) return nullopt;
            return it->second.value;
        }
        return nullopt;
    }

    void flush() {
        if (memtable.empty()) return;
        sstables.push_back(memtable);
        memtable.clear();
    }

    void compact() {
        map<string, Entry> merged;
        for (auto& table : sstables) {
            for (auto& [key, entry] : table) merged[key] = entry;
        }

        for (auto it = merged.begin(); it != merged.end(); ) {
            if (it->second.deleted) it = merged.erase(it);
            else ++it;
        }

        sstables.clear();
        if (!merged.empty()) sstables.push_back(merged);
    }
};
```

### Dry Run

Flush limit is `3`.

| Step | Operation | State |
| --- | --- | --- |
| 1 | `put(a,1)` | memtable has `a` |
| 2 | `put(b,2)` | memtable has `a,b` |
| 3 | `put(c,3)` | memtable flushes to SSTable-1 |
| 4 | `put(a,9)` | new value in memtable shadows old `a` |
| 5 | `get(a)` | returns `9` from memtable |
| 6 | `remove(a)` then flush | tombstone shadows both old values |
| 7 | compact | old `a` values and tombstone are removed |

### Go Real-Life Example: Log Ingestion Buffer

```go
package main

import "fmt"

type Entry struct {
    Value   string
    Deleted bool
}

type LSM struct {
    Mem      map[string]Entry
    SSTables []map[string]Entry
    Limit    int
}

func (l *LSM) Put(k, v string) {
    if l.Mem == nil {
        l.Mem = map[string]Entry{}
    }
    l.Mem[k] = Entry{Value: v}
    if len(l.Mem) >= l.Limit {
        l.Flush()
    }
}

func (l *LSM) Get(k string) (string, bool) {
    if e, ok := l.Mem[k]; ok {
        return e.Value, !e.Deleted
    }
    for i := len(l.SSTables) - 1; i >= 0; i-- {
        if e, ok := l.SSTables[i][k]; ok {
            return e.Value, !e.Deleted
        }
    }
    return "", false
}

func (l *LSM) Flush() {
    frozen := map[string]Entry{}
    for k, v := range l.Mem {
        frozen[k] = v
    }
    l.SSTables = append(l.SSTables, frozen)
    l.Mem = map[string]Entry{}
}

func main() {
    db := &LSM{Limit: 2}
    db.Put("log:1", "started")
    db.Put("log:2", "finished")
    v, ok := db.Get("log:1")
    fmt.Println(v, ok)
}
```
