#include <bits/stdc++.h>

using namespace std;

char mid1[100005] = {'\0'};
char first1[100005] = {'\0'};
char post1[100005] = {'\0'};

int k;

struct node
{
    char value;
    node *l, *r;
    node(char value, node *l = NULL, node *r = NULL) : value(value), l(l), r(r) {}
};

void buildtree(int l, int r, int &t, node *&root)
{
    int flag = -1;
    for (int i = 0; i <= r; i++)
    {
        if (mid1[i] == first1[t])
        {
            flag = i;
            break;
        }
    }
    if (flag == -1)
        return;
    root = new node(mid1[flag]);
    t++;
    //cout << t << endl;
    if (flag > l)
        buildtree(l, flag - 1, t, root->l);
    if (flag < r)
        buildtree(flag + 1, r, t, root->r);
}

void postorder(node *root)
{
    if (root != NULL)
    {
        postorder(root->l);
        postorder(root->r);
        post1[k++] = root->value;
    }
}

void remove(node *root)
{
    if (root == NULL)
        return;
    remove(root->l);
    remove(root->r);
    delete root;
}

int main()
{
    cin >> mid1 >> first1;
    node *root;
    int t = 0;
    buildtree(0, strlen(mid1) - 1, t, root);
    k = 0;
    postorder(root);
    cout << post1 << endl;
    remove(root);
    //system("pause");
    return 0;
}