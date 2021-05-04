#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

const ll OIU = 2e6 + 5;

struct node
{
    int x;
    int z;
    node(int y = 0, int n = 0) : x(y), z(n)
    {
        x = y;
        z = n;
    }
};

int main()
{
    node root(0);
    printf("%d %d\n", root.x, root.z);
    system("pause");
    return 0;
}