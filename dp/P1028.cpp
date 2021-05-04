#include <bits/stdc++.h>

using namespace std;

int a[10010] = { 0 };

int sol(int x)
{
    int ans = 1;
    if (a[x] != 0) {
        return a[x];
    }
    int k = x / 2;
    for (int i = 1; i <= k; i++) {
        ans += sol(i);
    }
    return a[x] = ans;
}

int main()
{
    int j;
    a[1] = 1;
    scanf("%d", &j);
    sol(j);
    printf("%d\n", a[j]);
    system("pause");
    return 0;
}