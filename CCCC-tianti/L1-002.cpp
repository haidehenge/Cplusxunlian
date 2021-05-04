#include <bits/stdc++.h>

using namespace std;

int main()
{
    int sum = 0;
    char s = '\0';
    scanf("%d %c", &sum, &s);
    int n = 0, m = 0;
    while (sum >= n) {
        m++;
        n = 2 * m * m - 1;
    }
    m -= 1;
    n = 2 * m * m - 1;
    int yushu = sum - n;
    for (int i = m, v = 0; i >= 1; i--, v++) {
        int k = v;
        for (int j = 0; j < k; j++) {
            printf(" ");
        }
        int x = 1 + (i - 1) * 2;
        for (int j = 0; j < x; j++) {
            printf("%c", s);
        }
        printf("\n");
    }
    for (int i = 0, v = m - 2; i < m - 1; i++, v--) {
        for (int j = 0; j < v; j++) {
            printf(" ");
        }
        int x = 2 * (i + 1) + 1;
        for (int j = 0; j < x; j++) {
            printf("%c", s);
        }
        printf("\n");
    }
    printf("%d\n", yushu);
    system("pause");
    return 0;
}