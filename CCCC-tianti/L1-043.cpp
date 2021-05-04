#include <bits/stdc++.h>

using namespace std;

int flag[10005] = { -1 };

int sda(int w, int h)
{
    return w * 60 + h;
}

int main()
{
    int n;
    int d;
    int w;
    int h;
    scanf("%d\n", &n);
    char c;
    double sum = 0;
    int m = 0;
    for (int i = 0; i < n; i++) {
        memset(flag, -1, sizeof(flag));
        while (true) {
            scanf("%d %c %d:%d", &d, &c, &w, &h);
            if (d == 0) {
                break;
            }
            if (c == 'S') {
                flag[d] = sda(w, h);
            }
            if (c == 'E') {
                if (flag[d] != -1) {
                    sum += sda(w, h) - flag[d];
                    m++;
                    flag[d] = -1;
                }
            }
        }
        if (m == 0) {
            printf("0 0\n");
        } else {
            sum /= m;
            int t = sum + 0.5f;
            printf("%d %d\n", m, t);
        }
        m = 0;
        sum = 0;
    }
    //system("pause");
    return 0;
}