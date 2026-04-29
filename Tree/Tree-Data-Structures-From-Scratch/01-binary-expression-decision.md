# 01. Binary, Expression, And Decision Trees

## Binary Tree

A binary tree is any tree where each node has at most two children. It does not require ordering. That makes it useful for general hierarchy, parsing structures, ASTs, and decision modeling.

### Required Operations

| Operation | What it does | Cost |
| --- | --- | --- |
| Create node | Allocates a node with left and right pointers | O(1) |
| Insert level-order | Places the new node in the first empty child slot | O(n) |
| DFS traversals | Preorder, inorder, postorder | O(n) |
| BFS traversal | Visits level by level | O(n) |
| Search | Finds a value without ordering assumptions | O(n) |
| Height | Longest path from node to leaf | O(n) |
| Delete value | Replace target with deepest node, then remove deepest | O(n) |

### C++ From Scratch

```cpp
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node *left, *right;
    Node(int v) : val(v), left(nullptr), right(nullptr) {}
};

Node* insertLevelOrder(Node* root, int val) {
    Node* node = new Node(val);
    if (!root) return node;

    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* cur = q.front();
        q.pop();

        if (!cur->left) {
            cur->left = node;
            return root;
        }
        q.push(cur->left);

        if (!cur->right) {
            cur->right = node;
            return root;
        }
        q.push(cur->right);
    }
    return root;
}

bool search(Node* root, int target) {
    if (!root) return false;
    if (root->val == target) return true;
    return search(root->left, target) || search(root->right, target);
}

int height(Node* root) {
    if (!root) return 0;
    return 1 + max(height(root->left), height(root->right));
}

void preorder(Node* root) {
    if (!root) return;
    cout << root->val << ' ';
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << ' ';
    inorder(root->right);
}

void postorder(Node* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->val << ' ';
}

void levelOrder(Node* root) {
    if (!root) return;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* cur = q.front();
        q.pop();
        cout << cur->val << ' ';
        if (cur->left) q.push(cur->left);
        if (cur->right) q.push(cur->right);
    }
}

Node* deleteValue(Node* root, int key) {
    if (!root) return nullptr;
    if (!root->left && !root->right) {
        if (root->val == key) {
            delete root;
            return nullptr;
        }
        return root;
    }

    queue<Node*> q;
    q.push(root);
    Node* target = nullptr;
    Node* cur = nullptr;
    Node* parentOfDeepest = nullptr;

    while (!q.empty()) {
        cur = q.front();
        q.pop();
        if (cur->val == key) target = cur;

        if (cur->left) {
            parentOfDeepest = cur;
            q.push(cur->left);
        }
        if (cur->right) {
            parentOfDeepest = cur;
            q.push(cur->right);
        }
    }

    if (!target) return root;

    target->val = cur->val;
    if (parentOfDeepest->right == cur) parentOfDeepest->right = nullptr;
    else parentOfDeepest->left = nullptr;
    delete cur;
    return root;
}
```

### Dry Run

Insert `10, 20, 30, 40, 50` using level-order insertion.

| Step | Action | Tree shape |
| --- | --- | --- |
| 1 | Insert 10 | `10` is root |
| 2 | Insert 20 | `20` becomes left child of `10` |
| 3 | Insert 30 | `30` becomes right child of `10` |
| 4 | Insert 40 | first empty slot is left child of `20` |
| 5 | Insert 50 | next empty slot is right child of `20` |

Final tree:

```text
        10
       /  \
     20    30
    /  \
  40    50
```

Traversals:

| Traversal | Output | Meaning |
| --- | --- | --- |
| Preorder | `10 20 40 50 30` | Process node before children |
| Inorder | `40 20 50 10 30` | Left, node, right |
| Postorder | `40 50 20 30 10` | Process children before node |
| Level-order | `10 20 30 40 50` | Process breadth first |

### Go Real-Life Example: Company Hierarchy

```go
package main

import "fmt"

type Employee struct {
    Name   string
    Left   *Employee
    Right  *Employee
}

func PrintOrg(root *Employee) {
    if root == nil {
        return
    }
    fmt.Println(root.Name)
    PrintOrg(root.Left)
    PrintOrg(root.Right)
}

func main() {
    ceo := &Employee{Name: "CEO"}
    ceo.Left = &Employee{Name: "Engineering VP"}
    ceo.Right = &Employee{Name: "Sales VP"}
    ceo.Left.Left = &Employee{Name: "Backend Lead"}
    ceo.Left.Right = &Employee{Name: "Frontend Lead"}

    PrintOrg(ceo)
}
```

## Expression Tree

An expression tree stores operators as internal nodes and operands as leaves. Compilers, interpreters, calculators, SQL planners, and rule engines use this idea.

### Required Operations

| Operation | What it does | Cost |
| --- | --- | --- |
| Build from postfix | Uses a stack to connect operands and operators | O(n) |
| Evaluate | Recursively computes left and right subtrees | O(n) |
| Infix print | Prints human-readable expression | O(n) |
| Prefix/postfix print | Emits compiler-friendly traversal order | O(n) |
| Replace subtree | Optimizes or rewrites an expression | O(size of subtree) |

### C++ From Scratch

