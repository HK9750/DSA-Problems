# Tree Data Structures From Scratch

This folder is a practical guide for the tree families listed in the request. The goal is to learn each tree in this order:

1. Understand what problem the tree solves.
2. Learn the core operations and why they work.
3. Dry run a small input by hand.
4. Read or type the C++ scratch implementation.
5. See how the same idea appears in real Go applications.

The C++ snippets are intentionally written from scratch and avoid library tree containers. The Go snippets focus on real-life usage patterns, not competitive-programming boilerplate.

## Chapters

| File | Trees covered | Main operations |
| --- | --- | --- |
| `01-binary-expression-decision.md` | Binary Tree, Expression Tree, Decision Tree | build, traverse, search, evaluate, classify |
| `02-search-balanced-trees.md` | Binary Search Tree, Unbalanced Tree, Balanced Tree, AVL Tree, Red-Black Tree | search, insert, delete, rotations, range query |
| `03-database-storage-trees.md` | B-Tree, B+ Tree, LSM Tree | block search, split, range scan, flush, compaction |
| `04-prefix-text-trees.md` | Trie, Radix Tree / Patricia Trie, Suffix Tree | prefix search, compressed edges, substring search |
| `05-query-priority-spatial-integrity.md` | Segment Tree, Fenwick Tree, Heap, R-Tree, Merkle Tree | range query, prefix sum, priority queue, spatial search, proofs |

## Quick Selection Guide

| Need | Use |
| --- | --- |
| Simple parent-child hierarchy | Binary Tree |
| Ordered keys with easy implementation | Binary Search Tree |
| Ordered keys with guaranteed height | AVL Tree or Red-Black Tree |
| Disk/page based index | B-Tree or B+ Tree |
| Heavy writes with background merge | LSM Tree |
| Prefix lookup | Trie or Radix Tree |
| Range sums/min/max with updates | Segment Tree |
| Prefix sums with point updates | Fenwick Tree |
| Always need min/max item | Heap |
| Rectangles, maps, geospatial data | R-Tree |
| Tamper proof data blocks | Merkle Tree |
| Fast substring queries | Suffix Tree |
| Human-readable rules or ML splits | Decision Tree |

## Common Tree Terms

| Term | Meaning |
| --- | --- |
| Root | Top node of the tree |
| Parent | Node directly above another node |
| Child | Node directly below another node |
| Leaf | Node with no children |
| Height | Longest downward path from a node to a leaf |
| Depth | Distance from root to a node |
| Balance | Keeping height small so operations stay fast |
| Rotation | Local pointer change used by self-balancing trees |

## Big-O Summary

| Tree | Search | Insert | Delete | Best use |
| --- | --- | --- | --- | --- |
| Binary Tree | O(n) | O(n) or O(1) with queue | O(n) | General hierarchy |
| BST unbalanced | O(h), worst O(n) | O(h), worst O(n) | O(h), worst O(n) | Learning and small data |
| AVL | O(log n) | O(log n) | O(log n) | Read-heavy ordered index |
| Red-Black | O(log n) | O(log n) | O(log n) | General ordered map/set |
| B-Tree | O(log n) page reads | O(log n) | O(log n) | Database/filesystem pages |
| B+ Tree | O(log n) page reads | O(log n) | O(log n) | Range scans and SQL indexes |
| LSM Tree | O(levels) | Amortized O(1) append | Tombstone + compaction | Write-heavy storage |
| Trie | O(length) | O(length) | O(length) | Prefix lookup |
| Radix Tree | O(length) | O(length) | O(length) | Compressed prefix lookup |
| Segment Tree | O(log n) | O(log n) | Not typical | Range query + updates |
| Fenwick Tree | O(log n) | O(log n) | Not typical | Prefix sums |
| Heap | O(n) contains | O(log n) push | O(log n) pop | Priority queue |
| R-Tree | Data-dependent | Data-dependent | Data-dependent | Spatial rectangles |
| Merkle Tree | O(log n) proof verify | Rebuild path | Rebuild path | Integrity checks |
| Suffix Tree | O(m) query after build | Build once | Not typical | Substring search |
| Decision Tree | O(depth) | Train/build offline | Retrain/prune | Classification rules |
| Expression Tree | O(n) evaluate | Build from tokens | Rebuild subtree | Expressions and ASTs |
