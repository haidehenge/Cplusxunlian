#include <bits/stdc++.h>

using namespace std;

long long checker[30][30] = { 0 };

bool flag[30][30] = { 0 };

int del[9][2] = { { 0, 0 }, { 2, 1 }, { -2, 1 }, { 2, -1 }, { -2, -1 }, { 1, 2 }, { 1, -2 }, { -1, 2 }, { -1, -2 } };

int main()
{
    int a, b;
    int n, m;
    scanf("%d %d %d %d", &a, &b, &n, &m);
    for (int i = 0; i < 9; i++) {
        int tmpx = del[i][0] + n;
        int tmpy = del[i][1] + m;
        if (tmpx >= 0 && tmpx <= a && tmpy >= 0 && tmpy <= b) {
            flag[tmpx][tmpy] = 1;
        }
    }
    checker[0][0] = 1 - flag[0][0];
    for (int i = 0; i <= a; i++) {
        for (int j = 0; j <= b; j++) {
            if (flag[i][j] == 1) {
                continue;
            }
            if (i != 0) {
                checker[i][j] += checker[i - 1][j];
            }
            if (j != 0) {
                checker[i][j] += checker[i][j - 1];
            }
        }
    }
    printf("%lld\n", checker[a][b]);
    return 0;
}