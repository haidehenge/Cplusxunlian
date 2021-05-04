#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a, b;
    scanf("%d:%d", &a, &b);
    if ((a >= 0 && a < 12) || (a == 12 && b == 0)) {
        printf("Only %02d:%02d.  Too early to Dang.\n", a, b);
    } else {
        int n = a % 12;
        if (b > 0) {
            n++;
        }
        for (int i = 0; i < n; i++) {
            printf("Dang");
        }
        putchar('\n');
    }
    system("pause");
    return 0;
}