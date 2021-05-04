#include <bits/stdc++.h>

using namespace std;

struct milk {
    long long int p;
    long long int q;
    //double value;
} c[5005];

bool cmp(milk A, milk B)
{
    return A.p < B.p;
}

int main()
{
    long long int a, b;
    scanf("%lld %lld", &a, &b);
    for (int i = 0; i < b; i++) {
        scanf("%lld %lld", &c[i].p, &c[i].q);
    }
    sort(c, c + b, cmp);
    long long int j = 0, sum = 0;
    while (a != 0) {
        if (a >= c[j].q) {
            a -= c[j].q;
            sum += c[j].q * c[j].p;
            j++;
            //continue;
        } else if (a < c[j].q && a != 0) {
            sum += c[j].p * a;
            a = 0;
        }
    }
    printf("%lld\n", sum);
    return 0;
}