#include <bits/stdc++.h>

using namespace std;

long long int z[100005];

int main()
{
    long long int cnt = 0;
    long long int a;
    long long int b;
    long long int c;
    long long int sum = 0;
    scanf("%lld %lld", &a, &b);
    for (int i = 0; i < a; i++) {
        scanf("%lld", &c);
        if (sum + c <= b) {
            sum += c;
        } else {
            cnt++;
            sum = c;
        }
    }
    printf("%lld\n", ++cnt);
    return 0;
}