# 05. Query, Priority, Spatial, And Integrity Trees

## Segment Tree

A segment tree stores answers for intervals. It is used when an array changes and you still need fast range queries such as sum, min, max, gcd, or custom analytics.

### Required Operations

| Operation | Explanation | Cost |
| --- | --- | --- |
| Build | Recursively store answer for each interval | O(n) |
| Range query | Combine nodes fully inside query range | O(log n) for simple queries |
| Point update | Update one index and rebuild ancestors | O(log n) |
| Range update | Use lazy propagation to delay child updates | O(log n) |
| Push lazy | Applies pending update before going deeper | O(1) per visited node |

### C++ From Scratch: Range Sum With Lazy Add

```cpp
#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
    int n;
    vector<long long> tree, lazy;

    void build(int node, int l, int r, const vector<int>& a) {
        if (l == r) {
            tree[node] = a[l];
            return;
        }
        int mid = (l + r) / 2;
        build(node * 2, l, mid, a);
        build(node * 2 + 1, mid + 1, r, a);
        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }

    void apply(int node, int l, int r, long long add) {
        tree[node] += add * (r - l + 1);
        lazy[node] += add;
    }

    void push(int node, int l, int r) {
        if (lazy[node] == 0 || l == r) return;
        int mid = (l + r) / 2;
        apply(node * 2, l, mid, lazy[node]);
        apply(node * 2 + 1, mid + 1, r, lazy[node]);
        lazy[node] = 0;
    }

    long long query(int node, int l, int r, int ql, int qr) {
        if (qr < l || r < ql) return 0;
        if (ql <= l && r <= qr) return tree[node];
        push(node, l, r);
        int mid = (l + r) / 2;
        return query(node * 2, l, mid, ql, qr) +
               query(node * 2 + 1, mid + 1, r, ql, qr);
    }

    void update(int node, int l, int r, int ql, int qr, long long add) {
        if (qr < l || r < ql) return;
        if (ql <= l && r <= qr) {
            apply(node, l, r, add);
            return;
        }
        push(node, l, r);
        int mid = (l + r) / 2;
        update(node * 2, l, mid, ql, qr, add);
        update(node * 2 + 1, mid + 1, r, ql, qr, add);
        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }

public:
    SegmentTree(const vector<int>& a) {
        n = a.size();
        tree.assign(4 * n, 0);
        lazy.assign(4 * n, 0);
        build(1, 0, n - 1, a);
    }

    long long rangeSum(int l, int r) { return query(1, 0, n - 1, l, r); }
    void rangeAdd(int l, int r, long long add) { update(1, 0, n - 1, l, r, add); }
};
```

### Dry Run

Array: `[2, 1, 5, 3]`.

| Node interval | Sum |
| --- | --- |
| `[0,3]` | `11` |
| `[0,1]` | `3` |
| `[2,3]` | `8` |
| `[0,0]` | `2` |
| `[1,1]` | `1` |
| `[2,2]` | `5` |
| `[3,3]` | `3` |

Query `[1,3]` returns `[1,1] + [2,3] = 1 + 8 = 9`.

### Go Real-Life Example: Booking Capacity

```go
package main

import "fmt"

type Seg struct{ tree []int }

func NewSeg(a []int) *Seg {
    s := &Seg{tree: make([]int, 4*len(a))}
    var build func(int, int, int)
    build = func(node, l, r int) {
        if l == r {
            s.tree[node] = a[l]
            return
        }
        m := (l + r) / 2
        build(node*2, l, m)
        build(node*2+1, m+1, r)
        s.tree[node] = s.tree[node*2] + s.tree[node*2+1]
    }
    build(1, 0, len(a)-1)
    return s
}

func main() {
    seatsPerHour := []int{5, 3, 7, 2}
    seg := NewSeg(seatsPerHour)
    fmt.Println("total seats tracked:", seg.tree[1])
}
```

## Fenwick Tree / Binary Indexed Tree

A Fenwick tree stores partial prefix sums using the last set bit of an index. It is smaller and simpler than a segment tree when you only need prefix sums and point updates.

### Required Operations

| Operation | Explanation | Cost |
| --- | --- | --- |
| Add | Add delta to one index and all responsible buckets | O(log n) |
| Prefix sum | Move backward by last set bit | O(log n) |
| Range sum | `prefix(r) - prefix(l - 1)` | O(log n) |
| Build | Add each value, or use linear build | O(n log n) or O(n) |
| Lower bound | Find first prefix with sum >= target | O(log n) |

