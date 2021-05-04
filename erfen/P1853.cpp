#include <bits/stdc++.h>

using namespace std;

int L, N, K;

int a[100005] = { 0 };

bool P(int x)
{
    int g = 0;
    for (int i = 0; i < N - 1; i++) {
        if (a[i + 1] - a[i] > x) {
            g += ((a[i + 1] - a[i]) / x);
            if ((a[i + 1] - a[i]) % x == 0) {
                g--;
            }
        }
    }
    return g <= K;
}

int main()
{
    scanf("%d %d %d", &L, &N, &K);
    for (int i = 0; i < N; i++) {
        scanf("%d", &a[i]);
    }
    int r = L, l = 0;
    int ans = 0, mid = 0;
    while (l < r) {
        mid = (l + r) >> 1;
        bool flag = P(mid);
        if (flag) {
            ans = mid;
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    printf("%d\n", ans);
    //system("pause");
    return 0;
}