#include <bits/stdc++.h>

using namespace std;

int n;

void sde(char (*a)[5])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            a[i][j] = '0';
        }
    }
}

char s[5][5] = {{'1'}};

int main()
{
    /*
    freopen("title.in", "r", stdin);
    freopen("title.out", "w", stdout);
    string s;
    int ans = 0;
    while (cin >> s)
    {
        ans += s.length();
    }
    cout << ans << endl;
    */
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%c", s[i][j]);
        }
        printf("\n");
    }
    sde(s);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%c", s[i][j]);
        }
        printf("\n");
    }
    system("pause");
    return 0;
}