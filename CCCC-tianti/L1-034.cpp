#include <bits/stdc++.h>

using namespace std;

const long long int OIU = -1;

int flag[1005] = { 0 };

int main()
{
    int a;
    int b;
    int c;
    scanf("%d", &a);
    for (int i = 0; i < a; i++) {
        scanf("%d", &b);
        for (int j = 0; j < b; j++) {
            scanf("%d", &c);
            flag[c]++;
        }
    }
    int n = 0, j = 0;
    for (int i = 1000; i >= 0; i--) {
        if (flag[i] > j) {
            j = flag[i];
            n = i;
        }
    }
    printf("%d %d\n", n, j);
    system("pause");
    return 0;
}