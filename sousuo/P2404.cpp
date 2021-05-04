#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

const ll OIU = 2e6 + 5;

ll n, sum = 0;

string s = "";

void DFS(ll x, ll previous, string sf)
{
    if (x == n && sum >= 2)
    {
        cout << sf << endl;
        return;
    }
    for (ll i = previous; i <= n; i++)
    {
        x += i;
        if (sum != 0 && sf[sf.size() - 1] != '+')
        {
            sf += '+';
        }
        sum++;
        sf += char(i + '0');
        if (x <= n)
        {
            DFS(x, i, sf);
            sf.erase(sf.end() - 1, sf.end());
            x -= i;
            sum = sf.size();
        }
        else
        {
            x -= i;
            return;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    DFS(0, 1, s);
    system("pause");
    return 0;
}