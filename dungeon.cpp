#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
using namespace std;

struct Node {
    int key;
    int pri;
    Node* l;
    Node* r;

    Node(int k, int p) : key(k), pri(p), l(nullptr), r(nullptr) {}
};

class NodePool {
private:
    vector<Node> pool;
    int idx;

public:
    NodePool() : pool(500000, Node(0, 0)), idx(0) {}

    Node* new_node(int key, int pri) {
        pool[idx] = Node(key, pri);
        return &pool[idx++];
    }

    void reset() {
        idx = 0;
    }
};

class Treap {
private:
    NodePool& pool;
    mt19937 rng;

    Node* rotate_left(Node* x) {
        Node* y = x->r;
        x->r = y->l;
        y->l = x;
        return y;
    }

    Node* rotate_right(Node* x) {
        Node* y = x->l;
        x->l = y->r;
        y->r = x;
        return y;
    }

public:
    Treap(NodePool& p) : pool(p), rng(1) {}

    Node* insert(Node* root, int key) {
        if (!root)
            return pool.new_node(key, rng());
        if (key < root->key)
            root->l = insert(root->l, key);
        else
            root->r = insert(root->r, key);
        if (root->l && root->l->pri > root->pri)
            root = rotate_right(root);
        else if (root->r && root->r->pri > root->pri)
            root = rotate_left(root);
        return root;
    }

    Node* erase(Node* root, int key) {
        if (!root)
            return nullptr;
        if (key < root->key)
            root->l = erase(root->l, key);
        else if (key > root->key)
            root->r = erase(root->r, key);
        else {
            if (!root->l)
                return root->r;
            else if (!root->r)
                return root->l;
            else {
                if (root->l->pri > root->r->pri) {
                    root = rotate_right(root);
                    root->r = erase(root->r, key);
                } else {
                    root = rotate_left(root);
                    root->l = erase(root->l, key);
                }
            }
        }
        return root;
    }

    Node* lower_bound(Node* root, int key) {
        Node* res = nullptr;
        while (root) {
            if (root->key >= key) {
                res = root;
                root = root->l;
            } else
                root = root->r;
        }
        return res;
    }
};

struct Monster {
    int b;
    int c;

    Monster() : b(0), c(0) {}
    Monster(int b_val, int c_val) : b(b_val), c(c_val) {}
};

bool cmp_pos(const Monster& x, const Monster& y) {
    if (x.b != y.b)
        return x.b < y.b;
    return x.c > y.c;
}

bool cmp_zero(const Monster& x, const Monster& y) {
    return x.b < y.b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n, m;
        cin >> n >> m;

        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        vector<int> b(m);
        for (int i = 0; i < m; ++i) {
            cin >> b[i];
        }

        vector<int> c(m);
        for (int i = 0; i < m; ++i) {
            cin >> c[i];
        }

        NodePool pool;
        Treap treap(pool);
        Node* root = nullptr;

        for (int i = 0; i < n; ++i) {
            root = treap.insert(root, a[i]);
        }

        vector<Monster> pos;
        vector<Monster> zero;

        for (int i = 0; i < m; ++i) {
            if (c[i] > 0) {
                pos.push_back(Monster(b[i], c[i]));
            } else {
                zero.push_back(Monster(b[i], 0));
            }
        }

        if (!pos.empty()) {
            sort(pos.begin(), pos.end(), cmp_pos);
        }
        if (!zero.empty()) {
            sort(zero.begin(), zero.end(), cmp_zero);
        }

        int kills = 0;

        for (const Monster& monster : pos) {
            Node* nd = treap.lower_bound(root, monster.b);
            if (!nd)
                continue;
            int x = nd->key;
            root = treap.erase(root, x);
            int nw = max(x, monster.c);
            root = treap.insert(root, nw);
            ++kills;
        }

        for (const Monster& monster : zero) {
            Node* nd = treap.lower_bound(root, monster.b);
            if (!nd)
                continue;
            int x = nd->key;
            root = treap.erase(root, x);
            ++kills;
        }

        cout << kills << '\n';
    }

    return 0;
}

