/*
hdu 3791的源代码被我改了，添加了删除功能
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll OIU = 2e6 + 5;

int n;

char sfe[OIU];
char efs[OIU];

struct node
{
    char x;
    node *l;
    node *r;
    node(char value = '\0', node *l = NULL, node *r = NULL) : x(value), l(l), r(r) {}
};

void buildtree(char y, node *&root)
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

string t = "";
string f = "";

void preorder(node *root)
{
    if (root != NULL)
    {
        t += root->x;
        preorder(root->l);
        preorder(root->r);
    }
}

node *findmax(node *feda)
{
    while (feda->r != NULL)
        feda = feda->r;
    return feda;
}

void shanchu(node *&ro, char a)
{
    if (ro == NULL)
    {
        return;
    }
    else if ((ro->x) > a)
    {
        shanchu(ro->l, a);
    }
    else if ((ro->x) < a)
    {
        shanchu(ro->r, a);
    }
    else
    {
        if (ro->l == NULL && ro->r == NULL)
        {
            delete ro;
            ro = NULL;
        }
        else if (ro->l != NULL && ro->r == NULL)
        {
            node *temp = ro;
            ro = ro->l;
            delete temp;
        }
        else if (ro->l == NULL && ro->r != NULL)
        {
            node *temp = ro;
            ro = ro->r;
            delete temp;
        }
        else
        {
            node *temp = findmax(ro->l);
            ro->x = temp->x;
            shanchu(ro->l, temp->x);
        }
    }
    return;
}

void movetree(node *root)
{
    if (root == NULL)
    {
        return;
    }
    movetree(root->l);
    movetree(root->r);
    delete root;
}

int main()
{
    node *root = NULL;
    char a;
    int b;
    cin >> b;
    for (int i = 0; i < b; i++)
    {
        cin >> a;
        buildtree(a, root);
    }
    preorder(root);
    cout << t << endl;
    t = "";
    char c = '1';
    char d = '2';
    shanchu(root, c);
    preorder(root);
    cout << t << endl;
    system("pause");
    return 0;
}
