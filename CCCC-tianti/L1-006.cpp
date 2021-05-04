#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long int s;
    scanf("%lld", &s);
    long long int x = (long long int)sqrt(s);
    bool flag = 0;
    bool loc = 0;
    for (long long int i = 12; i >= 1; i--) {
        for (long long int j = 2; j <= x; j++) {
            long long int sum = 1;
            loc = 0;
            for (long long int k = j; k - j + 1 <= i; k++) {
                if (s % k == 0) {
                    sum *= k;
                } else {
                    loc = 1;
                    break;
                }
            }
            if (s % sum == 0 && loc == 0) {
                printf("%lld\n%lld", i, j);
                for (long long int v = j + 1; v - j + 1 <= i; v++) {
                    printf("*%lld", v);
                }
                flag = 1;
                break;
            }
        }
        if (flag == 1) {
            break;
        }
    }
    if (flag == 0) {
        printf("1\n%lld", s);
    }
    system("pause");
    return 0;
}