### C++ From Scratch

```cpp
#include <bits/stdc++.h>
using namespace std;

class Fenwick {
    int n;
    vector<long long> bit;

public:
    Fenwick(int n) : n(n), bit(n + 1, 0) {}

    void add(int index0, long long delta) {
        for (int i = index0 + 1; i <= n; i += i & -i) bit[i] += delta;
    }

    long long prefixSum(int index0) {
        long long ans = 0;
        for (int i = index0 + 1; i > 0; i -= i & -i) ans += bit[i];
        return ans;
    }

    long long rangeSum(int l, int r) {
        return prefixSum(r) - (l == 0 ? 0 : prefixSum(l - 1));
    }

    int lowerBound(long long target) {
        int idx = 0;
        int jump = 1;
        while (jump * 2 <= n) jump *= 2;

        for (; jump > 0; jump /= 2) {
            int next = idx + jump;
            if (next <= n && bit[next] < target) {
                idx = next;
                target -= bit[next];
            }
        }
        return idx; // zero-based index of first prefix >= original target
    }
};
```

### Dry Run

Array `[3, 2, 1, 6]`, using 1-based internal indexes.

| Add | Updated buckets |
| --- | --- |
| `add(0,3)` | `bit[1]`, `bit[2]`, `bit[4]` |
| `add(1,2)` | `bit[2]`, `bit[4]` |
| `add(2,1)` | `bit[3]`, `bit[4]` |
| `add(3,6)` | `bit[4]` |

`prefixSum(2)` reads `bit[3] + bit[2] = 1 + 5 = 6`.

### Go Real-Life Example: Live Ranking Counts

```go
package main

import "fmt"

type BIT []int

func (b BIT) Add(i, delta int) {
    for i++; i < len(b); i += i & -i {
        b[i] += delta
    }
}

func (b BIT) Sum(i int) int {
    total := 0
    for i++; i > 0; i -= i & -i {
        total += b[i]
    }
    return total
}

func main() {
    scores := make(BIT, 101)
    scores.Add(90, 1)
    scores.Add(75, 1)
    scores.Add(90, 1)
    fmt.Println("players with score <= 90:", scores.Sum(90))
}
```

## Heap

A heap is a complete binary tree stored in an array. A min-heap keeps the smallest element at the root. A max-heap keeps the largest element at the root.

### Required Operations

| Operation | Explanation | Cost |
| --- | --- | --- |
| Peek | Return root | O(1) |
| Push | Add at end, bubble up | O(log n) |
| Pop | Replace root with last, bubble down | O(log n) |
| Heapify | Build heap from array bottom-up | O(n) |
| Replace root | Pop and push in one operation | O(log n) |
| Top-K | Keep heap of size k | O(n log k) |

### C++ From Scratch: Min-Heap

```cpp
#include <bits/stdc++.h>
using namespace std;

class MinHeap {
    vector<int> a;

    void up(int i) {
        while (i > 0) {
            int p = (i - 1) / 2;
            if (a[p] <= a[i]) break;
            swap(a[p], a[i]);
            i = p;
        }
    }

    void down(int i) {
        int n = a.size();
        while (true) {
            int l = i * 2 + 1, r = i * 2 + 2, best = i;
            if (l < n && a[l] < a[best]) best = l;
            if (r < n && a[r] < a[best]) best = r;
            if (best == i) break;
            swap(a[i], a[best]);
            i = best;
        }
    }

public:
    void push(int x) {
        a.push_back(x);
        up(a.size() - 1);
    }

    int peek() { return a.front(); }

    int pop() {
        int ans = a.front();
        a[0] = a.back();
        a.pop_back();
        if (!a.empty()) down(0);
        return ans;
    }

    void heapify(vector<int> values) {
        a = move(values);
        for (int i = (int)a.size() / 2 - 1; i >= 0; i--) down(i);
    }
};
```

### Dry Run

Push `5, 2, 8, 1`.

| Step | Array heap |
| --- | --- |
| push 5 | `[5]` |
| push 2 | `[2, 5]` |
| push 8 | `[2, 5, 8]` |
| push 1 | `[1, 2, 8, 5]` |

Pop returns `1`, moves `5` to root, then bubbles it down to get `[2, 5, 8]`.

### Go Real-Life Example: Job Scheduling

