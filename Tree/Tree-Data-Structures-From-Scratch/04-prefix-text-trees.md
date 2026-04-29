# 04. Prefix And Text Trees

## Trie / Prefix Tree

A trie stores one character per edge. It is excellent when the query is based on a string prefix: autocomplete, dictionaries, spell checking, contact search, and command lookup.

### Required Operations

| Operation | Explanation | Cost |
| --- | --- | --- |
| Insert word | Walk/create one node per character | O(L) |
| Search word | Walk characters and check terminal flag | O(L) |
| StartsWith | Walk prefix only | O(P) |
| Delete word | Unmark terminal and remove unused nodes | O(L) |
| Autocomplete | Find prefix node, DFS below it | O(P + output) |
| Count prefix | Store pass count on nodes | O(P) |

### C++ From Scratch

```cpp
#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
    array<TrieNode*, 26> next{};
    bool word = false;
    int pass = 0;
};

class Trie {
    TrieNode* root = new TrieNode();

    bool erase(TrieNode* node, const string& s, int i) {
        if (!node) return false;
        if (i == (int)s.size()) {
            if (!node->word) return false;
            node->word = false;
            node->pass--;
        } else {
            int c = s[i] - 'a';
            if (!erase(node->next[c], s, i + 1)) return false;
            node->pass--;
            if (node->next[c]->pass == 0) {
                delete node->next[c];
                node->next[c] = nullptr;
            }
        }
        return true;
    }

    void collect(TrieNode* node, string& path, vector<string>& out) {
        if (!node) return;
        if (node->word) out.push_back(path);
        for (int i = 0; i < 26; i++) {
            if (!node->next[i]) continue;
            path.push_back(char('a' + i));
            collect(node->next[i], path, out);
            path.pop_back();
        }
    }

public:
    void insert(const string& s) {
        TrieNode* cur = root;
        cur->pass++;
        for (char ch : s) {
            int c = ch - 'a';
            if (!cur->next[c]) cur->next[c] = new TrieNode();
            cur = cur->next[c];
            cur->pass++;
        }
        cur->word = true;
    }

    bool search(const string& s) {
        TrieNode* cur = root;
        for (char ch : s) {
            int c = ch - 'a';
            if (!cur->next[c]) return false;
            cur = cur->next[c];
        }
        return cur->word;
    }

    bool startsWith(const string& p) {
        TrieNode* cur = root;
        for (char ch : p) {
            int c = ch - 'a';
            if (!cur->next[c]) return false;
            cur = cur->next[c];
        }
        return true;
    }

    bool remove(const string& s) { return erase(root, s, 0); }

    vector<string> autocomplete(const string& p) {
        TrieNode* cur = root;
        for (char ch : p) {
            int c = ch - 'a';
            if (!cur->next[c]) return {};
            cur = cur->next[c];
        }
        vector<string> out;
        string path = p;
        collect(cur, path, out);
        return out;
    }
};
```

### Dry Run

Insert `car`, `cat`, `dog`.

```text
root
+-- c -> a -> r(word)
|         \
|          t(word)
+-- d -> o -> g(word)
```

Search `can` fails at `n`. Prefix `ca` succeeds because the path exists. Autocomplete `ca` returns `car, cat`.

### Go Real-Life Example: Contact Search

```go
package main

import "fmt"

type Trie struct {
    Children map[rune]*Trie
    Word     string
}

func NewTrie() *Trie { return &Trie{Children: map[rune]*Trie{}} }

func (t *Trie) Insert(word string) {
    cur := t
    for _, ch := range word {
        if cur.Children[ch] == nil {
            cur.Children[ch] = NewTrie()
        }
        cur = cur.Children[ch]
    }
    cur.Word = word
}

func (t *Trie) Collect(prefix string) []string {
    cur := t
    for _, ch := range prefix {
        if cur.Children[ch] == nil {
            return nil
        }
        cur = cur.Children[ch]
    }
    var out []string
    var dfs func(*Trie)
    dfs = func(n *Trie) {
        if n.Word != "" {
            out = append(out, n.Word)
        }
        for _, child := range n.Children {
            dfs(child)
        }
    }
    dfs(cur)
    return out
}

func main() {
    contacts := NewTrie()
    contacts.Insert("hassan")
    contacts.Insert("hasnain")
    contacts.Insert("hamza")
    fmt.Println(contacts.Collect("has"))
}
```

