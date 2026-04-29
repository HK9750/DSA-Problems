# 02. Search And Balanced Trees

## Binary Search Tree

A binary search tree stores ordered keys using this invariant: every key in the left subtree is smaller than the node, and every key in the right subtree is larger.

### Required Operations

| Operation | Explanation | Cost |
| --- | --- | --- |
| Search | Compare and move left or right | O(h) |
| Insert | Search until an empty child position is found | O(h) |
| Delete leaf | Remove directly | O(h) |
| Delete one child | Replace node with its child | O(h) |
| Delete two children | Replace with inorder successor or predecessor | O(h) |
| Min/Max | Keep moving left/right | O(h) |
| Inorder traversal | Emits sorted keys | O(n) |
| Range query | Prune branches outside `[lo, hi]` | O(k + h) |

### C++ From Scratch

```cpp
#include <bits/stdc++.h>
using namespace std;

struct BSTNode {
    int key;
    BSTNode *left, *right;
    BSTNode(int k) : key(k), left(nullptr), right(nullptr) {}
};

BSTNode* insert(BSTNode* root, int key) {
    if (!root) return new BSTNode(key);
    if (key < root->key) root->left = insert(root->left, key);
    else if (key > root->key) root->right = insert(root->right, key);
    return root;
}

bool search(BSTNode* root, int key) {
    if (!root) return false;
    if (root->key == key) return true;
    if (key < root->key) return search(root->left, key);
    return search(root->right, key);
}

BSTNode* minNode(BSTNode* root) {
    while (root && root->left) root = root->left;
    return root;
}

BSTNode* erase(BSTNode* root, int key) {
    if (!root) return nullptr;

    if (key < root->key) root->left = erase(root->left, key);
    else if (key > root->key) root->right = erase(root->right, key);
    else {
        if (!root->left) {
            BSTNode* child = root->right;
            delete root;
            return child;
        }
        if (!root->right) {
            BSTNode* child = root->left;
            delete root;
            return child;
        }

        BSTNode* successor = minNode(root->right);
        root->key = successor->key;
        root->right = erase(root->right, successor->key);
    }
    return root;
}

void inorder(BSTNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->key << ' ';
    inorder(root->right);
}

void rangeQuery(BSTNode* root, int lo, int hi, vector<int>& out) {
    if (!root) return;
    if (root->key > lo) rangeQuery(root->left, lo, hi, out);
    if (lo <= root->key && root->key <= hi) out.push_back(root->key);
    if (root->key < hi) rangeQuery(root->right, lo, hi, out);
}

BSTNode* lowerBound(BSTNode* root, int key) {
    BSTNode* ans = nullptr;
    while (root) {
        if (root->key >= key) {
            ans = root;
            root = root->left;
        } else {
            root = root->right;
        }
    }
    return ans;
}
```

### Dry Run

Insert `50, 30, 70, 20, 40, 60, 80`.

```text
        50
       /  \
     30    70
    / \    / \
  20  40  60  80
```

Delete `30`:

| Step | Action |
| --- | --- |
| 1 | Find node `30` |
| 2 | It has two children |
| 3 | Inorder successor is minimum of right subtree: `40` |
| 4 | Copy `40` into node `30` |
| 5 | Delete original `40` leaf |

Inorder after delete: `20 40 50 60 70 80`.

### Go Real-Life Example: Product Price Range Query

```go
package main

import "fmt"

type ProductNode struct {
    Price int
    SKU   string
    Left  *ProductNode
    Right *ProductNode
}

func Insert(root *ProductNode, price int, sku string) *ProductNode {
    if root == nil {
        return &ProductNode{Price: price, SKU: sku}
    }
    if price < root.Price {
        root.Left = Insert(root.Left, price, sku)
    } else {
        root.Right = Insert(root.Right, price, sku)
    }
    return root
}

func Range(root *ProductNode, lo, hi int, out *[]string) {
    if root == nil {
        return
    }
    if root.Price > lo {
        Range(root.Left, lo, hi, out)
    }
    if lo <= root.Price && root.Price <= hi {
        *out = append(*out, root.SKU)
    }
    if root.Price < hi {
        Range(root.Right, lo, hi, out)
    }
}

func main() {
    var root *ProductNode
    root = Insert(root, 120, "keyboard")
    root = Insert(root, 80, "mouse")
    root = Insert(root, 200, "monitor")

    var matches []string
    Range(root, 50, 150, &matches)
    fmt.Println(matches)
}
```

