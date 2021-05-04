#include <bits/stdc++.h>

using namespace std;

int tianti[105][15][15];

int M[105];

int p[105];

int main()
{
    int n, m;
    long long int a = 1;
    scanf("%d", &n);
    int N = n;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &M[i]);
        p[i] = M[i];
    }
    m = 0;
    if (N == 1) {
        for (int k = 1; k <= M[1]; k++) {
            for (int i = 0, j = m; i <= 9; i++) {
                tianti[1][j][i] = a;
                a += 2;
            }
            m++;
        }
        N = 0;
    }
    while (N != 0) {
        for (int k = 0; k < 10; k++) {
            for (int i = 1, j = m; i <= n; i++) {
                if (N == 1 && M[i] > 0) {
                    if (tianti[i][j - 1][9] + 1 == a) {
                        a += 1;
                    }
                    tianti[i][j][k] = a;
                    a += 2;
                    if (k == 9) {
                        M[i]--;
                        continue;
                    }
                }
                if (M[i] > 0 && N > 1) {
                    tianti[i][j][k] = a++;
                    if (k == 9) {
                        M[i]--;
                        continue;
                    }
                }
            }
        }
        int sum = 0;
        for (int v = 1; v <= n; v++) {
            if (M[v] == 0) {
                sum++;
            }
        }
        N = n - sum;
        m++;
    }
    m = 1, a = 1;
    int b = 0, c = 0;
    for (a = 1; a <= n; a++) {
        printf("#%d\n", a);
        for (int b = 0; b < p[m]; b++) {
            for (c = 0; c < 10; c++) {
                if (c != 0) {
                    printf(" ");
                }
                printf("%d", tianti[a][b][c]);
            }
            printf("\n");
        }
        m++;
    }
    system("pause");
    return 0;
}