## Radix Tree / Patricia Trie

A radix tree compresses chains of single-child trie nodes into one edge label. Patricia trie is a common compressed trie form. It saves memory and is used in IP routing, URL routing, Redis internals, and compressed prefix indexes.

### Required Operations

| Operation | Explanation | Cost |
| --- | --- | --- |
| Insert | Find common prefix, split edge if needed | O(L) |
| Exact search | Match compressed edge labels | O(L) |
| Longest prefix match | Keep last terminal node seen while walking | O(L) |
| Delete | Unmark terminal, merge node if it has one child | O(L) |
| Prefix list | Find prefix boundary, collect descendants | O(P + output) |

### C++ From Scratch

```cpp
#include <bits/stdc++.h>
using namespace std;

struct RadixNode;
struct Edge {
    string label;
    RadixNode* child;
};

struct RadixNode {
    bool word = false;
    unordered_map<char, Edge> edges;
};

int lcp(const string& a, int ai, const string& b) {
    int k = 0;
    while (ai + k < (int)a.size() && k < (int)b.size() && a[ai + k] == b[k]) k++;
    return k;
}

void insert(RadixNode* root, const string& s) {
    RadixNode* cur = root;
    int i = 0;
    while (i < (int)s.size()) {
        char c = s[i];
        if (!cur->edges.count(c)) {
            cur->edges[c] = {s.substr(i), new RadixNode()};
            cur->edges[c].child->word = true;
            return;
        }

        Edge& e = cur->edges[c];
        int k = lcp(s, i, e.label);
        if (k == (int)e.label.size()) {
            cur = e.child;
            i += k;
            continue;
        }

        RadixNode* mid = new RadixNode();
        string oldRest = e.label.substr(k);
        mid->edges[oldRest[0]] = {oldRest, e.child};

        string newRest = s.substr(i + k);
        if (newRest.empty()) {
            mid->word = true;
        } else {
            mid->edges[newRest[0]] = {newRest, new RadixNode()};
            mid->edges[newRest[0]].child->word = true;
        }

        e.label = e.label.substr(0, k);
        e.child = mid;
        return;
    }
    cur->word = true;
}

bool search(RadixNode* root, const string& s) {
    RadixNode* cur = root;
    int i = 0;
    while (i < (int)s.size()) {
        char c = s[i];
        if (!cur->edges.count(c)) return false;
        Edge& e = cur->edges[c];
        if (s.compare(i, e.label.size(), e.label) != 0) return false;
        i += e.label.size();
        cur = e.child;
    }
    return cur->word;
}
```

### Dry Run

Insert `romane`, then `romanus`.

| Step | Action |
| --- | --- |
| 1 | `romane` creates one compressed edge `romane` |
| 2 | `romanus` shares prefix `roman` with `romane` |
| 3 | Split edge into `roman`, then children `e` and `us` |

Compressed shape:

```text
root -> "roman" -> "e"(word)
                 -> "us"(word)
```

### Go Real-Life Example: URL Router

```go
package main

import "fmt"

type Route struct {
    Prefix  string
    Handler string
}

func LongestPrefix(routes []Route, path string) string {
    best := ""
    for _, r := range routes {
        if len(r.Prefix) <= len(path) && path[:len(r.Prefix)] == r.Prefix {
            if len(r.Prefix) > len(best) {
                best = r.Handler
            }
        }
    }
    return best
}

func main() {
    routes := []Route{{"/api/", "api"}, {"/api/users/", "users"}, {"/assets/", "static"}}
    fmt.Println(LongestPrefix(routes, "/api/users/42"))
}
```

## Suffix Tree

A suffix tree is a compressed trie of all suffixes of a string. After building it, substring search is fast because every substring is a prefix of some suffix. It is used in DNA matching, text indexing, plagiarism detection, and compression.

The optimal algorithm is Ukkonen's algorithm with O(n) build time. The scratch version below is the clearer learning version: insert every suffix into a compressed trie. Build is O(n^2), but search demonstrates the same suffix-tree idea.