```go
package main

import (
    "container/heap"
    "fmt"
)

type Job struct{ Name string; Priority int }
type PQ []Job

func (p PQ) Len() int { return len(p) }
func (p PQ) Less(i, j int) bool { return p[i].Priority < p[j].Priority }
func (p PQ) Swap(i, j int) { p[i], p[j] = p[j], p[i] }
func (p *PQ) Push(x any) { *p = append(*p, x.(Job)) }
func (p *PQ) Pop() any {
    old := *p
    x := old[len(old)-1]
    *p = old[:len(old)-1]
    return x
}

func main() {
    pq := &PQ{}
    heap.Push(pq, Job{"send-email", 2})
    heap.Push(pq, Job{"backup", 5})
    heap.Push(pq, Job{"alert", 1})
    fmt.Println(heap.Pop(pq).(Job))
}
```

## R-Tree

An R-Tree indexes rectangles. Each internal node stores bounding rectangles for child nodes. It is used by GIS systems, nearby search, geofencing, map queries, and spatial databases.

### Required Operations

| Operation | Explanation |
| --- | --- |
| Search | Visit child rectangles that intersect query rectangle |
| Insert | Choose child needing least bounding-box enlargement |
| Split | Divide overflowing entries into two nodes |
| Delete | Remove entry, condense underfull nodes |
| Nearest | Traverse promising rectangles first by distance |

### C++ From Scratch: Educational R-Tree Insert/Search

```cpp
#include <bits/stdc++.h>
using namespace std;

struct Rect {
    double minX, minY, maxX, maxY;
};

double area(Rect r) {
    return (r.maxX - r.minX) * (r.maxY - r.minY);
}

Rect combine(Rect a, Rect b) {
    return {min(a.minX, b.minX), min(a.minY, b.minY), max(a.maxX, b.maxX), max(a.maxY, b.maxY)};
}

bool intersects(Rect a, Rect b) {
    return !(a.maxX < b.minX || b.maxX < a.minX || a.maxY < b.minY || b.maxY < a.minY);
}

struct RNode;
struct Entry {
    Rect box;
    string id;
    RNode* child = nullptr;
};

struct RNode {
    bool leaf;
    vector<Entry> entries;
    RNode(bool isLeaf) : leaf(isLeaf) {}
};

Rect cover(RNode* n) {
    Rect ans = n->entries[0].box;
    for (auto& e : n->entries) ans = combine(ans, e.box);
    return ans;
}

RNode* splitNode(RNode* n) {
    sort(n->entries.begin(), n->entries.end(), [](const Entry& a, const Entry& b) {
        return a.box.minX < b.box.minX;
    });
    auto* sibling = new RNode(n->leaf);
    int mid = n->entries.size() / 2;
    sibling->entries.assign(n->entries.begin() + mid, n->entries.end());
    n->entries.erase(n->entries.begin() + mid, n->entries.end());
    return sibling;
}

RNode* insertRec(RNode* n, Rect box, const string& id, int maxEntries) {
    if (n->leaf) {
        n->entries.push_back({box, id, nullptr});
    } else {
        int best = 0;
        double bestGrow = 1e100;
        for (int i = 0; i < (int)n->entries.size(); i++) {
            double grow = area(combine(n->entries[i].box, box)) - area(n->entries[i].box);
            if (grow < bestGrow) bestGrow = grow, best = i;
        }
        RNode* sibling = insertRec(n->entries[best].child, box, id, maxEntries);
        n->entries[best].box = cover(n->entries[best].child);
        if (sibling) n->entries.push_back({cover(sibling), "", sibling});
    }
    if ((int)n->entries.size() > maxEntries) return splitNode(n);
    return nullptr;
}

RNode* insert(RNode* root, Rect box, const string& id, int maxEntries = 4) {
    RNode* sibling = insertRec(root, box, id, maxEntries);
    if (!sibling) return root;
    auto* newRoot = new RNode(false);
    newRoot->entries.push_back({cover(root), "", root});
    newRoot->entries.push_back({cover(sibling), "", sibling});
    return newRoot;
}

void search(RNode* n, Rect query, vector<string>& out) {
    for (auto& e : n->entries) {
        if (!intersects(e.box, query)) continue;
        if (n->leaf) out.push_back(e.id);
        else search(e.child, query, out);
    }
}
```

### Dry Run

Insert rectangles for shops `A, B, C, D, E` with max `4` entries per node.

| Step | Action |
| --- | --- |
| 1 | First four rectangles stay in one leaf |
| 2 | Fifth rectangle overflows the leaf |
| 3 | Split creates two leaves grouped by x-position |
| 4 | New root stores bounding boxes for both leaves |

