#include <bits/stdc++.h>

using namespace std;

struct fenshu {
    int a;
    int b;
} fd[105];

int gct(int x, int y)
{
    return y ? gct(y, x % y) : x;
}

int main()
{
    int n;
    scanf("%d", &n);
    fenshu k;
    k.a = k.b = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d/%d", &fd[i].a, &fd[i].b);
        if (i == 0) {
            k.a += fd[i].a;
            k.b += fd[i].b;
        } else {
            int fil = k.b;
            int mn = fd[i].b;
            k.a = k.a * mn;
            k.b = k.b * mn;
            fd[i].a = fd[i].a * fil;
            fd[i].b = fd[i].b * fil;
            k.a += fd[i].a;
        }
    }
    if (k.a != 0) {
        int p = gct(k.a, k.b);
        k.a /= p;
        k.b /= p;
    }

    int flag = 0;

    int l = k.a / k.b;
    k.a -= (l * k.b);
    if (l != 0) {
        printf("%d", l);
        flag = 1;
    }
    if (k.a != 0) {
        if (flag == 1) {
            putchar(' ');
        }
        printf("%d/%d\n", k.a, k.b);
    }
    if (l == 0 && k.a == 0) {
        printf("%d\n", 0);
    }
    system("pause");
    return 0;
}