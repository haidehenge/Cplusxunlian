#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

const ll OIU = 2e7 + 5;

ll len, m, n;

ll sa[OIU] = { 0 };

bool check(ll x)
{
    ll N = 0, counte = 0;
    for (ll i = 1; i <= m; i++) {
        if (sa[i] - N < x) {
            counte++;
        } else {
            N = sa[i];
        }
    }
    if (counte > n) {
        return false;
    } else {
        return true;
    }
}

int main()
{

    ios::sync_with_stdio(false);
    cin >> len >> m >> n;
    for (ll i = 1; i <= m; i++) {
        cin >> sa[i];
    }
    sa[m + 1] = len;
    ll l = 0;
    ll r = len;
    ll ans = 0;
    while (l <= r) {
        ll mid = (l + r) / 2;
        if (check(mid)) {
            l = mid + 1;
            ans = mid;
        } else {
            r = mid - 1;
        }
    }
    cout << ans << endl;
    return 0;
}