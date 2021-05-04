#include <bits/stdc++.h>

using namespace std;

int l[100008];

int main()
{
    int a;
    int n;
    scanf("%d\n%d", &a, &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &l[i]);
    }
    int cnt = 0;
    int i = 0, j = n - 1;
    sort(l, l + n);
    while (i <= j) {
        if (l[i] + l[j] <= a) {
            i++;
            j--;
        } else {
            j--;
        }
        cnt++;
    }
    printf("%d\n", cnt);
    //system("pause");
    return 0;
}