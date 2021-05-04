#include <bits/stdc++.h>

using namespace std;

#define INF 1000000000

int n, c;

int noc[1000005];

bool P(int a[], int x)
{
    int k = 0;
    int location = -INF;
    for (int i = 0; i < n; i++) {
        if (a[i] - location >= x) {
            location = a[i];
            k++;
        }
    }
    return k >= c;
}

int main()
{
    scanf("%d %d", &n, &c);
    for (int i = 0; i < n; i++) {
        scanf("%d", &noc[i]);
    }
    sort(noc, noc + n);
    int l = 0, r = INF;
    int ans = 0;
    while (l <= r) {
        int mid = l + r >> 1;
        if (P(noc, mid)) {
            l = mid + 1, ans = mid;
        } else {
            r = mid - 1;
        }
    }
    printf("%d\n", ans);
    //system("pause");
    return 0;
}