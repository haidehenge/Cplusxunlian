#include <cstdio>
#include <iostream>

using namespace std;

#define size 5

int a[size * size], n = 4 * 4, ans = 0;

int b1[size][5], b2[size][5], b3[size][5];

void dfs(int x)
{
    if (x > n) {
        ans++;
        for (int i = 1; i <= n; i++) {
            printf("%d ", a[i]);
            if (i % 4 == 0)
                puts(" ");
        }
        puts(" ");
        return;
    }

    int row = (x - 1) / 4 + 1;
    int col = (x - 1) % 4 + 1;
    int block = (row - 1) / 2 * 2 + (col - 1) / 2 + 1;
    for (int i = 1; i <= 4; i++) {
        if (b1[row][i] == 0 && b2[col][i] == 0 && b3[block][i] == 0) {
            a[x] = i;
            b1[row][i] = 1;
            b2[col][i] = 1;
            b3[block][i] = 1;
            dfs(x + 1);
            b1[row][i] = 0;
            b2[col][i] = 0;
            b3[block][i] = 0;
        }
    }
}

int main()
{
    dfs(1);
    printf("%d", ans);
    system("pause");
    return 0;
}