```cpp
#include <bits/stdc++.h>
using namespace std;

struct ExprNode {
    string token;
    ExprNode *left, *right;
    ExprNode(string t) : token(t), left(nullptr), right(nullptr) {}
};

bool isOperator(const string& s) {
    return s == "+" || s == "-" || s == "*" || s == "/";
}

ExprNode* buildFromPostfix(const vector<string>& tokens) {
    stack<ExprNode*> st;
    for (const string& tok : tokens) {
        ExprNode* node = new ExprNode(tok);
        if (isOperator(tok)) {
            node->right = st.top(); st.pop();
            node->left = st.top(); st.pop();
        }
        st.push(node);
    }
    return st.empty() ? nullptr : st.top();
}

int eval(ExprNode* root) {
    if (!root) return 0;
    if (!isOperator(root->token)) return stoi(root->token);

    int a = eval(root->left);
    int b = eval(root->right);
    if (root->token == "+") return a + b;
    if (root->token == "-") return a - b;
    if (root->token == "*") return a * b;
    return a / b;
}

void printInfix(ExprNode* root) {
    if (!root) return;
    if (isOperator(root->token)) cout << '(';
    printInfix(root->left);
    cout << root->token;
    printInfix(root->right);
    if (isOperator(root->token)) cout << ')';
}
```

### Dry Run

Postfix input: `3 4 + 2 *`

| Token | Stack after processing |
| --- | --- |
| `3` | `3` |
| `4` | `3, 4` |
| `+` | `(3 + 4)` |
| `2` | `(3 + 4), 2` |
| `*` | `((3 + 4) * 2)` |

Evaluation returns `14`.

### Go Real-Life Example: Pricing Formula Evaluation

```go
package main

import "fmt"

type Expr struct {
    Token string
    Left  *Expr
    Right *Expr
}

func Eval(n *Expr) int {
    if n.Left == nil && n.Right == nil {
        if n.Token == "price" {
            return 100
        }
        if n.Token == "discount" {
            return 15
        }
        return 0
    }
    a, b := Eval(n.Left), Eval(n.Right)
    switch n.Token {
    case "-":
        return a - b
    case "+":
        return a + b
    default:
        return 0
    }
}

func main() {
    formula := &Expr{
        Token: "-",
        Left:  &Expr{Token: "price"},
        Right: &Expr{Token: "discount"},
    }
    fmt.Println("checkout total:", Eval(formula))
}
```

## Decision Tree

A decision tree routes input through yes/no or threshold checks until it reaches a leaf answer. In machine learning the tree is trained from data. In rule engines it is often written manually.

### Required Operations

| Operation | What it does | Cost |
| --- | --- | --- |
| Create split node | Stores feature and threshold | O(1) |
| Create leaf | Stores final class/decision | O(1) |
| Classify | Walks one branch per level | O(depth) |
| Train/build | Chooses best split from data | Depends on algorithm |
| Prune | Removes branches that overfit | Depends on tree size |

### C++ From Scratch

```cpp
#include <bits/stdc++.h>
using namespace std;

struct DecisionNode {
    string feature;
    double threshold;
    string label;
    DecisionNode *left, *right;

    DecisionNode(string answer)
        : feature(""), threshold(0), label(answer), left(nullptr), right(nullptr) {}

    DecisionNode(string f, double t, DecisionNode* l, DecisionNode* r)
        : feature(f), threshold(t), label(""), left(l), right(r) {}

    bool isLeaf() const { return !label.empty(); }
};

string classify(DecisionNode* root, const unordered_map<string, double>& row) {
    DecisionNode* cur = root;
    while (cur && !cur->isLeaf()) {
        double value = row.at(cur->feature);
        if (value <= cur->threshold) cur = cur->left;
        else cur = cur->right;
    }
    return cur ? cur->label : "unknown";
}
```

### Dry Run

Rule tree:

```text
income <= 50000?
yes -> risk = high
no  -> debt <= 10000?
       yes -> risk = low
       no  -> risk = medium
```

Input row: `income = 70000, debt = 12000`

| Step | Check | Direction |
| --- | --- | --- |
| 1 | `70000 <= 50000` | false, go right |
| 2 | `12000 <= 10000` | false, go right |
| 3 | Leaf | `medium` |

### Go Real-Life Example: Fraud Rule Classifier

```go
package main

import "fmt"

type Txn struct {
    Amount       float64
    FailedLogins float64
}

type Rule struct {
    Feature   string
    Threshold float64
    Label     string
    Left      *Rule
    Right     *Rule
}

func (r *Rule) IsLeaf() bool { return r.Label != "" }

func Classify(r *Rule, t Txn) string {
    for !r.IsLeaf() {
        var value float64
        if r.Feature == "amount" {
            value = t.Amount
        } else {
            value = t.FailedLogins
        }

        if value <= r.Threshold {
            r = r.Left
        } else {
            r = r.Right
        }
    }
    return r.Label
}

func main() {
    tree := &Rule{
        Feature:   "amount",
        Threshold: 1000,
        Left:      &Rule{Label: "allow"},
        Right: &Rule{
            Feature:   "failed_logins",
            Threshold: 3,
            Left:      &Rule{Label: "review"},
            Right:     &Rule{Label: "block"},
        },
    }

    fmt.Println(Classify(tree, Txn{Amount: 2500, FailedLogins: 4}))
}
```
