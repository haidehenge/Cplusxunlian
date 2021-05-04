#include <bits/stdc++.h>

using namespace std;

struct node
{
    int x;
    node *l;
    node *r;
    node(int value = 0, node *l = NULL, node *r = NULL) : x(value), l(l), r(r) {}
};

void buildtree(int y, node *&root)
{
    if (root == NULL)
    {
        root = new node(y);
    }
    else
    {
        if (root->x > y)
        {
            buildtree(y, root->l);
        }
        else
        {
            buildtree(y, root->r);
        }
    }
}

int t = 0;

void inorder(node *root)
{
    if (root != NULL)
    {
        if (t != 0)
        {
            putchar(' ');
        }
        t++;
        printf("%d", root->x);
        inorder(root->l);
        inorder(root->r);
    }
}

void remove(node *root)
{
    if (root != NULL)
    {
        remove(root->l);
        remove(root->r);
        delete root;
    }
}

int main()
{
    node *root = NULL;
    int n;
    int a;
    while (cin >> n)
    {
        while (n--)
        {
            cin >> a;
            buildtree(a, root);
        }
        inorder(root);
        cout << endl;
        remove(root);
        root = NULL;
        t = 0;
    }
    system("pause");
    return 0;
}