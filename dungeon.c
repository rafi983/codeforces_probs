#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node {
    int key;
    int pri;
    struct Node *l;
    struct Node *r;
} Node;

static Node pool[500000];
static int pool_idx;

static Node* new_node(int key) {
    Node* n = &pool[pool_idx++];
    n->key = key;
    n->pri = rand();
    n->l = NULL;
    n->r = NULL;
    return n;
}

static Node* rotate_left(Node* x) {
    Node* y = x->r;
    x->r = y->l;
    y->l = x;
    return y;
}

static Node* rotate_right(Node* x) {
    Node* y = x->l;
    x->l = y->r;
    y->r = x;
    return y;
}

static Node* insert(Node* root, int key) {
    if (!root)
        return new_node(key);
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

static Node* erase(Node* root, int key) {
    if (!root)
        return NULL;
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

static Node* lower_bound(Node* root, int key) {
    Node* res = NULL;
    while (root) {
        if (root->key >= key) {
            res = root;
            root = root->l;
        } else
            root = root->r;
    }
    return res;
}

typedef struct {
    int b;
    int c;
} Monster;

int cmp_pos(const void* a, const void* b) {
    const Monster* x = (const Monster*)a;
    const Monster* y = (const Monster*)b;
    if (x->b != y->b)
        return x->b - y->b;
    return y->c - x->c;
}

int cmp_zero(const void* a, const void* b) {
    const Monster* x = (const Monster*)a;
    const Monster* y = (const Monster*)b;
    return x->b - y->b;
}

int main() {
    srand(1);
    int T;
    if (scanf("%d", &T) != 1)
        return 0;

    while (T--) {
        int n, m;
        scanf("%d %d", &n, &m);
        int* a = (int*)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        int* b = (int*)malloc(m * sizeof(int));
        for (int i = 0; i < m; i++)
            scanf("%d", &b[i]);
        int* c = (int*)malloc(m * sizeof(int));
        for (int i = 0; i < m; i++)
            scanf("%d", &c[i]);

        pool_idx = 0;
        Node* root = NULL;
        for (int i = 0; i < n; i++)
            root = insert(root, a[i]);

        Monster* pos = (Monster*)malloc(m * sizeof(Monster));
        Monster* zero = (Monster*)malloc(m * sizeof(Monster));
        int pc = 0, zc = 0;

        for (int i = 0; i < m; i++) {
            if (c[i] > 0) {
                pos[pc].b = b[i];
                pos[pc].c = c[i];
                pc++;
            } else {
                zero[zc].b = b[i];
                zero[zc].c = 0;
                zc++;
            }
        }

        if (pc)
            qsort(pos, pc, sizeof(Monster), cmp_pos);
        if (zc)
            qsort(zero, zc, sizeof(Monster), cmp_zero);

        int kills = 0;
        for (int i = 0; i < pc; i++) {
            Node* nd = lower_bound(root, pos[i].b);
            if (!nd)
                continue;
            int x = nd->key;
            root = erase(root, x);
            int nw = x > pos[i].c ? x : pos[i].c;
            root = insert(root, nw);
            kills++;
        }

        for (int i = 0; i < zc; i++) {
            Node* nd = lower_bound(root, zero[i].b);
            if (!nd)
                continue;
            int x = nd->key;
            root = erase(root, x);
            kills++;
        }

        printf("%d\n", kills);

    }
    return 0;
}
