#include <bits/stdc++.h>

using namespace std;

char s[10005] = { "\0" };

char ss[10005] = { "\0" };

int flag[10005] = { 0 };

int main()
{
    fgets(s, 10000, stdin);
    fgets(ss, 10000, stdin);
    int n = strlen(s);
    int m = strlen(ss);
    for (int i = 0; i < m; i++) {
        flag[ss[i]] = 1;
    }

    putchar('\n');
    system("pause");
    return 0;
}