### Required Operations

| Operation | Explanation | Cost in scratch version |
| --- | --- | --- |
| Build | Insert every suffix into compressed trie | O(n^2) |
| Search substring | Walk compressed edges by pattern | O(m) after traversal comparisons |
| Edge split | Split at first mismatch | O(edge length) |
| Longest repeated substring | Find deepest internal node with multiple leaves | O(n) traversal after build |
| Pattern positions | Store suffix start indexes in leaves | O(m + output) |

### C++ From Scratch: Naive Compressed Suffix Tree

```cpp
#include <bits/stdc++.h>
using namespace std;

struct SuffixNode;
struct SuffixEdge {
    string label;
    SuffixNode* child;
};

struct SuffixNode {
    bool terminal = false;
    vector<int> suffixStarts;
    unordered_map<char, SuffixEdge> edges;
};

int commonPrefix(const string& s, int i, const string& label) {
    int k = 0;
    while (i + k < (int)s.size() && k < (int)label.size() && s[i + k] == label[k]) k++;
    return k;
}

void insertSuffix(SuffixNode* root, const string& text, int start) {
    SuffixNode* cur = root;
    int i = start;
    while (i < (int)text.size()) {
        char c = text[i];
        if (!cur->edges.count(c)) {
            auto* leaf = new SuffixNode();
            leaf->terminal = true;
            leaf->suffixStarts.push_back(start);
            cur->edges[c] = {text.substr(i), leaf};
            return;
        }

        SuffixEdge& e = cur->edges[c];
        int k = commonPrefix(text, i, e.label);
        if (k == (int)e.label.size()) {
            cur = e.child;
            i += k;
            continue;
        }

        auto* mid = new SuffixNode();
        string oldRest = e.label.substr(k);
        mid->edges[oldRest[0]] = {oldRest, e.child};

        string newRest = text.substr(i + k);
        if (newRest.empty()) {
            mid->terminal = true;
            mid->suffixStarts.push_back(start);
        } else {
            auto* leaf = new SuffixNode();
            leaf->terminal = true;
            leaf->suffixStarts.push_back(start);
            mid->edges[newRest[0]] = {newRest, leaf};
        }

        e.label = e.label.substr(0, k);
        e.child = mid;
        return;
    }
    cur->terminal = true;
    cur->suffixStarts.push_back(start);
}

SuffixNode* buildSuffixTree(const string& text) {
    auto* root = new SuffixNode();
    for (int i = 0; i < (int)text.size(); i++) insertSuffix(root, text, i);
    return root;
}

bool contains(SuffixNode* root, const string& pattern) {
    SuffixNode* cur = root;
    int i = 0;
    while (i < (int)pattern.size()) {
        char c = pattern[i];
        if (!cur->edges.count(c)) return false;
        SuffixEdge& e = cur->edges[c];

        int j = 0;
        while (j < (int)e.label.size() && i + j < (int)pattern.size()) {
            if (e.label[j] != pattern[i + j]) return false;
            j++;
        }
        i += j;
        if (i == (int)pattern.size()) return true;
        cur = e.child;
    }
    return true;
}
```

### Dry Run

Text: `banana$`. Suffixes inserted:

```text
banana$
anana$
nana$
ana$
na$
a$
$
```

Search pattern `ana`:

| Step | Action |
| --- | --- |
| 1 | Start at root with `a` |
| 2 | Follow compressed edge beginning with `a` |
| 3 | Match `a`, then `n`, then `a` |
| 4 | Pattern is fully consumed, so `ana` exists |

### Go Real-Life Example: DNA Substring Lookup

```go
package main

import "fmt"

type SuffixIndex struct {
    Text string
}

func (s SuffixIndex) Contains(pattern string) bool {
    for i := 0; i+len(pattern) <= len(s.Text); i++ {
        if s.Text[i:i+len(pattern)] == pattern {
            return true
        }
    }
    return false
}

func main() {
    genome := SuffixIndex{Text: "ACGTCGACGTT"}
    fmt.Println(genome.Contains("CGAC"))
}
```