## Unbalanced Tree

An unbalanced tree is usually a plain BST with no rotations. It is useful for learning, small datasets, temporary indexes, or random-ish inserts. It is risky for production because sorted input creates height `n`.

### Required Operations

The operations are the same as BST: search, insert, delete, min, max, inorder, and range query. The difference is that no operation repairs height.

### Dry Run: Worst Case

Insert `1, 2, 3, 4, 5` into a plain BST.

```text
1
 \
  2
   \
    3
     \
      4
       \
        5
```

Searching for `5` now takes 5 comparisons, so the BST behaves like a linked list.

### Go Real-Life Example: Small Temporary Index

```go
package main

import "fmt"

type Node struct {
    Key   int
    Value string
    Left  *Node
    Right *Node
}

func Put(n *Node, key int, value string) *Node {
    if n == nil {
        return &Node{Key: key, Value: value}
    }
    if key < n.Key {
        n.Left = Put(n.Left, key, value)
    } else if key > n.Key {
        n.Right = Put(n.Right, key, value)
    } else {
        n.Value = value
    }
    return n
}

func main() {
    var tmp *Node
    for id, name := range map[int]string{3: "c", 1: "a", 2: "b"} {
        tmp = Put(tmp, id, name)
    }
    fmt.Println(tmp.Key)
}
```

## Balanced Tree

Balanced tree is a category, not one exact implementation. AVL and Red-Black trees are balanced BSTs. The goal is to keep height near `log n`.

### Required Operations

| Operation | Explanation |
| --- | --- |
| Search | Same as BST |
| Insert | BST insert, then rebalance ancestors |
| Delete | BST delete, then rebalance ancestors |
| Rotate left | Fixes a right-heavy local shape |
| Rotate right | Fixes a left-heavy local shape |
| Range query | Same sorted traversal as BST |

### Rotation Code

```cpp
struct TNode {
    int key;
    TNode *left, *right;
};

TNode* rotateRight(TNode* y) {
    TNode* x = y->left;
    TNode* moved = x->right;
    x->right = y;
    y->left = moved;
    return x;
}

TNode* rotateLeft(TNode* x) {
    TNode* y = x->right;
    TNode* moved = y->left;
    y->left = x;
    x->right = moved;
    return y;
}
```

### Dry Run: Right Rotation

Before inserting into a balanced tree, the local shape becomes left-heavy:

```text
    30
   /
  20
 /
10
```

Right rotate at `30`:

```text
   20
  /  \
10    30
```

The inorder order stays `10, 20, 30`, but the height improves.

### Go Real-Life Example: Sorted In-Memory Index API

```go
package main

import (
    "fmt"
    "sort"
)

type SortedIndex struct {
    Keys []int
    Data map[int]string
}

func (s *SortedIndex) Put(key int, value string) {
    if s.Data == nil {
        s.Data = map[int]string{}
    }
    i := sort.SearchInts(s.Keys, key)
    if i == len(s.Keys) || s.Keys[i] != key {
        s.Keys = append(s.Keys, 0)
        copy(s.Keys[i+1:], s.Keys[i:])
        s.Keys[i] = key
    }
    s.Data[key] = value
}

func (s *SortedIndex) Range(lo, hi int) []string {
    i := sort.SearchInts(s.Keys, lo)
    var out []string
    for i < len(s.Keys) && s.Keys[i] <= hi {
        out = append(out, s.Data[s.Keys[i]])
        i++
    }
    return out
}

func main() {
    idx := &SortedIndex{}
    idx.Put(10, "small")
    idx.Put(30, "large")
    idx.Put(20, "medium")
    fmt.Println(idx.Range(10, 25))
}
```

## AVL Tree

AVL trees keep the balance factor of every node between `-1` and `1`. Balance factor is `height(left) - height(right)`. AVL is stricter than Red-Black, so lookups are very fast.

### Required Operations

| Operation | Explanation | Cost |
| --- | --- | --- |
| Search | BST search | O(log n) |
| Insert | BST insert, update height, rotate if needed | O(log n) |
| Delete | BST delete, update height, rotate if needed | O(log n) |
| LL rotation | Right rotate | O(1) |
| RR rotation | Left rotate | O(1) |
| LR rotation | Left rotate child, then right rotate | O(1) |
| RL rotation | Right rotate child, then left rotate | O(1) |

