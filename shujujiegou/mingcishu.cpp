#include <bits/stdc++.h>

using namespace std;

struct node
{
    node *ch[2];
    int value;
    int random;
    int sum;
    node(int v = 0, int re = rand(), node *r = NULL, node *l = NULL, int s = 1) : value(v), random(re), ch{r, l}, sum(s) {}
    int cmp(int x)
    {
        if (x == value)
            return -1;
        return x < value ? 0 : 1;
    }
    void maintain()
    {
        sum = 1;
        if (ch[0] != NULL)
            sum += ch[0]->sum;
        if (ch[1] != NULL)
            sum += ch[1]->sum;
    }
};

void rotate(node *&o, int d)
{
    node *k = o->ch[d ^ 1];
    o->ch[d ^ 1] = k->ch[d];
    k->ch[d] = o;
    o->maintain();
    k->maintain();
    o = k;
}

void insert(node *&o, int x)
{
    if (o == NULL)
    {
        o = new node(x);
    }
    else
    {
        int d = x < o->value ? 0 : 1;
        insert(o->ch[d], x);
        if (o->ch[d]->random > o->random)
            rotate(o, d ^ 1);
    }
    o->maintain();
}

int kth(node *o, int k)
{
    if (o == NULL || k <= 0 || k > o->sum)
    {
        return -1;
    }
    int s = o->ch[1] == NULL ? 0 : o->ch[1]->sum;
    if (s + 1 == k)
    {
        return o->value;
    }
    if (k <= s)
    {
        return kth(o->ch[1], k);
    }
    else
    {
        kth(o->ch[0], k - s - 1);
    }
}

int find(node *o, int k)
{
    if (o == NULL)
    {
        return -1;
    }
    int d = o->cmp(k);
    if (d == -1)
    {
        return o->ch[1] == NULL ? 1 : o->ch[1]->sum + 1;
    }
    else if (d == 1)
    {
        return find(o->ch[d], k);
    }
    else
    {
        int tmp = find(o->ch[d], k);
        if (tmp == -1)
        {
            return -1;
        }
        else
        {
            return o->ch[1] == NULL ? tmp + 1 : tmp + 1 + o->ch[1]->sum;
        }
    }
}

int main()
{

    return 0;
}