Search visits only bounding boxes that intersect the query window.

### Go Real-Life Example: Geofence Query

```go
package main

import "fmt"

type Rect struct{ MinX, MinY, MaxX, MaxY float64 }
type Place struct{ Name string; Box Rect }

func Intersects(a, b Rect) bool {
    return !(a.MaxX < b.MinX || b.MaxX < a.MinX || a.MaxY < b.MinY || b.MaxY < a.MinY)
}

func Search(places []Place, q Rect) []string {
    var out []string
    for _, p := range places {
        if Intersects(p.Box, q) {
            out = append(out, p.Name)
        }
    }
    return out
}

func main() {
    places := []Place{{"school", Rect{0, 0, 2, 2}}, {"mall", Rect{5, 5, 8, 8}}}
    fmt.Println(Search(places, Rect{1, 1, 6, 6}))
}
```

## Merkle Tree

A Merkle tree hashes data blocks into leaves, then hashes pairs upward until one root hash remains. If one block changes, the root changes. It is used in blockchains, Git-like integrity checks, BitTorrent, replica sync, and tamper detection.

### Required Operations

| Operation | Explanation | Cost |
| --- | --- | --- |
| Build | Hash leaves, then hash pairs upward | O(n) |
| Root | Return top hash | O(1) after build |
| Proof | Collect sibling hash at each level | O(log n) |
| Verify | Recompute path from leaf to root | O(log n) |
| Update leaf | Recompute hashes on path to root | O(log n) |

### C++ From Scratch

```cpp
#include <bits/stdc++.h>
using namespace std;

string hashText(const string& s) {
    return to_string(hash<string>{}(s)); // Use SHA-256 in production.
}

class MerkleTree {
    vector<vector<string>> levels;

public:
    MerkleTree(const vector<string>& blocks) {
        vector<string> cur;
        for (auto& b : blocks) cur.push_back(hashText(b));
        levels.push_back(cur);

        while (cur.size() > 1) {
            if (cur.size() % 2 == 1) cur.push_back(cur.back());
            vector<string> next;
            for (int i = 0; i < (int)cur.size(); i += 2) {
                next.push_back(hashText(cur[i] + cur[i + 1]));
            }
            levels.push_back(next);
            cur = next;
        }
    }

    string root() const { return levels.back()[0]; }

    vector<pair<string, bool>> proof(int index) const {
        vector<pair<string, bool>> p; // bool is true when sibling is on the left
        for (int level = 0; level + 1 < (int)levels.size(); level++) {
            int sibling = index ^ 1;
            if (sibling >= (int)levels[level].size()) sibling = index;
            p.push_back({levels[level][sibling], sibling < index});
            index /= 2;
        }
        return p;
    }

    static bool verify(string block, int index, const vector<pair<string, bool>>& proof, const string& expectedRoot) {
        string cur = hashText(block);
        for (auto& [siblingHash, siblingLeft] : proof) {
            if (siblingLeft) cur = hashText(siblingHash + cur);
            else cur = hashText(cur + siblingHash);
            index /= 2;
        }
        return cur == expectedRoot;
    }
};
```

### Dry Run

Blocks: `A, B, C, D`.

```text
          H(H(A)+H(B) + H(C)+H(D))
             /                 \
       H(H(A)+H(B))       H(H(C)+H(D))
          /     \             /     \
       H(A)    H(B)        H(C)    H(D)
```

To prove `C`, send `H(D)` and `H(H(A)+H(B))`. The verifier rebuilds the root without downloading every block.

### Go Real-Life Example: File Chunk Verification

```go
package main

import (
    "crypto/sha256"
    "encoding/hex"
    "fmt"
)

func Hash(s string) string {
    h := sha256.Sum256([]byte(s))
    return hex.EncodeToString(h[:])
}

func MerkleRoot(blocks []string) string {
    var level []string
    for _, b := range blocks {
        level = append(level, Hash(b))
    }
    for len(level) > 1 {
        if len(level)%2 == 1 {
            level = append(level, level[len(level)-1])
        }
        var next []string
        for i := 0; i < len(level); i += 2 {
            next = append(next, Hash(level[i]+level[i+1]))
        }
        level = next
    }
    return level[0]
}

func main() {
    chunks := []string{"chunk-a", "chunk-b", "chunk-c"}
    fmt.Println(MerkleRoot(chunks))
}
```