### C++ From Scratch

```cpp
#include <bits/stdc++.h>
using namespace std;

struct AVLNode {
    int key, h;
    AVLNode *left, *right;
    AVLNode(int k) : key(k), h(1), left(nullptr), right(nullptr) {}
};

int ht(AVLNode* n) { return n ? n->h : 0; }
int bal(AVLNode* n) { return n ? ht(n->left) - ht(n->right) : 0; }

void pull(AVLNode* n) {
    n->h = 1 + max(ht(n->left), ht(n->right));
}

AVLNode* rotateRight(AVLNode* y) {
    AVLNode* x = y->left;
    AVLNode* moved = x->right;
    x->right = y;
    y->left = moved;
    pull(y);
    pull(x);
    return x;
}

AVLNode* rotateLeft(AVLNode* x) {
    AVLNode* y = x->right;
    AVLNode* moved = y->left;
    y->left = x;
    x->right = moved;
    pull(x);
    pull(y);
    return y;
}

AVLNode* rebalance(AVLNode* root) {
    pull(root);
    int b = bal(root);

    if (b > 1) {
        if (bal(root->left) < 0) root->left = rotateLeft(root->left);
        return rotateRight(root);
    }
    if (b < -1) {
        if (bal(root->right) > 0) root->right = rotateRight(root->right);
        return rotateLeft(root);
    }
    return root;
}

AVLNode* insert(AVLNode* root, int key) {
    if (!root) return new AVLNode(key);
    if (key < root->key) root->left = insert(root->left, key);
    else if (key > root->key) root->right = insert(root->right, key);
    else return root;
    return rebalance(root);
}

AVLNode* minNode(AVLNode* root) {
    while (root->left) root = root->left;
    return root;
}

AVLNode* erase(AVLNode* root, int key) {
    if (!root) return nullptr;

    if (key < root->key) root->left = erase(root->left, key);
    else if (key > root->key) root->right = erase(root->right, key);
    else {
        if (!root->left || !root->right) {
            AVLNode* child = root->left ? root->left : root->right;
            delete root;
            return child;
        }

        AVLNode* successor = minNode(root->right);
        root->key = successor->key;
        root->right = erase(root->right, successor->key);
    }
    return rebalance(root);
}

bool contains(AVLNode* root, int key) {
    while (root) {
        if (key == root->key) return true;
        root = key < root->key ? root->left : root->right;
    }
    return false;
}
```

### Dry Run: LL Case

Insert `30, 20, 10`.

| Step | Tree issue | Fix |
| --- | --- | --- |
| Insert 30 | balanced | none |
| Insert 20 | balance of 30 is `1` | none |
| Insert 10 | balance of 30 is `2` | right rotate at 30 |

Final tree is `20` root with `10` left and `30` right.

### Go Real-Life Example: Low-Latency Routing Table Shape

```go
package main

import "fmt"

type Route struct {
    Prefix string
    NextHop string
}

// In production this would be backed by an AVL or radix tree.
// The caller sees stable ordered lookup behavior.
func Lookup(routes []Route, prefix string) (string, bool) {
    for _, r := range routes {
        if r.Prefix == prefix {
            return r.NextHop, true
        }
    }
    return "", false
}

func main() {
    routes := []Route{{"10.0.0.0/8", "gw-a"}, {"10.2.0.0/16", "gw-b"}}
    hop, ok := Lookup(routes, "10.2.0.0/16")
    fmt.Println(hop, ok)
}
```

## Red-Black Tree

Red-Black trees keep height logarithmic using node colors. They are less strict than AVL, so they often perform fewer rotations on insert/delete. Java `TreeMap`, C++ `std::map`, and many kernel structures use this family.

This implementation uses a left-leaning red-black tree. It is a simpler red-black variant with the same practical guarantee: no path is more than about twice as long as another.

### Required Operations

| Operation | Explanation | Cost |
| --- | --- | --- |
| Search | Same as BST | O(log n) |
| Insert | Insert red node, rotate/flip colors | O(log n) |
| Delete min | Move red link down, remove leaf, fix up | O(log n) |
| Delete key | Convert to delete-min problem when needed | O(log n) |
| Rotate left/right | Repairs leaning and consecutive red links | O(1) |
| Color flip | Splits or merges temporary 4-nodes | O(1) |

### C++ From Scratch

