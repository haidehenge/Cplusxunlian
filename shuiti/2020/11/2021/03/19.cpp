#include <bits/stdc++.h>

using namespace std;

char mid1[100005] = { '\0' };
char first1[100005] = { '\0' };

struct node {
    char value;
    node *l, *r;
    node(char value, node* l = NULL, node* r = NULL)
        : value(value)
        , l(l)
        , r(r)
    {
    }
};

void buildtree(int l, int r, int& t, node*& root)
{
    int flag = -1;
    for (int i = 0; i <= r; i++) {
        if (mid1[i] == first1[t]) {
            flag = i;
            break;
        }
    }
    if (flag == -1)
        return;
    root = new node(mid1[flag]);
    t++;
    if (flag > l)
        buildtree(l, flag - 1, t, root->l);
    if (flag < r)
        buildtree(flag + 1, r, t, root->r);
}

void bfs(node* root)
{
    queue<node*> q;
    int flag = 0;
    q.push(root);
    while (!q.empty()) {
        node* start = q.front();
        q.pop();
        if (flag != 0) {
            printf(" ");
        }
        printf("%c", start->value);
        flag++;
        if (start->r != NULL) {
            q.push(start->r);
        }
        if (start->l != NULL) {
            q.push(start->l);
        }
    }
}

void remove(node* root)
{
    if (root == NULL)
        return;
    remove(root->l);
    remove(root->r);
    delete root;
}

int main()
{
    int a;
    cin >> a;
    for (int i = 0; i < a; i++) {
        scanf(" %c", &mid1[i]);
    }
    for (int j = 0; j < a; j++) {
        scanf(" %c", &first1[j]);
    }
    node* root;
    int t = 0;
    buildtree(0, a - 1, t, root);
    bfs(root);
    remove(root);
    system("pause");
    return 0;
}