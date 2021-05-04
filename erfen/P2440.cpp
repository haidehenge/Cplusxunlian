#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

const ll OIU = 2e7 + 5;

ll ses[OIU] = { 0 };

ll a, b;

ll sfea(ll x)
{
    ll ans = 0;
    for (ll i = 0; i < a; i++) {
        ans += (ses[i] / x);
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    ll t = 0;
    cin >> a >> b;
    for (ll i = 0; i < a; i++) {
        cin >> ses[i];
        if (t < ses[i]) {
            t = ses[i];
        }
    }
    ll r = t;
    ll l = 1;
    while (l <= r) {
        ll mid = (l + r) / 2;
        ll t = sfea(mid);
        if (t < b) {
            r = mid - 1;
        }
        if (t >= b) {
            l = mid + 1;
        }
    }
    cout << r << endl;
    return 0;
}
