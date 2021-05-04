#include <bits/stdc++.h>

using namespace std;

int nowtime, maxtime, sum;
int ans, maxdeep;
int s[4], a[21];

void dfs(int x)
{
    if (x > maxdeep) {
        maxtime = max(maxtime, nowtime);
        return;
    }
    if (nowtime + a[x] <= sum / 2) {
        nowtime += a[x];
        dfs(x + 1);
        nowtime -= a[x];
    }
    dfs(x + 1);
}

int main()
{
    cin >> s[0] >> s[1] >> s[2] >> s[3];
    for (int i = 0; i < 4; i++) {
        nowtime = 0;
        maxdeep = s[i];
        sum = 0;
        for (int j = 1; j <= s[i]; j++) {
            cin >> a[j];
            sum += a[j];
        }
        maxtime = 0;
        dfs(1);
        ans += (sum - maxtime);
    }
    cout << ans;
    system("pause");
    return 0;
}