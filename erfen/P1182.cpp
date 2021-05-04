#include <bits/stdc++.h>

using namespace std;

double Sn(double n, double a)
{
    return a * (1 - pow(a, n)) / (1 - a);
}

int main()
{
    int p, a, m;
    scanf("%d %d %d", &p, &a, &m);
    double x, ans;
    double y;
    y = 1.0 * p / a;
    double r = 0, l = 5;
    while (l - r >= 0.0001) {
        ans = (l + r) / 2;
        x = 1 / (1 + ans);
        if (Sn(m, x) > y) {
            r = ans;
        } else {
            l = ans;
        }
    }
    printf("%.1lf\n", ans * 100);
    //system("pause");
    return 0;
}