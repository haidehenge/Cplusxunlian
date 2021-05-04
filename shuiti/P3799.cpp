#include <bits/stdc++.h>

using namespace std;

const long long int mod = 1e9 + 7;

int flag[10000005];

int sf[5005];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &flag[i]);
        sf[flag[i]]++;
    }
    int sum = 0;
    for (int i = 1; i <= 5005; i++) {
        for (int j = 1; j < ((i / 2) + 1); j++) {
            if (sf[i] >= 2) {
                if (i - j == j) {
                    sum += (sf[i] * (sf[i] - 1) / 2) % mod * (sf[j] * (sf[j] - 1) / 2) % mod;
                } else {
                    sum += (sf[i] * (sf[i] - 1) / 2) % mod * sf[j] % mod * sf[i - j] % mod;
                }
            }
        }
        sum = sum % mod;
    }
    printf("%d\n", sum % mod);
    return 0;
}