```cpp
#include <bits/stdc++.h>
using namespace std;

const bool RED = true;
const bool BLACK = false;

struct RBNode {
    int key;
    bool red;
    RBNode *left, *right;
    RBNode(int k) : key(k), red(RED), left(nullptr), right(nullptr) {}
};

bool isRed(RBNode* n) { return n && n->red == RED; }

RBNode* rotateLeft(RBNode* h) {
    RBNode* x = h->right;
    h->right = x->left;
    x->left = h;
    x->red = h->red;
    h->red = RED;
    return x;
}

RBNode* rotateRight(RBNode* h) {
    RBNode* x = h->left;
    h->left = x->right;
    x->right = h;
    x->red = h->red;
    h->red = RED;
    return x;
}

void flipColors(RBNode* h) {
    h->red = !h->red;
    if (h->left) h->left->red = !h->left->red;
    if (h->right) h->right->red = !h->right->red;
}

RBNode* fixUp(RBNode* h) {
    if (isRed(h->right) && !isRed(h->left)) h = rotateLeft(h);
    if (isRed(h->left) && isRed(h->left->left)) h = rotateRight(h);
    if (isRed(h->left) && isRed(h->right)) flipColors(h);
    return h;
}

RBNode* put(RBNode* h, int key) {
    if (!h) return new RBNode(key);
    if (key < h->key) h->left = put(h->left, key);
    else if (key > h->key) h->right = put(h->right, key);
    return fixUp(h);
}

RBNode* insert(RBNode* root, int key) {
    root = put(root, key);
    root->red = BLACK;
    return root;
}

RBNode* minNode(RBNode* h) {
    while (h->left) h = h->left;
    return h;
}

RBNode* moveRedLeft(RBNode* h) {
    flipColors(h);
    if (h->right && isRed(h->right->left)) {
        h->right = rotateRight(h->right);
        h = rotateLeft(h);
        flipColors(h);
    }
    return h;
}

RBNode* moveRedRight(RBNode* h) {
    flipColors(h);
    if (h->left && isRed(h->left->left)) {
        h = rotateRight(h);
        flipColors(h);
    }
    return h;
}

RBNode* deleteMin(RBNode* h) {
    if (!h->left) {
        delete h;
        return nullptr;
    }
    if (!isRed(h->left) && !isRed(h->left->left)) h = moveRedLeft(h);
    h->left = deleteMin(h->left);
    return fixUp(h);
}

RBNode* eraseNode(RBNode* h, int key) {
    if (!h) return nullptr;

    if (key < h->key) {
        if (h->left && !isRed(h->left) && !isRed(h->left->left)) h = moveRedLeft(h);
        h->left = eraseNode(h->left, key);
    } else {
        if (isRed(h->left)) h = rotateRight(h);
        if (key == h->key && !h->right) {
            delete h;
            return nullptr;
        }
        if (h->right && !isRed(h->right) && !isRed(h->right->left)) h = moveRedRight(h);
        if (key == h->key) {
            RBNode* x = minNode(h->right);
            h->key = x->key;
            h->right = deleteMin(h->right);
        } else {
            h->right = eraseNode(h->right, key);
        }
    }
    return fixUp(h);
}

RBNode* erase(RBNode* root, int key) {
    root = eraseNode(root, key);
    if (root) root->red = BLACK;
    return root;
}

bool contains(RBNode* root, int key) {
    while (root) {
        if (key == root->key) return true;
        root = key < root->key ? root->left : root->right;
    }
    return false;
}
```

### Dry Run

Insert `10, 20, 30` into a left-leaning red-black tree.

| Step | Local issue | Fix |
| --- | --- | --- |
| Insert 10 | root is red | recolor root black |
| Insert 20 | red link leans right | rotate left at 10 |
| Insert 30 | both children red under 20 | flip colors, root black |

The final logical tree has `20` as black root with `10` and `30` below it.

### Go Real-Life Example: Scheduler Ordered By Deadline

```go
package main

import (
    "fmt"
    "sort"
)

type Job struct {
    ID       string
    Deadline int
}

func NextJob(jobs []Job) Job {
    sort.Slice(jobs, func(i, j int) bool {
        return jobs[i].Deadline < jobs[j].Deadline
    })
    return jobs[0]
}

func main() {
    jobs := []Job{{"backup", 30}, {"email", 10}, {"report", 20}}
    fmt.Println(NextJob(jobs))
}
```
