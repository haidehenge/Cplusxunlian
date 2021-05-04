#include <bits/stdc++.h>

using namespace std;

struct node
{
    char value;
    node *l;
    node *r;
    node(char x = '\0', node *l = NULL, node *r = NULL) : value(x), l(l), r(r) {}
};

bool flag = false;

void buildtree(node *&root, char *a)
{
    if (flag == false)
    {
        root = new node(a[0]);
        root->l = new node(a[1]);
        root->r = new node(a[2]);
        flag = true;
        return;
    }
    if (root != NULL)
    {
        if (root->value == a[0])
        {
            root->l = new node(a[1]);
            root->r = new node(a[2]);
        }
        else
        {
            buildtree(root->l, a);
            buildtree(root->r, a);
        }
    }
    return;
}

void preorder(node *ora)
{
    if (ora != NULL && ora->value != '*')
    {
        printf("%c", ora->value);
        preorder(ora->l);
        preorder(ora->r);
    }
}

int main()
{
    char s[8];
    int n;
    cin >> n;
    node *root = NULL;
    while (n--)
    {
        scanf(" %s", s);
        buildtree(root, s);
    }
    preorder(root);
    cout << endl;
    //system("pause");
    return 0;
}