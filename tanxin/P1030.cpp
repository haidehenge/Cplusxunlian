#include <bits/stdc++.h>

using namespace std;

int m[100005];

int main()
{
    int n;
    scanf("%d", &n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &m[i]);
        sum += m[i];
    }
    int ave = sum / n;
    int time = 0;
    for (int i = 0; i < n; i++) {
        m[i] -= ave;
    }
    for (int i = 0; i < n - 1; i++) {
        if (m[i] == 0) {
            continue;
        }
        m[i + 1] += m[i];
        time++;
    }
    printf("%d\n", time);
    system("pause");
    return 0;
}