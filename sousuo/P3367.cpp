#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

const ll OIU = 2e6 + 5;

ll s[OIU] = {0};

ll n, m;

void init(ll *a)
{
    for (ll i = 1; i <= m; i++)
    {
        a[i] = i;
    }
    return;
}

ll setfind(ll a)
{
    if (a != s[a])
        s[a] = setfind(s[a]);
    return s[a];
}

void union_set(ll x, ll y)
{
    x = setfind(x);
    y = setfind(y);
    if (x != y)
    {
        s[x] = s[y];
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    ll a, b, c;
    init(s);
    while (m--)
    {
        cin >> a >> b >> c;
        if (a == 2)
        {
            if (setfind(b) == setfind(c))
            {
                cout << "Y" << endl;
            }
            else
            {
                cout << "N" << endl;
            }
        }
        if (a == 1)
        {
            union_set(b, c);
        }
    }
    return 0;
}
